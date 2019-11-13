#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "strumienie.hpp"

using namespace std;
using namespace strumienie;

int main( int argc, char const* argv[] ){

	if( argc == 1)
	{
		//Zadanie 3
		vector<string> vec(5);
		string str;

		//delete first line
		cin >> clearline;
		//ignore 2 charactes of 2nd line and load the rest
		ignore( cin, 2 );
		getline( cin, str );
		vec.push_back( str );
		//ignore 10 characters of 3rd line and load the rest
		ignore( cin, 10 );
		getline( cin, str );
		vec.push_back( str );
		//get 2 next lines
		getline( cin, str );
		vec.push_back( str );
		getline( cin, str );
		vec.push_back( str );

		sort(vec.begin(), vec.end(), less<string>() );

		int i = 1;
		for( string str : vec )
		{
			if( str != "")
			{
				index( cout, i++ , 4 );
				cout << colon << str << endl;
			}
		}
		cout << endl;
		return 0;
	}
	//Zadnie 5
	if( argc != 3 )
	{
		cerr << "Zla liczba argumentow" << endl;
		return 0;
	}

	wejscie wej( argv[1] );
	wyjscie wyj( argv[2] );
	int z;
	while( (z = wej.read()) != EOF )
		wyj.write( z+1 );

	return 0;
}
