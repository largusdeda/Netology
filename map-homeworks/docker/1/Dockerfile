FROM ubuntu:16.04
	LABEL maintainer "evopta.stadler@gmail.com"
	RUN apt-get update && apt-get install -y g++ nano
	WORKDIR /usr/src/test
	COPY test.cpp .
	RUN g++ test.cpp -o test
	CMD ["./test"]