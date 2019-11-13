LIBS = -std=c++14 -Wall -Wextra -Werror 

prog: main.o kolejka.o
	g++ $(LIBS) main.o kolejka.o

main.o:  main.cpp
	g++ $(LIBS) -c main.cpp

kolejka.o: kolejka.cpp kolejka.hpp
	g++ $(LIBS) -c kolejka.cpp 
