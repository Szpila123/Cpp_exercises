#include <iostream>
#include "wymierna.hpp"

using namespace obliczenia;
using namespace std;

int main(){
	wymierna a(12, 20);
	cout << double(a) << " = " <<  a << endl;
	cout << "Zaokraglenie a to " << int(a) << endl;

	wymierna b( 20 );
	wymierna c = a + b;
	cout << c << " = " << a << " + " << b << endl;
	cout << double( a - b ) << " = " << a << " - " << b << endl;
	cout << a * wymierna( 3, 18 ) << " = " << a << " * " << wymierna( 3, 18 ) << endl;
	cout << a / wymierna( 3, 1 ) << " = " << a << " / " << wymierna( 3, 1 ) << endl;

	try{
		a/wymierna(0,2);
	}catch( dzielenie_przez_0 a ){
		cerr << "Dzielenie przez 0" << endl;
	}

	try{
		a + wymierna( ~(1<<31), 1);
	}catch( przekroczenie_zakresu a){
		cerr << "Przekroczenie zakresu" << endl;
	}

	try{
		wymierna(4,0);
	}catch( wyjatek_wymierny a ){
		cerr << "Zla inicjalizacja 1" << endl;
	}
	catch( mianownik_rowny_0 a){
		cerr << "Zla inicjalizacja 2" << endl;
	}

	return 0;
}
