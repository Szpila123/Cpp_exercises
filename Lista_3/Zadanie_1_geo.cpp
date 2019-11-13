#include <iostream>
#include <cmath>
#include <stdexcept>
#include <vector>
#include "Zadanie_1_geo.h"
#define PI 3.14159265

//Definitions for methods of Point class
Point::Point( double xv, double yv) : x(xv), y(yv){}
Point::Point( const Point &pnt ) : x( pnt.x ), y( pnt.y ){}

void Point::Move( double x, double y){
	this->x += x;
	this->y += y;
}

void Point::Turn( Point pnt, double angle ){
	angle *= PI/180.0;
	double nx = x, ny = y;
	x = cos(angle) * ( nx - pnt.getx() ) - sin(angle) * ( ny - pnt.gety() ) + pnt.getx();
	y = sin(angle) * ( nx - pnt.getx() ) + cos(angle) * ( ny - pnt.gety() ) + pnt.gety();
	if( abs( x ) < 0.000001 ) x = 0;
	if( abs( y ) < 0.000001 ) y = 0;	
}

void Point::Show(){ std::cout << "( " << x << " , " << y << " )"; }
	

//Definitions for methods of Segment class
Segment::Segment( Point pnta, Point pntb ): a( pnta ), b( pntb ){
	try{
		if( pnta.getx() == pntb.getx() && pnta.gety() == pntb.gety() )
			throw std::invalid_argument( "Segment has to have different beggining and ending points\n");
	}catch( const std::invalid_argument& ia ){
		std::cerr << ia.what();
		std::cout << "Destroying segment\n";
		pnta.~Point();
		pntb.~Point();
		this->~Segment();
	}
}

Segment::Segment( const Segment &seg ) : a( seg.a ), b( seg.b ) {}

double Segment::Lenght(){
	return sqrt( ( a.getx() - b.getx() ) * ( a.getx() - b.getx() ) +
		( a.gety() - b.gety() ) * ( a.gety() - b.gety() ) );
}

bool Segment::PntOnSeg( Point pnt ){ return abs( Distance( pnt, a ) + Distance( pnt, b) - Lenght() ) < 0.00000001; }

Point Segment::Middle(){
	Point pnt{ ( a.getx() - b.getx() ) / 2, 
		( a.gety() - b.gety() ) / 2};
	return pnt;
			
}

void Segment::Move( double x, double y){
	a.Move( x, y);
	b.Move( x, y);
}

void Segment::Turn( Point pnt, double angle ){
	a.Turn( pnt, angle );
	b.Turn( pnt, angle );
}

Point Segment::Cross( Segment seg ){
	try{
		double t1, t2;
		double den = ( seg.b.getx() - seg.a.getx() ) * ( a.gety() - b.gety() ) - 
				( a.getx() - b.getx() ) * (seg.b.gety() * seg.a.gety());
	
		if( den == 0 ) throw std::invalid_argument( "Segments don't intersect, den is 0\n");
	
		t1 = ( seg.a.gety() - seg.b.gety() ) * ( a.getx() - seg.a.getx() ) +
			( seg.b.getx() - seg.a.getx() ) * ( a.gety() - seg.a.gety() );
		t2 = ( a.gety() - b.gety() ) * ( a.getx() - seg.a.getx() ) +
			( b.getx() - a.getx() ) * ( a.gety() - seg.a.gety() );
	
		t1 /= den;
		t2 /= den;
		if( t1 > 1 || t1 < 0 || t2 > 1 || t2 < 0 ) throw std::invalid_argument( "Segments dont intersect\n");

		Point pnt(  a.getx() + t1 * (b.getx() - a.getx()), a.gety() + t1 * (b.gety() - a.gety()) );
		return pnt;
	}catch (const std::invalid_argument& ia){
		std::cerr << ia.what();
		return (Point) {0.0,0.0};
	}
}

std::vector <double> Segment::PntsCords(){
	std::vector <double> cords(4);
	cords[0] = a.getx();
	cords[1] = a.gety();
	cords[2] = b.getx();
	cords[3] = b.gety();
	return cords;
}

void Segment::Show(){
	std::cout << "[";
	a.Show();
	std::cout << " , ";
	b.Show();
	std::cout << "]";
}


//Definitions for methods of Triangle class
Triangle::Triangle( Point pnta, Point pntb, Point pntc ) : a( pnta ), b( pntb ), c( pntc ){
	try{
		if( Distance( pnta, pntb ) + Distance( pntb, pntc ) - Distance( pnta, pntc ) < 0.000001 ||
			Distance( pntb, pntc ) + Distance( pntc, pnta ) - Distance( pntc, pnta ) < 0.000001 ||
			Distance( pntb, pnta ) + Distance( pnta, pntc ) - Distance( pntb, pntc ) < 0.000001 )
				throw std::invalid_argument( "Every two sides of triangle have to be longer than the third\n");
	}catch( const std::invalid_argument &ia ){
		std::cerr << ia.what();
		pnta.~Point();
		pntb.~Point();
		pntc.~Point();
		this->~Triangle();}
}

Triangle::Triangle( const Triangle &tri ) : a( tri.a ), b( tri.b ), c( tri.c ) {}

double Triangle::Circuit(){ return Distance( a, b ) + Distance( b, c ) + Distance( c, a ); }

double Triangle::Field(){
	double p = this->Circuit() / 2;
	return sqrt( p * ( p - Distance( a, b) )
			* ( p - Distance( b, c) )
			* ( p - Distance( c, a) ) );
}

bool Triangle::PntInTri( Point pnt ){
	double s = 1 / ( 2 * this->Field() ), t = s;
	s *= a.gety() * c.getx() - a.getx() * c.gety() + ( c.gety() - a.gety()) * pnt.getx() + ( a.getx() - c.getx() ) * pnt.gety();
	t *= a.getx() * b.gety() - a.gety() * b.getx() + ( a.gety() - b.gety()) * pnt.getx() + ( b.getx() - a.getx() ) * pnt.gety();
	if( s > 0 && t > 0 && 1 - s - t > 0 ) return true;
	return false;
}

Point Triangle::Middle(){
	double x = (a.getx() + b.getx() + c.getx() ) / 3,
		y = ( a.gety() + b.gety() + c.gety() ) / 3;
	Point pnt(x,y);
	return pnt;
}
	
void Triangle::Move( double x, double y ){
	a.Move( x, y);
	b.Move( x, y);
	c.Move( x, y);
}

void Triangle::Turn( Point pnt, double angle ){
	a.Turn( pnt, angle );
	b.Turn( pnt, angle );
	c.Turn( pnt, angle );
}	

std::vector <Point> Triangle::Pnts(){
	std::vector <Point> pnts;
	pnts.push_back(Point(a));
	pnts.push_back(Point(b));
	pnts.push_back(Point(c)); 
	return pnts;
}

void Triangle::Show(){
	std::cout << "{ ";
	a.Show();
	std::cout << " , ";
	b.Show();
	std::cout << " , ";
	c.Show();
	std::cout << " }";
}
	
//Definitions of functions	
double Distance( Point pnta, Point pntb ){
	return sqrt( (pnta.getx() - pntb.getx()) * (pnta.getx() - pntb.getx()) +
			(pnta.gety() - pntb.gety()) * (pnta.gety() - pntb.gety()) );
}	

bool Parallel( Segment sega, Segment segb ){
	std::vector <double> cordsa = sega.PntsCords();
	std::vector <double> cordsb = segb.PntsCords();

	if( cordsa[0] - cordsa[2] == 0 || cordsb[0] - cordsb[2] == 0 )
		return cordsa[0] - cordsa[2] == cordsb[0] - cordsb[2];

	double slopea = ( cordsa[1] - cordsa[3] ) / ( cordsa[0] - cordsa[2] ),
		slopeb = ( cordsb[1] - cordsb[3] ) / ( cordsb[0] - cordsb[2] );
	
	return abs( slopea - slopeb ) < 0.000001;
}	

bool Perpendicular( Segment sega, Segment segb ){
	std::vector <double> cordsa = sega.PntsCords();
	std::vector <double> cordsb = segb.PntsCords();

	if( cordsa[0] - cordsa[2] == 0 || cordsb[0] - cordsb[2] == 0 ){
		if( cordsa[0] - cordsa[2] == 0 ) return cordsb[1] == cordsb[3];
		else return cordsa[1] == cordsa[3];
	}
	double slopea = ( cordsa[1] - cordsa[3] ) / ( cordsa[0] - cordsa[2] ),
		slopeb = ( cordsb[1] - cordsb[3] ) / ( cordsb[0] - cordsb[2] );
	
	return  1 - abs(slopea * slopeb) < 0.00000001;
}

static bool IfCross( Segment sega, Segment segb ){
	std::vector <double> a = sega.PntsCords(), b = segb.PntsCords();
	double t1, t2;
	double den = ( b[2] - b[0] ) * ( a[1] - a[3] ) - 
			( a[0] - a[2] ) * (b[3] * b[1]);

	t1 = ( b[1] - b[3] ) * ( a[0] - b[0] ) +
		( b[2] - b[0] ) * ( a[1] - b[1] );
	t2 = ( a[1] - a[3] ) * ( a[0] - b[0] ) +
		( a[2] - a[0] ) * ( a[1] - b[1] );

	if( den == 0 && ( sega.PntOnSeg( Point(b[0],b[2])) || sega.PntOnSeg( Point(b[1],b[3])) ) ) return true;	
	else if ( den == 0 ) return false;

	t1 /= den;
	t2 /= den;

	if( t1 > 1 || t1 < 0 || t2 > 1 || t2 < 0 ) return false; 
	return true;
}

bool Separated( Triangle tria, Triangle trib ){
	std::vector <Point> a = tria.Pnts(), b = trib.Pnts();
	std::vector <std::vector <Segment>> Segments (3);

	for( int i = 0 ; i < 3 ; i++ ){
		Segments[i].push_back(Segment{a[i%3], a[(i+1)%3]});
		Segments[i].push_back(Segment{b[i%3], b[(i+1)%3]});
	}
	for( int i = 0 ; i < 3 ; i++ )
		for( int j = 0 ; j < 3 ; j++ )
			if( IfCross( Segments[i][0], Segments[j][1] ) ) return false;

	return true;
}

static int CheckOrientation( Point a, Point b, Point c){
	double orientation = ( b.gety() - a.gety() ) * ( c.getx() - b.getx() ) -
		( b.getx() - a.getx() ) * ( c.gety() - b.gety() );
	if( orientation == 0.0 ) return 0;
	return orientation > 0.0 ? 1 : 2;	
}

bool TriInTri( Triangle tria, Triangle trib ){
	std::vector <Point> pntsa = tria.Pnts(), pntsb = trib.Pnts();
	int o[4];
	for( int i = 0 ; i < 3 ; i++ ){
		o[0] = CheckOrientation( pntsa[i], pntsa[(i+1)%3], pntsa[(i+2)%3] );
		o[1] = CheckOrientation( pntsa[i], pntsa[(i+1)%3], pntsb[0] );
		o[2] = CheckOrientation( pntsa[i], pntsa[(i+1)%3], pntsb[1] );
		o[3] = CheckOrientation( pntsa[i], pntsa[(i+1)%3], pntsb[2] );
		if( o[1] != o[0] || o[2] != o[0] || o[3] != o[0] ) return false;
	}
	return true;	
}


