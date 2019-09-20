// #[macro_use]
// extern crate diesel;
// #[macro_use]
// extern crate serde_derive;

// mod schema;

// use bloom42_res;
// use std::boxed::Box;
// use bloom42_diesel_as_jsonb::AsJsonb;
// use bloom42_res::uuid::Uuid;
// use crate::schema::{accounts, accounts_events};
// use diesel::prelude::*;
// use std::env;
// use dotenv::dotenv;


// #[derive(Debug, Identifiable, Queryable, Insertable)]
// #[table_name="accounts"]
// pub struct Account {
//     id: Uuid,
//     balance: i64,
// }
// impl bloom42_res::Aggregate for Account {
//     fn id(&self) -> Uuid {
//         return self.id.clone()
//     }
// }

// pub struct FundsWithdrawn {
//     amount: i64,
// }

// impl bloom42_res::EventData for FundsWithdrawn {
//     type Aggregate = Account;

//     fn apply(&self, aggregate: &mut Self::Aggregate, event: &bloom42_res::Event) {
//         aggregate.balance -= self.amount;
//     }
// }

// pub struct FundsDeposited {
//     amount: i64,
// }

// pub struct WithdrawFunds {
//     amount: i64,
// }

// impl bloom42_res::Command for WithdrawFunds {
//     type EventData = FundsWithdrawn;
//     type Aggregate = Account;

//     fn build_event(&self) -> Result<Box<Self::EventData>, String> {
//         let event = FundsWithdrawn{amount: self.amount};

//         Ok(Box::new(event))
//     }

//     fn validate(&self, aggregate: &Self::Aggregate) -> Result<(), String> {
//         if aggregate.balance - self.amount < 0 {
//             Ok(())
//         } else {
//             Err(String::from("withdrawn amout is not valid"))
//         }
//     }
// }

// pub trait HavingTable {
//     fn table() -> Table;
// }

// fn establish_connection() -> PgConnection {
//     dotenv().ok();

//     let database_url: String = env::var("DATABASE_URL")
//         .expect("DATABASE_URL must be set");
//     PgConnection::establish(&database_url)
//         .expect(&format!("Error connecting to {}", database_url))
// }


// fn inser_gen<T: Table, I>(conn: &PgConnection, aggregate: I)
// where I: HavingTable + diesel::Insertable<T> {
//     diesel::insert_into(aggregate.table())
//         .values(aggregate)
//         .execute(conn);
// }

// fn main() {
//     let cmd = WithdrawFunds{amount: 42};
//     let mut account = Account{id: Uuid(::uuid::Uuid::new_v4()), balance: 84};
//     bloom42_res::execute::<WithdrawFunds, crate::schema::accounts::Schema, Account>(&cmd, &mut account);
//     println!("{:?}", account);
// }
#[macro_use]
extern crate diesel;
#[macro_use]
extern crate serde_derive;

mod schema;

extern crate serde;

extern crate serde_json;

use bloom42_res::*;
use bloom42_diesel_as_jsonb::AsJsonb;
use dotenv::dotenv;
use std::env;
use diesel::prelude::*;
use ::uuid;

use crate::schema::accounts;



// #[derive(Serialize, Deserialize, Debug, Clone)]
// #[event_type_version("1.0")]
// #[event_source("events://github.com/pholactery/eventsourcing/samples/bank")]
// enum BankEvent {
//     FundsWithdrawn(String, i64),
//     FundsDeposited(String, i64),
// }
#[derive(Serialize, Deserialize, Debug, Clone, AsJsonb)]
pub struct FundsWithdrawn {
    account: String,
    amount: i64,
}

#[derive(Serialize, Deserialize, Debug, Clone, AsJsonb)]
pub struct FundsDeposited {
    account: String,
    amount: i64,
}

impl bloom42_res::EventData for FundsWithdrawn {
    type Aggregate = Account;

    fn apply(&self, state: &Self::Aggregate) -> Account {
         Account {
            id: state.id.clone(),
            balance: state.balance - self.amount,
            // acctnum: state.acctnum.to_owned(),
            version: state.version,
        }
    }
}

// enum BankCommand {
//     WithdrawFunds(WithdrawFunds),
//     DepositFunds(DepositFunds),
// }

struct WithdrawFunds {
    account: String,
    amount: i64,
}

struct DepositFunds {
    account: String,
    amount: i64,
}

impl bloom42_res::Command for WithdrawFunds {
    type Aggregate = Account;
    type Event = FundsWithdrawn;

    fn validate(&self, aggregate: &Account) -> Result<()> {
        match aggregate.balance.checked_sub(self.amount) {
            Some(_) => Ok(()),
            None => Err(bloom42_res::Error::new(Kind::CommandFailure(String::from("amount is invalid")))),
        }
    }

    fn build_event(&self) -> FundsWithdrawn {
        FundsWithdrawn{
            account: self.account.clone(),
            amount: self.amount,
        }
    }
}


#[derive(Debug, Clone, Insertable, Queryable)]
#[table_name="accounts"]
pub struct Account {
    id: bloom42_res::uuid::Uuid,
    balance: i64,
    version: i64,
}

impl Aggregate for Account {
    // type Event = BankEvent;
    // type State = Account;
    // type Command = BankCommand;

    fn increment_version(&mut self) {
        self.version += 1;
    }

    fn id(&self) -> uuid::Uuid {
        self.id.0
    }

    // fn execute(state: &Self::State, cmd: Self::Command) -> Result<(Self::State, Self::Event)> {
    //     cmd.validate(state)?;
    //     let event = cmd.build_event();
    //     let mut new_state = event.apply(state);
    //     new_state.version += 1;
    //     Ok((new_state, event))
    // }
}

pub fn establish_connection() -> PgConnection {
    dotenv().ok();

    let database_url = env::var("DATABASE_URL")
        .expect("DATABASE_URL must be set");
    PgConnection::establish(&database_url)
        .expect(&format!("Error connecting to {}", database_url))
}

fn main() {
    // let account_store = MemoryEventStore::new();
    let conn = establish_connection();

    let withdraw = WithdrawFunds{
        account: "SAVINGS100".to_string(),
        amount: 500,
    };

    let initial_state = Account {
        id: bloom42_res::uuid::Uuid(uuid::Uuid::new_v4()),
        balance: 800,
        // acctnum: "SAVINGS100".to_string(),
        version: 1,
    };

    let (post_withdraw, event) = bloom42_res::execute(&conn, accounts::table, &initial_state, withdraw).unwrap();

    // use crate::schema::accounts_events::dsl::*;
    // diesel::insert_into(accounts_events).values(&event).execute(&conn);

    println!("initial: {:#?}", initial_state);
    println!("post: {:#?}", post_withdraw);
    println!("event: {:#?}", event);
}
