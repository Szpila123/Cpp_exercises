#ifndef wyrazenia_h
#define wyrazenia_h
#include <string>
#include <vector>
#include <cmath>

class Wyrazenie{
	public:
		virtual double oblicz() const =0;
		virtual std::string opis() const =0;
};

class Liczba : public Wyrazenie{
	private:
		double liczba;
	public:
		double oblicz() const override { return liczba; }
		std::string opis() const override { return std::to_string( liczba ); }
		Liczba( double liczba ) : liczba(liczba) {};
};

class Stala : public Wyrazenie{
	protected:
		std::string name;
	public:
		std::string opis() const override { return name; }
};

class Pi : public Stala{
	public:
		Pi(){ name = "pi"; }
		double oblicz() const override { return 3.1415; }
};
class E : public Stala{
	public:
		E(){ name = "e"; }
		double oblicz() const override { return 2.71828182845904523536; }
};
class Fi : public Stala{
	public:
		Fi(){ name = "pi"; }
		double oblicz() const override { return 1.618033988749894848; }
};

class Zmienna : public Wyrazenie{
	private:
		std::string name;
		static std::vector<std::pair<std::string,double>> Context;
		double Find() const;
	public:
		double oblicz() const override { return this->Find(); }
		std::string opis() const override { return name; }
		Zmienna( std::string name ){
			if( name == "" ) throw "Empty name";
			this->name = name;
		}
		static void Add( std::string name, double val );
};

class operator1arg : public Wyrazenie{
	protected:
		Wyrazenie* first;
		std::string name;
	public:
		std::string opis() const override { return name + "(" + first->opis() + ")"; }
		operator1arg( Wyrazenie* first ) : first(first) {};
};

class Sin : public operator1arg{
	public:
		Sin( Wyrazenie* first) : operator1arg(first) { name = "sin"; }
		double oblicz() const override { return sin( first->oblicz() ) ;}
};
class Cos : public operator1arg{
	public:
	Cos( Wyrazenie* first) : operator1arg(first) { name = "cos"; }
	double oblicz() const override { return cos( first->oblicz() ) ;}
};
class Exp : public operator1arg{
	public:
	Exp( Wyrazenie* first) : operator1arg(first) { name = "exp"; }
	double oblicz() const override { return exp( first->oblicz() ) ;}
};
class Ln : public operator1arg{
	public:
	Ln( Wyrazenie* first) : operator1arg(first) { name = "ln"; }
	double oblicz() const override { return log( first->oblicz() ) ;}
};
class Bezwzgl : public operator1arg{
	public:
	Bezwzgl( Wyrazenie* first) : operator1arg(first) { name = "abs"; }
	double oblicz() const override { return std::abs( first->oblicz() ) ;}
};
class Przeciw : public operator1arg{
	public:
	Przeciw( Wyrazenie* first) : operator1arg(first) { name = "-"; }
	double oblicz() const override { return -( first->oblicz() ) ;}
};
class Odwrot : public operator1arg{
	public:
	Odwrot( Wyrazenie* first) : operator1arg(first) { name = "1/"; }
	double oblicz() const override { return 1.0/( first->oblicz() ) ;}
};

class operator2arg : public operator1arg{
	protected:
		Wyrazenie *second;
	public:
		operator2arg( Wyrazenie* first, Wyrazenie* second ) : operator1arg( first ), second( second ) {};
		std::string opis() const override;
};

class Dodaj : public operator2arg{
	public:
	Dodaj( Wyrazenie* first, Wyrazenie* second ) : operator2arg( first, second ){ name = "+"; }
	double oblicz() const override { return first->oblicz() + second->oblicz() ;}
};

class Odejmij : public operator2arg{
	public:
	Odejmij( Wyrazenie* first, Wyrazenie* second ) : operator2arg( first, second ){ name = "-"; }
	double oblicz() const override { return first->oblicz() - second->oblicz() ;}
};

class Mnoz : public operator2arg{
	public:
	Mnoz( Wyrazenie* first, Wyrazenie* second ) : operator2arg( first, second ){ name = "*"; }
	double oblicz() const override { return first->oblicz() * second->oblicz() ;}
};


class Dziel : public operator2arg{
	public:
	Dziel( Wyrazenie* first, Wyrazenie* second ) : operator2arg( first, second ){ name = "/"; }
	double oblicz() const override { return first->oblicz() / second->oblicz() ;}
};

class Logarytm : public operator2arg{
	public:
	Logarytm( Wyrazenie* base, Wyrazenie* num) : operator2arg( base, num){ name = "log";}
	double oblicz() const override { return log( second->oblicz() ) / log( first->oblicz()); }
	std::string opis() const override { return "log( " + first->opis() + " , " + second->opis() + " ) "; }
};

class Modulo : public operator2arg{
	public:
	Modulo( Wyrazenie* first, Wyrazenie* second) : operator2arg( first, second){ name = "%";}
	double oblicz() const override { return (long)first->oblicz() % (long)second->oblicz(); }
};

class Potega : public operator2arg{
	public:
	Potega( Wyrazenie* first, Wyrazenie* second) : operator2arg( first, second){ name = "^";}
	double oblicz() const override { return pow(first->oblicz(), second->oblicz() ); }
};
#endif
