CC=g++

CFLAGS=-g -std=c++11
LIBS=

IDIR=./include
ODIR=./obj

.PHONY = all

all: openhttest orderedhttest

openhttest: openhttest.cpp $(IDIR)/openhttest.hpp
	$(CC) -o openhttest $(CFLAGS) openhttest.cpp open.cpp $(LIBS) 

orderedhttest: orderedhttest.cpp $(IDIR)/orderedhttest.hpp
	$(CC) -o orderedhttest $(CFLAGS) orderedhttest.cpp ordered.cpp $(LIBS) 

test:
	./testing/test.sh

clean:
	rm openhttest orderedhttest

