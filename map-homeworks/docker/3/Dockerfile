FROM ubuntu:16.04
	LABEL maintainer "evopta.stadler@gmail.com"
	RUN apt-get update && apt-get install -y clang nano
	WORKDIR /usr/src/async_for_each(clang)
	COPY main.cpp async_for_each.h .
	RUN clang++ -std=c++1z -pthread main.cpp -o async_for_each
	CMD ["./async_for_each"]