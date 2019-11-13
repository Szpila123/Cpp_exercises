C=g++ -Wall -Wextra -Werror -std=c++14 -lm

prog: main.o Wyrazenia.o
	$C Wyrazenia.o main.o -o prog

main.o: main.cpp
	$C -c main.cpp

Wyrazenia.o: Wyrazenia.hpp Wyrazenia.cpp
	$C -c Wyrazenia.cpp
