#include "symbol.hpp"
#include "oblicz.hpp"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
using namespace kalkulator;

int main(){
	string napis, first;
	double result;

	while( true ){
			try{
				getline( cin, napis);
			}catch(...){ clog << "Error occured during reading your input" << endl; continue;}

			istringstream napis_stream(napis);
			napis_stream >> first;

			try{
				if( napis == "clear") zmienna::clear();
				else if( first == "print"){ result = Oblicz_wyr( napis_stream ); cout << "Wynik: " << result << endl;}
				else if( first == "assign"){ result = Przypisz( napis_stream ); cout << "Wynik: " << result << endl;}
				else if( napis == "exit") break;
				else clog << "Nie rozpoznano polecenia, sprobuj ponownie" << endl;
			}catch( NotEnoughNumsInStack e){ clog << "The number of operators doesnt match the number of operands" << endl;}
			catch( NoEquation e ){ clog << "Equation is missing from the input" << endl;}
			catch( EmptyStack e){ clog << "There are not enough numbers on the stack to count the equation" << endl;}
			catch( UnrecognizedString e ){ clog << "There is an unrecognized string in your input" << endl;}
			catch( WrongNumberOfOperators e ){ clog << "There are not enough operators" << endl;}
			catch( BadAssignSyntax e ){ clog << "Use \'to\' to assign value to a variable" << endl;}
			catch( BadVariName e ){clog << "You cannot name your variable with key words/funcion names" << endl;}
			catch( ... ){clog << "An error occured" << endl;}
	}
	return 0;
}
