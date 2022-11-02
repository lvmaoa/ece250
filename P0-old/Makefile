CC=g++

CFLAGS=-Wall -Wextra -g
LIBS=-lncurses

IDIR=./include
ODIR=./obj

_DEPS = playlistdriver.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = playlistdriver.o test.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) $^ $(CFLAGS) $(LIBS) 

test: ./test/test.sh

clean:
	rm $(ODIR)/*.o

all: main

.PHONY=all

