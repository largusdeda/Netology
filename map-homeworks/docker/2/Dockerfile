FROM ubuntu:16.04
	LABEL maintainer "evopta.stadler@gmail.com"
	RUN apt-get update && apt-get install -y build-essential nano
	WORKDIR /usr/src/async_for_each
	COPY main.cpp async_for_each.h .
	RUN g++ -std=c++17 -pthread main.cpp -o async_for_each
	CMD ["./async_for_each"]