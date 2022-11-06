CC=g++

CFLAGS=-g -std=c++11
LIBS=

IDIR=./include
ODIR=./obj

openhttest: openhttest.cpp $(IDIR)/openhttest.hpp
	$(CC) -o openhttest $(CFLAGS) openhttest.cpp $(LIBS) 

orderedhttest: orderedhttest.cpp $(IDIR)/orderedhttest.hpp
	$(CC) -o orderedhttest $(CFLAGS) orderedhttest.cpp $(LIBS) 

test:
	./testing/test.sh

clean:
	rm openhttest orderedhttest

all: openhttest orderedhttest

