#include "wymierna.hpp"
#include <cmath>

static int NWD( int a, int b);
static bool Mul_OF( int a, int b );
static bool Add_OF( int a, int b);

obliczenia::wymierna::wymierna ( int licz, int mian ) : licz(licz), mian(mian){
	if( mian == 0 ) throw obliczenia::mianownik_rowny_0() ;
	if( mian < 0 ){
		this->licz = -(this->licz);
		this->mian = -(this->mian);
	}
	int nwd = NWD( abs(this->licz), abs(this->mian) );
	this->licz /= nwd;
	this->mian /= nwd;
}

obliczenia::wymierna::wymierna( int liczba ) : licz(liczba), mian(1){}
		
obliczenia::wymierna obliczenia::wymierna::operator !() const{
	return obliczenia::wymierna( mian, licz );
}

obliczenia::wymierna obliczenia::wymierna::operator -() const {
	return obliczenia::wymierna( -licz, mian );
}

obliczenia::wymierna obliczenia::wymierna::operator +( const wymierna ulamek ) const {
	if( Mul_OF( licz, ulamek.mian ) || Mul_OF( mian, ulamek.licz ) || Mul_OF( mian, ulamek.mian ) ) throw obliczenia::przekroczenie_zakresu();
	int l1 = licz * ulamek.mian, l2 = mian * ulamek.licz;
	if( Add_OF( l1, l2 ) ) throw obliczenia::przekroczenie_zakresu();
	return obliczenia::wymierna( l1 + l2, ulamek.mian * mian );
}

obliczenia::wymierna obliczenia::wymierna::operator -( const wymierna ulamek ) const {
	return *this + -(ulamek);
}

obliczenia::wymierna obliczenia::wymierna::operator *( const wymierna ulamek ) const {
	if( Mul_OF( licz, ulamek.licz ) || Mul_OF( mian, ulamek.mian ) ) throw obliczenia::przekroczenie_zakresu();
	return obliczenia::wymierna( licz * ulamek.licz, mian * ulamek.mian );
}

obliczenia::wymierna obliczenia::wymierna::operator /( const wymierna ulamek ) const{
	if( ulamek.licz == 0 ) throw obliczenia::dzielenie_przez_0();
	return *this * !ulamek;
}
obliczenia::wymierna::operator double() const {
	return (double) (licz) / (double) (mian);
}
obliczenia::wymierna::operator int() const {
	return licz/mian;
}

std::ostream& obliczenia::operator<< ( std::ostream &wyj, const obliczenia::wymierna &w) {
	wyj << "[" << w.GetLicz() << "/" << w.GetMian() << "]";
	return wyj;
}


static int NWD( int a, int b ){
	int temp;
	while( a != 0 ){
		temp = a;
		a = b%a;
		b = temp;
	}
	return b;
}

static bool Mul_OF( int a, int b ){
	return (bool) ( (b < 0) && ( a == 1<<31 ) ) || ( ( b != 0 ) && ( (a*b)/b != a));
}

static bool Add_OF( int a, int b){
	return (bool) ( (~(a^b) & ((a+b)^a)) >> 31);
}
