FROM ubuntu:latest

RUN \
apt-get update && \
apt-get -y install clang cmake libgtest-dev && \
cd /usr/src/gtest && \
cmake CMakeLists.txt && \
make && \
cp *.a /usr/lib

RUN mkdir /dojos
VOLUME /dojos

CMD /bin/bash
