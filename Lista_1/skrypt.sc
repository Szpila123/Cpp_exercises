#! /bin/bash
g++ -std=c++14 -o Zadanie_1 Zadanie_1.cpp
g++ -std=c++14 -o Zadanie_2 Zadanie_2.cpp
./Zadanie_1 <boki.txt 2>&0 | ./Zadanie_2 >promien.txt
