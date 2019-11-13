CC=g++
CFLAGS= -std=c++14 -Wall -Wextra

BINS=prog
SRCS=$(wildcard *.cpp *.hpp)

all: $(BINS)

prog: main.o oblicz.o symbol.o
	$(CC) $(CFLAGS) $^ -o prog
main.o: main.cpp
oblicz.o: oblicz.cpp oblicz.hpp 
symbol.o: symbol.cpp symbol.hpp

clean:
	@rm -vf $(BINS) *.o
