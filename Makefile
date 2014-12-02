CC=clang++
DEBUGFLAGS=-g -Wall
CPP11=-std=c++11
INCLUDE=-I/opt/local/include/ -Ilib/openssl/include
LDFLAGS=-L/opt/local/lib/ -L lib/openssl -lcrypto -lssl -ldl

all: main

main:
	mkdir -p bin
	$(CC) $(CPP11) -g src/main.cc $(INCLUDE) $(LDFLAGS) -o bin/play
openssl:
	cd lib/openssl; ./config; make;

opensslclean:
	make -C lib/openssl/ -k clean

redblack: src/c_redblack.hpp src/c_redblack_main.cpp
	$(CC) $(CPP11) $(DEBUGFLAGS) $(INCLUDE) src/c_redblack_main.cpp -o bin/c_redlback_main

blockchain: blockchain.hpp c_redblack.hpp

transaction:
	$(CC) $(CPP11) -g src/transaction.cc $(INCLUDE) $(LDFLAGS) -c -o build/transaction.o	

clean:  opensslclean
	rm -rf bin
	mkdir bin
