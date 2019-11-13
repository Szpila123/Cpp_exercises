C = g++ -std=c++14

prog: main.o strumienie.o
	$C main.o strumienie.o -o prog

main.o: main.cpp
	$C -c main.cpp

strumienie.o: strumienie.cpp strumienie.hpp
	$C -c strumienie.cpp
clean:
	-rm -f $(wildcard *.o) prog
