play:
	clang++ src/main.cc -lbeecrypt -o bin/play

# Because MacPorts likes to put things under /opt/local/...
test: 
	clang++ src/main.cc -I/opt/local/include/ -L/opt/local/lib/ -lbeecrypt -o bin/play
