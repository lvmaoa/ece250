CC=g++

CFLAGS=-g -std=c++11 -Wall
LIBS=

triedriver: triedriver.cpp trie.cpp
	$(CC) triedriver.cpp trie.cpp $(CFLAGS)

all:
	triedriver

clean:
	rm *.out

.PHONY=triedriver

