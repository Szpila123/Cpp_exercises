#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include "strumienie.hpp"

//Zadanie 1
std::istream& strumienie::clearline( std::istream& stream)
{
	char z;
	while( stream.good() && (z = stream.get() ) != '\n' && z != EOF );
	return stream;
}

std::istream& strumienie::ignore( std::istream& stream, int x )
{
	if( x <= 0 ) return stream;
	char z;

	for( ; x > 0 && stream.good() ; x-- )
		if( (z = stream.get() ) == '\n' || z == EOF ) return stream;

	return stream;
}

//Zadanie 2
std::ostream& strumienie::comma( std::ostream& stream )
{
	return stream << ", ";
}

std::ostream& strumienie::colon( std::ostream& stream )
{
	return stream << ": ";
}

std::ostream& strumienie::index( std::ostream& stream, int x, int w)
{
	int wid = stream.width();

	stream << "[";

	stream.width(w);
	stream << x;

	stream.width(wid);
	return stream << "]";
}


//Zadanie 4
strumienie::wejscie::wejscie( std::string filename ) : stream( filename ), filename( filename )
{
	if( stream.fail() )
		throw std::ios_base::failure( "Couldnt open the file " + filename );
}

int strumienie::wejscie::read()
{
	if( !stream.fail() ) return stream.get();
	else throw std::ios_base::failure( "Coulnt read from the file " + filename );
}

strumienie::wejscie::~wejscie()
{
		stream.close();
		filename = "";
}

strumienie::wyjscie::wyjscie( std::string filename ) : stream( filename ), filename( filename )
{
	if( stream.fail() )
	throw std::ios_base::failure( "Couldnt open file " + filename );
}

void strumienie::wyjscie::write( int x )
{
	if( !stream.fail() ) stream.put( x & 0xff);
	else throw std::ios_base::failure( "Couldnt write to file " + filename );
}

strumienie::wyjscie::~wyjscie()
{
	stream.close();
	filename = "";
}

strumienie::wejscie& operator>>( strumienie::wejscie& wej, int& data )
{
	data = wej.read();
	return wej;
}

strumienie::wyjscie& operator<<( strumienie::wyjscie& wyj, int& data )
{
	wyj.write( data );
	return wyj;
}
