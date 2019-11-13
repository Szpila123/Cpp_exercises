#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>

int main(){

	std::string spole;
	double pole;

	do{
		std::clog << "Prosze podac pole powierzchni figury" << std::endl;
		std::cin >> spole;
		if( pole <= 0 ) std::cerr << "Pole figury musi byc dodatnie" << std::endl;
	}while( pole <= 0 );
	try{
		pole = stod( spole );
	} catch ( const std::exception& e ) {
		std::cerr << "Error thrown " <<  e.what() << std::endl;
		return 0;
	}
	std::cout << "Promien kola o danej powierzchni to " << sqrt( pole / M_PI ) << std::endl;
	return 0;
}




