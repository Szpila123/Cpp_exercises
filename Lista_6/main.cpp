#include "Wyrazenia.hpp"
#include <iostream>
using namespace std;

int main(){
	Zmienna::Add( "x", 3 );

	Wyrazenie* wyr = new Odejmij(new Pi(),new Dodaj(new Liczba(2),new Mnoz(new Zmienna("x"),new Liczba(7))));
	cout << wyr->opis() << " = " << wyr->oblicz() << endl;

	Zmienna::Add( "x", 0 );
	Zmienna::Add( "y", 0 );
	Wyrazenie* wyrs[4];
	wyrs[0] = new Dziel( new Mnoz( new Odejmij( new Zmienna("x"), new Liczba(1)), new Zmienna("x")), new Liczba(2));
	wyrs[1] = new Dziel(new Dodaj( new Liczba(3), new Liczba(5)), new Dodaj( new Liczba(2), new Mnoz( new Zmienna("x"), new Liczba(7))));
	wyrs[2] = new Odejmij( new Dodaj( new Liczba(2), new Mnoz( new Zmienna("x"), new Liczba(7))), new Dodaj( new Mnoz( new Zmienna("y"), new Liczba(3)), new Liczba(5)));
	wyrs[3] = new Dziel( new Cos( new Mnoz( new Dodaj( new Zmienna( "x" ), new Liczba(1)), new Zmienna("x"))), new Potega( new E(), new Potega( new Zmienna("x"), new Liczba(2))));

	for( double i = 0 ; i <= 1 ; i += 0.01 ){

		Zmienna::Add( "x", i );
		Zmienna::Add( "y", i );

		cout << "Dla x i y = " << i << ":" << endl;

		for( int x = 0 ; x < 4 ; x++ )
			cout << wyrs[x]->opis() << " = " << wyrs[x]->oblicz() << endl;
		cout << endl << endl;
	}

	return 0;
}
