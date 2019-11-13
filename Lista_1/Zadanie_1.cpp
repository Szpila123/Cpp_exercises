#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>

bool poprawne( std::string boki[] );

int main()
{
	std::string bok[3];
	double pole, pobw = 0;
	do{
		std::clog << "Podaj dlugosci trzech bokow trojkata" << std::endl;
		for( int i = 0 ; i < 3 ; i ++)
			std::cin >> bok[i];
	}while( !poprawne( bok ) );

	for( int i = 0 ; i < 3 ; i ++ )
		pobw += stod( bok[i] );

	pobw /= 2;
	pole = pobw; 

	for( int i = 0 ; i < 3 ; i ++ )
		pole *= pobw - stod( bok[i] );
	pole = sqrt( pole );
	std::cout <<  pole << std::endl;
	return 0;
}

bool poprawne( std::string boki[] )
{
	double dl[3] = { stod( boki[0] ), stod( boki[1] ), stod( boki[2] ) };

	for( int i = 0 ; i < 3 ; i ++ ){
		if( dl[i] + dl[(i+1) % 3] <= dl[(i+2) % 3]){
			std::cerr << "Bledne dlugosci" << std::endl;
			return false;
		}
		if( dl[i] <= 0 ){
			std::cerr << "Dlugosci bokow musza byc dodatnie" << std::endl;
			return false;
		}
	}
	return true;
}


	
