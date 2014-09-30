CC=clang++
FLAGS=-g -Wall
MACPORTSINCLUDE=-I/opt/local/include/
MACPORTSLINK=-L/opt/local/lib/ 

play:
	$(CC) src/main.cc -lbeecrypt -o bin/play

# Because MacPorts likes to put things under /opt/local/...
test: 
	$(CC) src/main.cc $(MACPORTSINCLUDE) $(MACPORTSLINK) -lbeecrypt -o bin/play
