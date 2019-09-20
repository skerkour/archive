// #[macro_use]
// extern crate diesel;
// #[macro_use]
// extern crate serde_derive;

// pub mod uuid;

// use serde_json;
// use serde::{Serialize, Deserialize};
// use crate::uuid::Uuid;
// use std::collections::HashMap;
// use dotenv::dotenv;
// use diesel::prelude::*;
// use diesel::pg::PgConnection;
// use std::env;
// use diesel::result::Error;


// // // pub struct Event<T> {
// // pub struct Event {
// //     id: Uuid,
// //     aggregate_id: Uuid,
// //     // data: Box<Event<Aggregate = T>>,
// // }

// // impl Event<T> {
// //     fn apply(&self, aggregate: T) {
// //         let _ =
// //     }
// // }

// pub struct Event {
//     id: Uuid,
//     data: serde_json::Value,
//     aggregate_id: Uuid,
// }

// pub trait EventData: Serialize {
//     type Aggregate;
//     type Command;

//     fn apply(&self, aggregate: &mut Self::Aggregate, event: &Event);
//     fn version() -> u64;
// }

// // pub trait Event {
// //     fn aggregate_type(&self) -> String;
// //     fn action(&self) -> String;
// //     fn version(&self) -> u64;
// //     fn apply(&self, aggregate: Aggregate, event: Event);
// // }

// pub trait Aggregate {
//     // type Event: Event;
//     type Commands: Command;
//     fn id(&self) -> uuid::Uuid;

//     // fn handle_command(state: &Self::State, cmd: Self::Command) -> Result<Vec<Self::Event>>;
// }

// pub trait Command {
//     type Event: EventData;
//     type Aggregate;

//     fn build_event(&self) -> Result<Box<Self::Event>, String>;
//     fn validate(&self, aggregate: &Self::Aggregate) -> Result<(), String>;
// }


// pub fn execute<C: Command, T, A: Aggregate + Insertable<T>>(command: &C, aggregate: &mut Aggregate<Commands = C>) {
//     let event_data = command.build_event().unwrap();
//     let ev = Event{id: Uuid(::uuid::Uuid::new_v4()), aggregate_id: Uuid(::uuid::Uuid::new_v4()), data: serde_json::Value::default() };// (*aggregate).id() };
//     event_data.apply(aggregate, &ev);

//     let connection = establish_connection();
//     let res = connection.transaction::<_, Error, _>(|| {
//         diesel::sql_query("INSERT INTO accounts (id, balance) VALUES ($1, $2)")
//             .bind::<diesel::sql_types::Uuid, _>(ev.id)
//             .bind::<diesel::sql_types::Int8, _>(84)
//             .execute(&connection)?;

//         Ok(())
//     });
//     if let Err(err) = res {
//         println!("{:?}", err);
//     }
// }


// fn establish_connection() -> PgConnection {
//     dotenv().ok();

//     let database_url: String = env::var("DATABASE_URL")
//         .expect("DATABASE_URL must be set");
//     PgConnection::establish(&database_url)
//         .expect(&format!("Error connecting to {}", database_url))
// }
//! # Event Sourcing
//!
//! An eventsourcing library for Rust
//!
//! One of the benefits of [event sourcing](https://martinfowler.com/eaaDev/EventSourcing.html)
//! is that in most cases, embracing this pattern does not require that much code.
//! However, there's still a bit of boilerplate required as well as the discipline for ensuring
//! the events, commands, and aggregates all perform their roles without sharing concerns.
//!
//! The fundamental workflow to remember is that **commands** are applied to **aggregates**,
//! which then emit one or more events. An **aggregate**'s business logic is also responsible
//! for returning a new state from a previous state combined with a new event. Put
//! mathematically, this looks like:
//!
//! ```terminal,ignore
//! f(state1, event) = state2
//! ```
//!
//! There are some event sourcing libraries that allow for, or even encourage, mutation of
//! state in memory. I prefer a more functional approach, and the design of this library
//! reflects that. It encourages you to write unit tests for your aggregate business logic that
//! are predictable and can be executed in isolation without concern for how you receive events
//! or how you persist them in a store.
//!
//! To start, you create an undecorated enum for your **Command** type:
//! ```rust
//! enum LocationCommand {
//!    UpdateLocation { lat: f32, long: f32, alt: f32 },
//!}
//! ```
//!
//! Next, you create an enum for your events and use a derive macro to write some boilerplate
//! on your behalf. Note how the command variants are _imperative_ statements while the
//! event variants are _verbs phrases in the past tense_. While this is by convention and
//! not enforced via code, this is a good practice to adopt.
//! ```rust
//!# #![feature(attr_literals)]
//!
//!# extern crate serde;
//!# #[macro_use] extern crate serde_derive;
//!# extern crate eventsourcing;
//!# extern crate serde_json;
//!# #[macro_use] extern crate eventsourcing_derive;
//!#[derive(Serialize, Deserialize, Debug, Clone, Event)]
//!#[event_type_version("1.0")]
//!#[event_source("events://github.com/pholactery/eventsourcing/samples/location")]
//!enum LocationEvent {
//!    LocationUpdated { lat: f32, long: f32, alt: f32 },
//!}
//! ```
//!
//! We then define a type that represents the state to be used by an aggregate.
//! With that in place, we write all of our business logic, the core of our event sourcing system,
//! in the aggregate.
//!```rust
//!# #![feature(attr_literals)]
//!# extern crate serde;
//!# #[macro_use] extern crate serde_derive;
//!# extern crate eventsourcing;
//!# extern crate serde_json;
//!# #[macro_use] extern crate eventsourcing_derive;
//!# use eventsourcing::{prelude::*, Result};
//!# #[derive(Serialize, Deserialize, Debug, Clone, Event)]
//!# #[event_type_version("1.0")]
//!# #[event_source("events://github.com/pholactery/eventsourcing/samples/location")]
//!# enum LocationEvent {
//!#     LocationUpdated { lat: f32, long: f32, alt: f32 },
//!# }
//!# enum LocationCommand {
//!#    UpdateLocation { lat: f32, long: f32, alt: f32 },
//!# }
//!#[derive(Debug)]
//!struct LocationData {
//!    lat: f32,
//!    long: f32,
//!    alt: f32,
//!    generation: u64,
//!}
//!
//!impl AggregateState for LocationData {
//!    fn generation(&self) -> u64 {
//!        self.generation
//!    }
//!}
//!struct Location;
//!impl Aggregate for Location {
//!   type Event = LocationEvent;
//!   type Command = LocationCommand;
//!   type State = LocationData;
//!
//!   fn apply_event(state: &Self::State, evt: Self::Event) -> Result<Self::State> {
//!       // TODO: validate event
//!       let ld = match evt {
//!           LocationEvent::LocationUpdated { lat, long, alt } => LocationData {
//!               lat,
//!               long,
//!               alt,
//!               generation: state.generation + 1,
//!           },
//!       };
//!       Ok(ld)
//!   }
//!
//!   fn handle_command(_state: &Self::State, cmd: Self::Command) -> Result<Vec<Self::Event>> {
//!       // TODO: add code to validate state and command
//!
//!       // if validation passes...
//!       Ok(vec![LocationEvent::LocationUpdated { lat: 10.0, long: 10.0, alt: 10.0 }])
//!   }
//!}
//! ```

pub mod uuid;

#[macro_use]
extern crate diesel;
#[macro_use]
extern crate serde_derive;
#[macro_use]
extern crate lazy_static;

extern crate chrono;
extern crate serde;
extern crate serde_json;
use crate::uuid::Uuid;
use diesel::PgConnection;


use std::sync::Mutex;

use serde::Serialize;
use std::fmt;
use diesel::pg::Pg;
use diesel::sql_types::Jsonb;
use diesel::*;
use diesel::query_builder::*;

lazy_static! {
    static ref EVENT_BUS: Mutex<Vec<u8>> = Mutex::new(vec![]);
}


/// An event sourcing error
#[derive(Debug)]
pub struct Error {
    kind: Kind,
}

impl Error {
    pub fn new(kind: Kind) -> Error {
        return Error{kind}
    }
}

impl std::error::Error for Error {
    fn description(&self) -> &str {
        "An eventsourcing error ocurred"
    }

    fn cause(&self) -> Option<&std::error::Error> {
        None
    }
}

impl fmt::Display for Error {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        match self.kind {
            Kind::ApplicationFailure(ref s) => fmt::Display::fmt(s, f),
            Kind::CommandFailure(ref s) => fmt::Display::fmt(s, f),
            Kind::StoreFailure(ref s) => fmt::Display::fmt(s, f),
        }
    }
}

/// Indicates the kind of event sourcing error that occurred.
#[derive(Debug)]
pub enum Kind {
    ApplicationFailure(String),
    CommandFailure(String),
    StoreFailure(String),
}

/// A Result where failure is an event sourcing error
pub type Result<T> = std::result::Result<T, Error>;

pub trait EventData: Serialize {
    type Aggregate: Aggregate;

    fn apply(&self, state: &Self::Aggregate) -> Self::Aggregate;
    // fn event_type_version(&self) -> &str;
    // fn event_type(&self) -> &str;
    // fn event_source(&self) -> &str;
}

#[derive(Debug, Serialize, Deserialize)]
pub struct Event<A>
    where A: EventData + diesel::serialize::ToSql<Jsonb, Pg> + diesel::deserialize::FromSql<Jsonb, Pg> {
    id: uuid::Uuid,
    aggregate_id: uuid::Uuid,
    data: A,
}

pub trait Aggregate {
    // type Event: Event;
    // type Command: Command;
    // type State;

    fn increment_version(&mut self);
    fn id(&self) -> ::uuid::Uuid;
}

pub fn execute<A, C, E, AT>(conn: &PgConnection, table: AT, aggregate: &A, cmd: C)
    -> Result<(A, Event<E>)>
    where A: Aggregate + diesel::Insertable<AT> + diesel::Queryable<AT, Pg>,
    C: Command<Aggregate = A, Event = E>,
    E: EventData<Aggregate = A> + diesel::serialize::ToSql<Jsonb, Pg> + diesel::deserialize::FromSql<Jsonb, Pg>,
    AT: diesel::Table {
    cmd.validate(aggregate)?;
    let event_data = cmd.build_event();
    let mut new_state = event_data.apply(aggregate);
    new_state.increment_version();

    // build base event
    let event = Event::<E>{
        id: uuid::Uuid(::uuid::Uuid::new_v4()),
        aggregate_id: uuid::Uuid(aggregate.id()),
        data: event_data,
    };

    let serialized = serde_json::to_string(&event).unwrap();
    println!("serialized = {}", serialized);

    // TODO: persist state and event

    diesel::insert_into(table).values(*aggregate).execute(conn);
    // TODO: dispatch event
    Ok((new_state, event))
}

pub trait Command {
    type Aggregate: Aggregate;
    type Event: EventData;

    fn validate(&self, aggregate: &Self::Aggregate) -> Result<()>;
    fn build_event(&self) -> Self::Event;
}
