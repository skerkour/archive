table! {
    accounts (id) {
        id -> Uuid,
        balance -> Int8,
        version -> Int8,
    }
}

table! {
    accounts_events (id) {
        id -> Uuid,
        aggregate_id -> Uuid,
        data -> Jsonb,
    }
}

allow_tables_to_appear_in_same_query!(
    accounts,
    accounts_events,
);
