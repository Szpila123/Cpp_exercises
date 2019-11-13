#include "symbol.hpp"
#include <iostream>

static std::vector<std::string> Operacje_1 = {"abs", "sgn", "floor", "ceil", "frac", "sin", "cos", "atan", "acot", "ln", "exp"};
static std::vector<std::string> Operacje = { "to", "print", "assign", "clear", "exit", "modulo", "min", "max", "log", "pow" };

//Obliczanie wszystkich operandów
void kalkulator::operand::Oblicz ( std::stack<double>& nums){ nums.push( num ); }

//Liczba
kalkulator::liczba::liczba( std::string num ){ this->num = std::stod(num); }
bool kalkulator::liczba::IsIt( std::string obj )
{
	try{ std::stod( obj );} catch(...){ return false; }
	return true;
}

//Stala
std::map<std::string,double> kalkulator::stala::Stale = {{"e", 2.7182}, {"pi",3.1415}, {"fi", 1.618033}};
kalkulator::stala::stala( std::string name ){ num = stala::Stale[name];}
bool kalkulator::stala::IsIt( std::string obj ){ return stala::Stale.end() != stala::Stale.find(obj); }

//Zmienna
std::map<std::string,double> kalkulator::zmienna::Zmienne = {};
kalkulator::zmienna::zmienna( std::string name ){  num = zmienna::Zmienne[name]; }
bool kalkulator::zmienna::IsIt( std::string obj ){return zmienna::Zmienne.end() != zmienna::Zmienne.find( obj );}
bool kalkulator::zmienna::Add( std::string name, double num ){
	if( !stala::IsIt( name ) &&
	 		Operacje.end() == find(Operacje.begin(), Operacje.end(), name )  &&
			Operacje_1.end() == find(Operacje_1.begin(), Operacje_1.end(), name )){
				zmienna::Zmienne[name] = num;
				return true;
			}
	return false;
}
void kalkulator::zmienna::clear(){ zmienna::Zmienne = {}; }

//Jedno argumentowa fcja
template <typename T> double sgn( T val ){ return (double) ((T(0) < val) - (val < T(0))); }

kalkulator::func_1::func_1( std::string obj ){
		if( obj == "abs") 			func = std::abs;
		else if( obj == "sgn")	func = sgn<double>;
		else if( obj == "floor")func = floor;
		else if( obj == "ceil") func = ceil;
		else if( obj == "frac") func = [](double num)->double{ double a; return modf(num, &a ); };
		else if( obj == "sin") 	func = sin;
		else if( obj == "con") 	func = cos;
		else if( obj == "atan") func = atan;
		else if( obj == "acot") func = [](double num)->double{ return 1/atan(num); };
		else if( obj == "ln") 	func = log;
		else if( obj == "exp")	func = exp;
}
bool kalkulator::func_1::IsIt( std::string obj ){return Operacje_1.end() != find( Operacje_1.begin(), Operacje_1.end(), obj);}
void kalkulator::func_1::Oblicz( std::stack<double>& nums ){
		if( nums.empty() ) throw NotEnoughNumsInStack();
		double top = nums.top();
		nums.pop();
		nums.push( func( top ));
}


//Dwuargumentowa fcja
kalkulator::func_2::func_2( std::string obj ){
		if( obj == "modulo") 		func = remainder;
		else if( obj == "min")	func = fmin;
		else if( obj == "max") 	func = fmax;
		else if( obj == "log") 	func = [](double a, double b)->double{ return std::log(b) / std::log(a);};
		else if( obj == "pow") 	func = pow;
		else if( obj == "+") 		func = [](double a, double b)->double{return a+b;};
		else if( obj == "-") 		func = [](double a, double b)->double{return a-b;};
		else if( obj == "*") 		func = [](double a, double b)->double{return a*b;};
		else if( obj == "/") 		func = [](double a, double b)->double{return a/b;};
}
bool kalkulator::func_2::IsIt( std::string obj ){
	return obj == "modulo" 	|| obj == "min" || obj == "max"
			|| obj == "log" 		|| obj == "pow" || obj == "+"
	 		|| obj == "-" 			|| obj == "*" 	|| obj == "/";
}
void kalkulator::func_2::Oblicz( std::stack<double>& nums ){
		double num1, num2;
		if( nums.empty() ) throw NotEnoughNumsInStack();
		num2 = nums.top();
		nums.pop();
		if( nums.empty() ) throw NotEnoughNumsInStack();
		num1 = nums.top();
		nums.pop();
		nums.push( func( num1, num2));
}
