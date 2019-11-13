#ifndef wymierna_h
#define wymierna_h

#include <iostream>
namespace obliczenia{
	class wymierna{
		private:
			int licz,mian;
		public: 
			int GetMian() const { return mian; }
			int GetLicz() const { return licz; }
			wymierna( int licz, int mian );
			wymierna( int liczba );
			
			wymierna operator !() const;
			wymierna operator -() const;
			wymierna operator +( const wymierna ulamek ) const;
			wymierna operator -( const wymierna ulamek ) const;
			wymierna operator *( const wymierna ulamek ) const;
			wymierna operator /( const wymierna ulamek ) const;
			operator double() const;
			operator int() const ;

			friend std::ostream& operator<<( std::ostream &wyj, const wymierna &w);
	};


	class wyjatek_wymierny{};
	class dzielenie_przez_0 : wyjatek_wymierny {};
	class mianownik_rowny_0 : wyjatek_wymierny {};
	class przekroczenie_zakresu : wyjatek_wymierny {};
	std::ostream& operator<<( std::ostream &wyj, const wymierna &w);
}


#endif
