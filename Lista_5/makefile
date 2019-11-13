CPP=g++ -std=c++14 -Wall -Wextra -Werror -Wall

prog: main.o wielomian.o
	$(CPP) main.o wielomian.o -o prog

main.o: main.cpp
	$(CPP) -c main.cpp

wielomian.o: wielomian.cpp wielomian.hpp
	$(CPP) -c wielomian.cpp 
