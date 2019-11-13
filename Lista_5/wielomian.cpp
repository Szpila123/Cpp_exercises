#include <iostream>
#include <initializer_list>
#include <iostream>
#include "wielomian.hpp"

	wielomian::wielomian( int st, double wsp ) : n(st){
		if( st < 0 ) throw "Wrong size";
		if( wsp != 0 ){
			a = new double[st+1];
			a[st] = wsp;
		}	
		else{
			a = new double[1];
			n = 0;
		}
	}

	wielomian::wielomian( int st, const double wsp[] ) : n(st){
		if( st < 0 ) throw "Wrong size";
		a = new double[n + 1];
		int non_zero = 0;
		for( int i = 0 ; i <= st ; i ++ ){
			a[i] = wsp[i];
			if( a[i] != 0 ) non_zero = i;
		}
		n = non_zero;
	}

	wielomian::wielomian( std::initializer_list<double> wsp ) : n( wsp.size() - 1 ){
		a = new double[n + 1];
		auto wsk = wsp.begin();
		int non_zero = 0;
		for( int i = 0 ; i <= n ; i++ ){
			a[i] = wsk[i];
			if( a[i] != 0 ) non_zero = i;
		}
		n = non_zero;
	}

	wielomian::wielomian( const wielomian &w ) : n(w.n){
		a = new double[n + 1];
		for( int i = 0 ; i <= n ; i ++ ) a[i] = w.a[i];
	}

	wielomian::wielomian( wielomian &&w ) : n(w.n){
		a = w.a;
		w.a = nullptr;
	}

	wielomian& wielomian::operator= ( const wielomian &w ){
		if( &w == this ) return *this;
		n = w.n;
		delete[] a;
		a = new double[n+1];
		for( int i = 0 ; i <=n ; i ++ ) a[i] = w.a[i];
		return *this;
	}

	wielomian& wielomian::operator= ( wielomian &&w ){
		n = w.n;
		delete[] a;
		a = w.a;
		w.a = nullptr;
		return *this;
	}

	wielomian::~wielomian(){ delete[] a; }

	std::istream& operator>> ( std::istream &we, wielomian &w ){ 
		for( int i = 0 ; i <= w.n ; i++ )
			we >> w.a[i];
		if( w.a[w.n] == 0 ){
			w.a[w.n] = 1;
			throw "The coefficient of biggest power of a polynomial cannot be 0, changing to 1";
		}
		return we;
	}

	std::ostream& operator<< ( std::ostream &wy, const wielomian &w ){
		for( int i = w.n ; i >= 0 ; i-- ){
			wy << w.a[i];
			if( i > 0 ) wy << " * x^" << i << " + ";
		}
		return wy;
	}

		
	wielomian operator+ ( const wielomian &u, const wielomian &v ){
		int size = u.n > v.n ? u.n + 1 : v.n + 1;
		double wsp[size];
		for( int i = 0 ; i < size ; i++ ) wsp[i] = 0;
		for( int i = 0 ; i < size ; i ++ ) wsp[i] = u[i] + v[i];
		return (wielomian) { size-1, wsp };
	}

	wielomian operator- ( const wielomian &u, const wielomian &v ){
		int size = u.n > v.n ? u.n + 1 : v.n + 1;
		double wsp[size];
		for( int i = 0 ; i < size ; i++ ) wsp[i] = 0;
		for( int i = 0 ; i < size ; i ++ ) wsp[i] = u[i] - v[i];
		return (wielomian) { size-1, wsp };
	}

	wielomian operator* ( const wielomian &u, const wielomian &v ){
		int size = u.n + v.n;
		double wsp[size + 1];
		for( int i = 0 ; i < size + 1 ; i++ ) wsp[i] = 0;
		for( int i = 0 ; i <= u.n ; i++ )
			for( int j = 0 ; j <= v.n ; j++ )
				wsp[i+j] += u[i] * v[j];
		return (wielomian) { size, wsp };
	}

	wielomian operator* ( double c, const wielomian &v ){
		return (wielomian(0, c)) * v;
	}

	wielomian& wielomian::operator += ( const wielomian &v ){
		int max = n > v.n ? n : v.n;
		double *wsk = new double[max+1];
		for( int i = 0 ; i <= max ; i++ ) wsk[i] = (*this)[i] + v[i];
		delete[] a;
		a = wsk;
		n = max;
		while( a[n] == 0 && n > 0 ) n--;
		return *this;
	}

	wielomian& wielomian::operator -= ( const wielomian &v ){
		int max = n > v.n ? n : v.n;
		double *wsk = new double[max+1];
		for( int i = 0 ; i <= max ; i++ ) wsk[i] = (*this)[i] - v[i];
		delete[] a;
		a = wsk;
		n = max;
		while( a[n] == 0 && n > 0 ) n--;
		return *this;
	}
		
	wielomian& wielomian::operator *= ( const wielomian &v ){
		int size = n + v.n;
		double *wsk = new double[size + 1];
		for( int i = 0 ; i < size + 1 ; i++ ) wsk[i] = 0;
		for( int i = 0 ; i <= n ; i ++ )
			for( int j = 0 ; j <= v.n ; j ++ )
				wsk[i+j] += (*this)[i] * v[j];
		delete[] a;
		a = wsk;
		n = size;
		return *this;
	}
		
	wielomian& wielomian::operator *= ( double c ){
		if( c == 0 ){
			delete[] a;
			a = new double[1];
			a[0] = 0;
			n = 0;
		}
		else
			for( int i = 0 ; i <= n ; i ++ ) a[i] *= c;
		return *this;
	}
				
	
	double wielomian::operator() ( double x ) const{
		double sum = 0.0;
		for( int i = n ; i >= 0 ; i-- ){
			sum *= x;
			sum += (*this)[i];
		}
		return sum;
	}

	double wielomian::operator[] ( int i ) const{
		if( i < 0 || i > n ) return 0.0;
		else return a[i];
	}
