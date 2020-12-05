####################################################################################################
## Builder image
####################################################################################################
FROM rust:latest AS builder

# Download the target for static linking.
RUN rustup target add x86_64-unknown-linux-musl
RUN apt update && apt install -y musl-tools

# create user
ENV USER=skerkour
ENV UID=10001
# See https://stackoverflow.com/a/55757473/12429735RUN
RUN adduser \
    --disabled-password \
    --gecos "" \
    --home "/nonexistent" \
    --shell "/sbin/nologin" \
    --no-create-home \
    --uid "${UID}" \
    "${USER}"


WORKDIR /skerkour
COPY ./ .
# RUN make build_static
RUN make build
# RUN cargo install --target x86_64-unknown-linux-musl --path .

####################################################################################################
## Final image
####################################################################################################

# see https://andygrove.io/2020/05/why-musl-extremely-slow/ for why we use debian instead of a
# scratch + musl build
FROM debian:buster-slim

# COPY --from=builder /etc/ssl/certs/ca-certificates.crt /etc/ssl/certs/
COPY --from=builder /etc/passwd /etc/passwd
COPY --from=builder /etc/group /etc/group

WORKDIR /skerkour
USER skerkour:skerkour

COPY --from=builder /skerkour/target/release/simpleserver .

EXPOSE 8080
CMD ["/skerkour/simpleserver"]


# FROM scratch

# # COPY --from=builder /etc/ssl/certs/ca-certificates.crt /etc/ssl/certs/
# COPY --from=builder /etc/passwd /etc/passwd
# COPY --from=builder /etc/group /etc/group


# WORKDIR /skerkour
# USER skerkour:skerkour

# COPY --from=builder /skerkour/target/release/simpleserver .

# EXPOSE 8080
# CMD ["/skerkour/simpleserver"]
