#ifndef oblicz_h
#define oblicz_h

#include "symbol.hpp"
#include <vector>
#include <sstream>
#include <stack>
#include <string>
#include <iostream>

double Oblicz_wyr( std::istringstream& napis_stream );
std::vector<kalkulator::symbol*> Parse( std::istringstream& napis_stream );
double Przypisz( std::istringstream& napis_stream );

class NoEquation : std::exception {};
class EmptyStack : std::exception {};
class UnrecognizedString : std::exception{};
class WrongNumberOfOperators: std::exception{};
class BadAssignSyntax : std::exception{};
class BadVariName : std::exception{};
#endif
