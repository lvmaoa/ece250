CC=g++

CFLAGS=-g -std=c++11
LIBS=

IDIR=./include
ODIR=./obj

_DEPS = playlistdriver.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = playlistdriverextra.o playlistdriver.o
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

