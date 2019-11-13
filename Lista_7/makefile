C=g++ -Werror -Wall -Wextra -std=c++14 -lm

prog: main.o wymierna.o
	$C main.o wymierna.o -o prog
main.o: main.cpp
	$C -c main.cpp
wymierna.o: wymierna.cpp wymierna.hpp
	$C -c wymierna.cpp
