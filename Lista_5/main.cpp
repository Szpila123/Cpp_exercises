#include <iostream>
#include "wielomian.hpp"
using namespace std;

int main(){
	wielomian a({1,2,3}); //Inicjalizacja listą
	wielomian b(2); //Inicjalizacja stopniem

	cout << "Inicjalizacja " << wielomian(0, 3.0) << endl; //Inicjalizacja jednomianu
 	cout << "Wielomian a: " << a << endl; //Operator <<
	cout << "Wielomian b: " << b << endl;
	cout << "a[0] = " << a[0] << endl; //Indeksowanie
	cout << "a+b = " << a+b << endl; //Operator + 
	cout << "a-b = " << a-b << endl; //Operator - 
	cout << "a*b = " << a*b << endl; //Operator * 
	cout << "2*a = " << 2*a << endl; //Operator * dla double
	cout << "Wprowadz nowy rozmiar a: " << endl;
	int x;
	cin >> x;
	a = wielomian(x);
	cout << "Wprowadz wspolczynniki a: " << endl;
	try{ cin >> a; }catch( const char* c){ cerr << c << endl; } //Operator >>
	cout << "Nowe a " << a << endl;
	cout << "a *= b :" << (a*=b) << endl;
	cout << "a += b :" << (a+=b) << endl;
	cout << "a -= b :" << (a-=b) << endl;
	return 0;
}
