#ifndef symbol_h
#define symbol_h
#include <vector>
#include <algorithm>
#include <cmath>
#include <functional>
#include <map>
#include <stack>
#include <string>

namespace kalkulator{

	class symbol{
	public:
		virtual void Oblicz( std::stack<double>& nums) =0;
	};

	class operand : public symbol{
	protected:
		double num;
	public:
		virtual void Oblicz( std::stack<double>& nums) override;
	};

	class liczba : public operand{
	public:
		liczba( std::string num );
		static bool IsIt( std::string obj );
	};

	class zmienna : public operand{
	private:
		static std::map<std::string,double> Zmienne;
	public:
		zmienna( std::string name );
		static bool IsIt( std::string obj );
		static bool Add( std::string name, double num );
		static void clear();
	};

	class stala : public operand{
	private:
		static std::map<std::string,double> Stale;
	public:
		static bool IsIt( std::string obj );
		stala( std::string name );
	};

	class oper : public symbol{};

	class func_1 : public oper
	{
	public:
		void Oblicz( std::stack<double>& nums ) override;
		func_1( std::string obj );
		static bool IsIt( std::string obj);
	private:
		double (*func)( double );
	};

	class func_2 : public oper
	{
	public:
		void Oblicz( std::stack<double>& nums ) override;
		func_2( std::string obj );
		static bool IsIt( std::string obj );
	private:
		double (*func)( double, double );
	};

	class NotEnoughNumsInStack : std::exception {};
}
#endif
