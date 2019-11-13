#ifndef _koljeka_h
#define _kolejka_h
#include <initializer_list>
#include <string>

class kolejka{
	private:
		std::string *kol;	
		int pojemnosc;
		int pocz;
		int ile;
	public:
		kolejka();
		kolejka( const kolejka &kolej );
		kolejka( int roz );
		kolejka( std::initializer_list< std::string > str_list );
		void wloz( std::string napis );
		std::string wyciagnij( void );
		int rozmiar( void ) const;
		//kolejka& operator=( kolejka&& kolej);
		//kolejka& operator=( const kolejka& kolej);
		//kolejka( kolejka && kolej );
};
#endif

