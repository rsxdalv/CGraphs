#include <iostream>
#include "point.h"
#include "circle.h"
#include "cylinder.h"

using namespace std;

void builder()
{
   Point p(10,10, 0);
   Circle c(15, 16, 17,1);
   Cylinder cc(10, 15, 13, 16, 2);
   cout << "Point:" << endl << "X=" << p.getX() << " Y=" << p.getY()
		<< endl;
   cout << "Circle:" << endl << "x=" << c.getX() << " Y=" << c.getY()
   	<< " R=" << c.getRadius() << endl;
  	cout << "Cylinder area:" << cc.area()<<endl;
  	//cout << "Cylinder volume:" << cc.cVolume()<<endl;
  	//getchar();
   //system("PAUSE");	
   //return 0;
   
}
/*
Cilveks
Vards Uzvards
Vecums - unsigned
Meneshbiletes cena -
Skolnieks
Vards Uzvards
Vecums - 7 < 16
Menesbiletes cena
Atlaide - %
Students
Vards Uzvards
Vecums - ??
Stipendija
Menesbiletes cena
Meneðbiletes cenas atlaide - %
*/
int main()
{
   builder();
   //Point p(10,10);
   //Circle c(15, 16, 17);
   //cout << "Point:" << endl << "X=" << p.getX() << " Y=" << p.getY()
	//	<< endl;
   //cout << "Circle:" << endl << "x=" << c.getX() << " Y=" << c.getY()
	//	<< " R=" << c.getRadius() << endl;
   system("PAUSE");	
   return 0;
}
