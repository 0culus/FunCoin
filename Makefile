CC=clang++
DEBUGFLAGS=-g -Wall
CPP11=-std=c++11
INCLUDE=-I/opt/local/include/ -Ilib/beecrypt/include
LDFLAGS=-L/opt/local/lib/ -Llib/beecrypt 

all:main

main: beecrypt
	mkdir -p bin
	$(CC) $(CPP11) -g src/main.cc $(INCLUDE) $(LDFLAGS) -lbeecrypt -o bin/play

#beecrypt things
beecrypt:
	cd lib/beecrypt; sh autogen.sh; ./configure; make;

cleancrypt:
	make -C lib/beecrypt/ -k clean

# Because MacPorts 
test:
	$(CC) $(CPP11) src/main.cc $(INCLUDE) $(LDFLAGS) -lbeecrypt -o bin/play

clean: cleancrypt
	rm -rf bin
	mkdir bin
