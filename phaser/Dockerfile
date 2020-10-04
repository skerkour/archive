FROM debian:9

RUN useradd -ms /bin/bash bloom

RUN mkdir /phaser && chown -R bloom:bloom /phaser && chmod 700 /phaser

# Add build
COPY ./dist/ /phaser/

COPY phaser.default.sane /phaser/phaser.sane

# install dependencies
RUN echo "deb http://deb.debian.org/debian unstable main" >> /etc/apt/sources.list
RUN apt update -y && apt dist-upgrade -y && apt upgrade -y

# we install libs because executable is not static
RUN apt install -y pkg-config openssl libssl-dev ca-certificates

# phaser's dependencies
RUN apt install -y  python3 python3-pip \
    dnsutils whois nmap
RUN apt -t unstable install -y sqlmap


USER bloom


# install dependencies in userland
RUN pip3 install --upgrade -U sslyze dnspython
# used for python binaries
ENV PATH="${PATH}:/home/bloom/.local/bin"

WORKDIR /phaser
RUN mkdir reports

CMD ["./phaser", "worker"]
