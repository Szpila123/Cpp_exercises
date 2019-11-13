#include "Wyrazenia.hpp"
#include <typeinfo>

std::vector<std::pair<std::string,double>> Zmienna::Context = std::vector<std::pair<std::string,double>>(0);
void Zmienna::Add( std::string name, double val ){
	if( name == "" ) throw "Adding Empty name";
	for( unsigned int i = 0 ; i < Context.size() ; i++ )
		if( Context[i].first == name ){
			Context[i].second = val;
			return;
		}
	Context.push_back( (std::pair<std::string,double>) {name, val} );
}

double Zmienna::Find() const{
	for( auto i: Context )
		if( i.first == this->name ) return i.second;
	throw "Invalid variable name";
}

std::string operator2arg::opis() const{
	std::string left = first->opis(), right = second->opis();
	if( name == "^" ){
		if( typeid( *first ) == typeid( operator2arg ) )	
			left = "(" + left + ")";
		if( typeid( *second ) == typeid( operator2arg ) && typeid( *second ) != typeid( Potega ) )
			right = "(" + right + ")";
	}		
	if( name == "%" ){
		if( typeid( *first ) == typeid( Dodaj ) || typeid( *first ) == typeid( Odejmij ) )
			left = "(" + left + ")";
		if( typeid( *second ) == typeid( Dodaj ) || typeid( *second ) == typeid( Odejmij ) )
			right = "(" + right + ")";
	}
	else {
		if( (typeid( *first ) == typeid( Dodaj ) && typeid( *this ) != typeid( Dodaj ) && typeid( *this ) != typeid( Odejmij) ) ||
		     (typeid( *first ) == typeid( Odejmij ) && typeid( *this ) != typeid( Odejmij ) && typeid( *this ) != typeid( Dodaj ) ) ||
		     (typeid( *first ) == typeid( Modulo )) )
			left = "(" + left + ")";

		if( (typeid( *second ) == typeid( Dodaj ) && typeid( *this ) != typeid( Dodaj )) || 
		     (typeid( *second ) == typeid( Odejmij ) && typeid( *this ) != typeid( Odejmij )) ||
		     (typeid( *second ) == typeid( Mnoz ) && typeid( *this ) == typeid( Dziel )) ||
		     (typeid( *second ) == typeid( Modulo )))
			right = "(" + right + ")";
	}
	return left + " " + name + " " + right;
}
		
	
	
