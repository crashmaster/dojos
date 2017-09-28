FROM ubuntu:latest

RUN \
apt-get update && \
apt-get -y install clang cmake

RUN mkdir /dojos
VOLUME /dojos

CMD /bin/bash
