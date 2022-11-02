CC=g++

CFLAGS=-g -std=c++11 -Wall
LIBS=

IDIR=./include
ODIR=./obj

_DEPS = dequeaslistdriver.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = dequeaslistdriver.o dequeaslist.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

TARGET = a.out
INPUTS = $(shell ls $(TDIR)/*.in)
OUTPUTS = $(patsubst $(TDIR)%.in, $(TDIR)%.out, $(INPUTS))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) $^ $(CFLAGS) $(LIBS) 

test:
	./testing/test.sh

clean:
	rm $(ODIR)/*.o

all: main

.PHONY=all

