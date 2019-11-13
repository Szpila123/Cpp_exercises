#include <iostream>
#include <fstream>
#include <string>

namespace strumienie
{
	//Zadanie 1
	std::istream& clearline( std::istream& stream );
	std::istream& ignore( std::istream& stream, int x );

	//Zadanie 2
	std::ostream& comma( std::ostream& stream );
	std::ostream& colon( std::ostream& stream );
	std::ostream& index( std::ostream& stream, int x, int w);

	//Zadanie 4
	class wejscie
	{
		private:
			 std::ifstream stream;
			 std::string filename;

		public:
			 wejscie( std::string filename );
			 int read();
			 ~wejscie();
			 friend wejscie& operator>>( wejscie& wej, int& data );
	};

	class wyjscie
	{
		private:
			std::ofstream stream;
			std::string filename;
		public:
			wyjscie( std::string filename );
			void write( int x );
			~wyjscie();
			friend wyjscie& operator<<( wyjscie& wyj, const int& data );
	};

	wejscie& operator>>( wejscie& wej, int& data );
	wyjscie& operator<<( wyjscie& wyj, int& data );
}
