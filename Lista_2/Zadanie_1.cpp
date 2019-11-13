#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;

bool SprNum( string num );
string bin2rzym( int num );

const vector<pair<int,string>> rzym = {
	{1000, "M"},
	{900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
	{90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"},
	{9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
};

int main( int argc, char* argv[] ){

	string numd;
	for( int i = 1 ; i < argc ; i ++ ) 
		if( SprNum( numd = argv[i] ) ) cout << bin2rzym( stoi( numd )) << endl;

	return 0;
}

bool SprNum( string snum ) 
{
	int inum; 
	try{
		inum = stoi( snum );
	} catch( ... ) {
		clog << "Error occured, please reenter the number\n";
		return false;
	}

	if( inum < 1 || inum > 3999 ){
		clog << "Number out of scope [1, 3999]\n";
		return false;
	}

	return true;
}

string bin2rzym( int num )
{
	string numr = "";
	for( auto u: rzym )
		while( num >= u.first ){
			numr += u.second; 
			num -= u.first;
		}
	return numr;
}

		
