#include <iostream>
#include <string>
#include <cstdlib>
#include "kolejka.hpp"

using namespace std;

int main(){
//Testowanie wyjatkow
	//Rozmiar kolejki mniejszy niż 1
	try{ kolejka(-1); } catch( const char* c ){ cerr << c << endl; }

	//wyciaganie z pustej kolejki
	try{ kolejka().wyciagnij(); } catch( const char* c){ cerr << c << endl; }
	
	//przeladowanie kolejki
	try{ 
		kolejka b;
		clog << "Dodajmy do kolejki rozmiaru " << b.rozmiar() << " dwa elementy: " << endl;
		b.wloz("a");
		b.wloz("b");
	} catch( const char* c ){ cerr << c << endl; }
		
//Testowanie dzialania
	try{
		//konstruktor z listy inicjalizacyjnej	
		kolejka a( {"qwe", "asd", "zxc"} );
		//wyciaganie elementow
		for( int i = 0 ; i < a.rozmiar() ; i++ )
			clog << a.wyciagnij() << endl;

		//operator przypisania i konstruktor kolejka::kolejka( int )
		a = kolejka( 5 );	

		//metoda zwracajaca rozmiar
		clog << a.rozmiar()<< endl;

		a.wloz( "kruk" );

		//Zawiniecie kolejki	
		for( int i = 0 ; i < 10 ; i++ ){
			a.wloz("a");
			clog << a.wyciagnij() << endl;
		}
		//element  ostatni
		clog << endl << a.wyciagnij() << endl;
	}catch( const char* c){ cerr << c << endl; }

//Program testujacy
	try{
		clog << "Program testujacy dzialanie kolejki" << endl;
		int i = 0;
		string str;
		kolejka *kol = new kolejka;

		do{
			clog << "Instrukcja obslugi:" << endl;
			clog << "0 - wyjdz" << endl;
			clog << "1 - zmiana rozmiaru (czysci kolejke)" << endl;
			clog << "2 - dodanie napisu do kolejki (mozliwe jest przepelnienie)" << endl;
			clog << "3 - wyswietlenie rozmiaru" << endl;
			clog << "4 - wyciagniecie napisu z kolejki (uwazaj na pusta kolejke)" << endl << endl << endl;
			cin >> i;

			switch( i ){
			case 1:
				clog << "Podaj nowy rozmiar kolejki: ";
				cin >> i;
				*kol = kolejka(i);
			break;
			case 2:
				clog << "Podaj napis ktory chcesz dodac: ";
				cin >> str;
				kol->wloz( str );
			break;
			case 3:
				clog << "Rozmiar kolejki to " << kol->rozmiar() << endl;
			break;
			case 4:
				clog << "Wyciagniety napis: " << kol->wyciagnij() << endl;
			break;
			default:
			break;
			}
		}		
		while( i != 0 );
		delete kol;
	} catch( const char* c ){ cerr << c << endl; }
	return 0;
}
	
