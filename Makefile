CC=clang++
DEBUGFLAGS=-g -Wall
BCINC=-I lib/beecrypt/include
CPP11=-std=c++11
MACPORTSINCLUDE=-I/opt/local/include/
LDFLAGS=-L/opt/local/lib/ -Llib/beecrypt 

all:main beecrypt

main:
	$(CC) $(CPP11) -g src/main.cc $(BCINC) $(LDFLAGS) -lbeecrypt -o bin/play

#beecrypt things
beecrypt:
	cd lib/beecrypt; sh autogen.sh; ./configure; make;

cleancrypt:
	make -C lib/beecrypt/ -k clean

# Because MacPorts 
test:
	$(CC) $(CPP11) src/main.cc $(MACPORTSINCLUDE) $(MACPORTSLINK) -lbeecrypt -o bin/play

clean: cleancrypt
	rm -rf bin
	mkdir bin
