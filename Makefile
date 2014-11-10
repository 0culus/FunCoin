CC=clang++
DEBUGFLAGS=-g -Wall
CPP11=-std=c++11
INCLUDE=-I/opt/local/include/ -Ilib/openssl/include
LDFLAGS=-L/opt/local/lib/ -L lib/openssl -lcrypto -lssl -ldl

all: main

main: openssl
	mkdir -p bin
	$(CC) $(CPP11) -g src/main.cc $(INCLUDE) $(LDFLAGS) -o bin/play

openssl:
	cd lib/openssl; ./config; make;

opensslclean:
	make -C openssl/ -k clean

clean:  opensslclean
	rm -rf bin
	mkdir bin
