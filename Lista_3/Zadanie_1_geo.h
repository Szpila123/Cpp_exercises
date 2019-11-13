#ifndef geo_h
#define geo_h
#include <vector>
class Point{
	private:
		double x, y;
	public:
		Point( double xv, double yv );
		Point( const Point &pnt );
		void Move( double x, double y );
		void Turn( Point pnt, double angle );
		double getx(){ return x; }
		double gety(){ return y; }
		void Show();
};	

class Segment{
	private:
		Point a, b;
	public:
		Segment( Point pnta, Point pntb );
		Segment( const Segment &seg ); 
		double Lenght();
		bool PntOnSeg( Point pnt );
		Point Middle();
		void Move( double x, double y );
		void Turn( Point pnt, double angle );
		Point Cross( Segment seg );
		std::vector <double> PntsCords();
		void Show();
};




class Triangle{
	private:
		Point a, b, c;
	public:	
		Triangle( Point pnta, Point pntb, Point pntc );
		Triangle( const Triangle &tri );
		double Circuit();
		double Field();
		bool PntInTri( Point pnta );
		Point Middle();
		void Move( double x, double y );
		void Turn( Point pnt, double angle );
		std::vector <Point> Pnts(); 
		void Show();
};

//Funcions for points	
double Distance( Point pnta, Point pntb );

//Functions for segments
bool Parallel( Segment sega, Segment segb );
bool Perpendicular( Segment sega, Segment segb );

//Functions for triangles
bool Separated( Triangle tria, Triangle trib );
bool TriInTri( Triangle tria, Triangle trib );


#endif
