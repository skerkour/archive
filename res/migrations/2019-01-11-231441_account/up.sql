CREATE TABLE accounts (
  id UUID NOT NULL PRIMARY KEY,
  balance BIGINT NOT NULL,
  version BIGINT NOT NULL
);

CREATE TABLE accounts_events (
  id UUID NOT NULL PRIMARY KEY,
  aggregate_id UUID NOT NULL,
  data JSONB NOT NULL
);
