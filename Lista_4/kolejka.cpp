#include <string>
#include <initializer_list>
#include <cstdlib>
#include "kolejka.hpp"
using namespace std;

kolejka::kolejka() : pojemnosc(1), pocz(0), ile(0){
	kol = new string[ pojemnosc ];
}

kolejka::kolejka( const kolejka &kolej ) : pojemnosc( kolej.pojemnosc ),  pocz( kolej.pocz ), ile( kolej.ile ){
	kol = new string[ pojemnosc ];
	for( int i = pocz ; i % pojemnosc <= ( pocz + ile ) % pojemnosc ; i++ )
		kol[i] = kolej.kol[i];
}	

kolejka::kolejka( int roz ) : pojemnosc( roz ), pocz(0), ile(0){
	if( roz <= 0 ) throw "Rozmiar mniejszy niz 1";
	kol = new string[pojemnosc];
}

kolejka::kolejka( initializer_list< string > str_list) : pojemnosc( str_list.size() ), pocz( 0 ),
		 ile( str_list.size() ){
	kol = new string[pojemnosc];
	auto wsk = str_list.begin();
	for( int i = 0 ; i < pojemnosc ; i ++ )
		kol[i] = wsk[i];
}

void kolejka::wloz( string str ){
	if( ile == pojemnosc ) throw "Brak miejsca w kolejce";
	kol[ (pocz + ile) % pojemnosc ] = str;
	ile++;
}

string kolejka::wyciagnij( void ){
	if( ile == 0 ) throw "Kolejka pusta";
	string str = kol[pocz];
	pocz = (pocz + 1) % pojemnosc;
	ile-=1;
	return str;
}

int kolejka::rozmiar( void ) const{ return pojemnosc; }

