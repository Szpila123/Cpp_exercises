#include "bst.hpp"
#include <iostream>

using namespace struktury;
using namespace std;
int main(){
	bst<int> *tree = new bst<int>( {1,-1,2} );
	tree->remove(-1);
	cout << *(tree) << endl;
	return 0;
}

