CC=clang++
DEBUGFLAGS=-g -Wall
BCINC=-I lib/beecrypt/include
CPP11=-std=c++11
MACPORTSINCLUDE=-I/opt/local/include/
MACPORTSLINK=-L/opt/local/lib/ 

play:
	$(CC) $(CPP11) src/main.cc -lbeecrypt -o bin/play

# Because MacPorts 
test:
	$(CC) $(CPP11) src/main.cc $(MACPORTSINCLUDE) $(MACPORTSLINK) -lbeecrypt -o bin/play

clean:
	rm bin/play
