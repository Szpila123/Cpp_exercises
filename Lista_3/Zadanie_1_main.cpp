#include <iostream>
#include <cmath>
#include <cstdlib>
#include "Zadanie_1_geo.h"
using namespace std;
int main(){
	Point a(0,0);

	//Point creation and printing
	cout << "Point \'a\' cords: ";
	a.Show();
	cout << endl;

	//Point moving
	a.Move( 1, 0 );
	cout << "Point \'a\' after moving with vector [1,0]: ";
	a.Show();
	cout << endl;

	//Point turning and creating from constructor (const Point& )
	a.Turn( Point(0,0), 90 );
	cout << "Point \'a\' after turning 90 degreese around (0,0): ";
	a.Show();
	cout << endl << endl;	

	
	//Segment creation and printing
	Segment sega( a, Point( 0, 0));
	cout << "Segment \'sega\' cords: ";
	sega.Show();
	cout << endl;

	//Creation of wrong segment:
	cout << "Creation a [( 0 , 0 ) , ( 0 , 0)] segment: ";
	Segment ( Point(0,0), Point(0,0) );

	//Segment lenght
	cout << "\'sega\' length is: " << sega.Lenght() << endl;

	//Checking if point is on segment
	cout << "Is point \'a\' on \'sega\'? " << (sega.PntOnSeg( a ) ? "true" : "false") << endl;
	cout << "Is point ( 1 , 1 ) on \'sega\'? " << (sega.PntOnSeg( Point(1,1)) ? "true" : "false") << endl;

	//Checking middle point of segment
	cout << "Middle point of \'sega\' is ";
	(sega.Middle()).Show();
	cout << endl;

	//Segment moving
	cout << "Moving \'sega\' with vector [2,1]: ";
	sega.Move( 2, 1);
	sega.Show();
	cout << endl;

	//Segment turning
	cout << "Turning \'sega\' 180 degrees around ( 2 , 1 ): ";
	sega.Turn( Point(2,1), 180 );
	sega.Show();
	cout << endl;

	//Checking where to segments cross
		//If they are crossing at all
	cout << "Crossing point of \'sega\' and [( 3 , 0 ) , ( 1 , 1)]: ";
	(sega.Cross( Segment( Point(3,0), Point(1,1) ) ) ).Show();
	cout << endl;
		//If they arent crossing at all
	cout << "Crossing point of \'sega\' and [( 10, 10 ) , ( 20 , 30 )]: ";
	sega.Cross( Segment( Point(10,10), Point(20,30)));

	//Checking if segment are parallel
	cout << "Are segments [( 1 , 1 ) , ( 2 , 2 )] and [( 4 , 4) , ( 8 , 8 )] parallel? "
		<< (Parallel( Segment( Point(1,1), Point(2,2)), Segment( Point(4,4), Point(8,8))) ? "true" : "false") << endl;
	cout << "Are segments [( 1 , 1 ) , ( 2 , 2 )] and [( 4 , 4) , ( 5 , 4 )] parallel? " 
		<< (Parallel( Segment( Point(1,1), Point(2,2)), Segment( Point(4,4), Point(5,4))) ? "true" : "false") << endl;
	
	//Checking if segments are perpendicular
	cout << "Are segments [( 1 , 1 ) , ( 2 , 2 )] and [( 2 , 2) , ( 3 , 1 )] perpendicular? "
		<< (Perpendicular( Segment( Point(1,1), Point(2,2)), Segment( Point(4,4), Point(8,8))) ? "true" : "false") << endl;
	cout << "Are segments [( 1 , 1 ) , ( 2 , 2 )] and [( 4 , 4) , ( 5 , 4 )] perpendicular? " 
		<< (Perpendicular( Segment( Point(1,1), Point(2,2)), Segment( Point(4,4), Point(5,4))) ? "true" : "false") << endl << endl << endl;

	
	//Craeting triangle
	cout << "Triangle \'tria\' coords: "; 	
	Triangle tria( Point(0,0), Point(3,0), Point(0,4));
	tria.Show();
	cout << endl;

	//Creating wrong triangle
	cout << "Trying to create triangle {( 0 , 0 ) , ( 1 , 1 ) , ( 2 , 2 )}: ";
	Triangle (Point(0,0), Point(1,1), Point(2,2));
	
	//Triangle circuit
	cout << "Triangle \'tria\' circuit is: " << tria.Circuit() << endl;

	//Triangle field
	cout << "Triangle \'tria\' field is: " << tria.Field() << endl;
	
	//Checking if point is in a triangle
	cout << "Is point ( 1 , 1 ) in \'tria\'? " << ( tria.PntInTri( Point(1,1) ) ? "true" : "false" ) << endl;
	cout << "Is point ( 4 , 4 ) in \'tria\'? " << ( tria.PntInTri( Point(4,4) ) ? "true" : "false" ) << endl;


	//Middle point of triangle
	cout << "Middle point of \'tria\' is : ";
	(tria.Middle()).Show();
	cout << endl;

	//Moving triangle
	cout << "Moving \'tria\' with vector [ 1 , 1 ]: ";
	tria.Move( 1, 1 );
	tria.Show();
	cout << endl;

	//Turning triangle
	cout << "Turning \'tria\' 90 degreese aroung point \'a\': ";
	tria.Turn( a, 90 );
	tria.Show();
	cout << endl;

	//Checking if triangles are separated
	cout << "Checking if \'tria\' and triangle {( 1 , 1 ) , ( -4 , 8 ) , ( 0 , 0 )} are separated: "
		<< (Separated( tria, Triangle( Point(1,1), Point(-4,8), Point(0,0))) ? "true" : "false" ) << endl;
	cout << "Checking if \'tria\' and triangle {( 0 , 0 ) , ( -4 , -1 ) , ( -5 , -2 )} are separated: "
		<< (Separated( tria, Triangle( Point(0,0), Point(-4,-1), Point(-5,-2))) ? "true" : "false" ) << endl;

	//Checking if triangles is inside another triangle
	cout << "Checking if \'tria\' has triangle {( -0.5 , 2.5 ) , ( -1 , 3 ) , ( -2 , 3 )} inside:"
		<< (TriInTri( tria, Triangle( Point(-0.5,2.5), Point(-1,3), Point(-2,3))) ? "true" : "false" ) << endl;
	cout << "Checking if \'tria\' has triangle {( 0 , 0 ) , ( -4 , -1 ) , ( -5 , -2 )} inside:"
		<< (TriInTri( tria, Triangle( Point(0,0), Point(-4,-1), Point(-5,-2))) ? "true" : "false" ) << endl;
	return 0;
}

