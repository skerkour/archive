####################################################################################################
## Build cli
####################################################################################################
# see https://medium.com/@chemidy/create-the-smallest-and-secured-golang-docker-image-based-on-scratch-4752223b7324
FROM golang:1.14-alpine AS builder_go

# Install git + SSL ca certificates.
# Git is required for fetching the dependencies.
# Ca-certificates is required to call HTTPS endpoints.
RUN apk update && apk add --no-cache git ca-certificates make gcc libc-dev alsa-lib-dev
RUN update-ca-certificates

# Create appuser
ENV USER=bloom
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


WORKDIR /appbox
COPY . ./

# Using go mod with go >= 1.11
RUN go mod download
RUN go mod verify

RUN make build

####################################################################################################
## Final image
####################################################################################################
FROM alpine:latest

RUN apk update && apk add --no-cache alsa-lib


# Import from builder.
COPY --from=builder_go /etc/ssl/certs/ca-certificates.crt /etc/ssl/certs/
COPY --from=builder_go /etc/passwd /etc/passwd
COPY --from=builder_go /etc/group /etc/group

WORKDIR /bloom

# Copy our builds
COPY --from=builder_go /appbox/dist/ ./

# Use an unprivileged user.
USER bloom:bloom

CMD ["/bloom/appbox"]
