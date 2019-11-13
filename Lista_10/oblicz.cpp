#include "oblicz.hpp"

static void DeleteVector( std::vector<kalkulator::symbol*> vec ){
		for( uint i = 0 ; i < vec.size() ; i++ )
			delete vec[i];
}

std::vector<kalkulator::symbol*> Parse( std::istringstream& napis_stream ){
	std::string word;
	std::vector<kalkulator::symbol*> parsed = {};

	try{
		while( !napis_stream.eof() ){
			napis_stream >> word;
			if( kalkulator::liczba::IsIt( word ) ) parsed.push_back( dynamic_cast<kalkulator::symbol*> (new kalkulator::liczba(word)) );
			else if( kalkulator::zmienna::IsIt( word ) ) parsed.push_back( dynamic_cast<kalkulator::symbol*>(new kalkulator::zmienna(word)) );
			else if( kalkulator::stala::IsIt( word ) ) parsed.push_back( dynamic_cast<kalkulator::symbol*>(new kalkulator::stala(word)) );
			else if( kalkulator::func_1::IsIt( word ) ) parsed.push_back( dynamic_cast<kalkulator::symbol*>(new kalkulator::func_1(word)) );
			else if( kalkulator::func_2::IsIt( word )) parsed.push_back( dynamic_cast<kalkulator::symbol*>(new kalkulator::func_2(word)) );
			else throw UnrecognizedString();
		}
	}catch( std::exception e){ DeleteVector( parsed); throw e; }
	return parsed;
}

double Oblicz_wyr( std::istringstream& napis_stream ){
	if( napis_stream.eof() ) throw NoEquation();
	std::vector<kalkulator::symbol*> parsed = Parse( napis_stream );
	std::stack<double> nums;

	try{
		for( uint i = 0 ; i < parsed.size() ; i++ )
				parsed[i]->Oblicz( nums );
	}catch( std::exception e ){ DeleteVector( parsed ); throw e; }

	if( nums.size() != 1 ) throw WrongNumberOfOperators();
	DeleteVector( parsed );
	return nums.top();
}

double Przypisz( std::istringstream& napis_stream ){
		std::string equation = "", word;
		while( !napis_stream.eof() ){
			napis_stream >> word;
			if( word == "to" ) break;
			equation += " " + word;
		}
		if( napis_stream.eof() ) throw BadAssignSyntax();
		napis_stream >> word;
		std::istringstream equation_stream( equation );
		double result = Oblicz_wyr(equation_stream);
		if( word.length() > 7 || word == "" ) throw BadVariName();
		if( !kalkulator::zmienna::Add(word, result ) ) throw BadVariName();
		return result;
}
