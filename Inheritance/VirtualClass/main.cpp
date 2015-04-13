#include <iostream>
#include "shape.h"
#include "point.h"
#include "circle.h"
#include "cylinder.h"

using namespace std;

int main()
{
   //Shape shape; //abstrakta klase - nevar veidot objektus
   Point point(7, 11);
   Circle circle(3.5, 22, 8);
   Cylinder cylinder(10, 3.3, 10, 10);

   point.printShapeName();
   circle.printShapeName();
   cylinder.printShapeName();
   cout << endl;

   Shape *arrayOfShapes[3];
   arrayOfShapes[0] = &point;
   arrayOfShapes[1] = &circle;
   arrayOfShapes[2] = &cylinder;

   for (int i=0; i<3; i++)
   {
      arrayOfShapes[i]->printShapeName();
      cout<<arrayOfShapes[i]->getX()<<" "<<arrayOfShapes[i]->getY()<<endl;
      cout << "Laukums: " << arrayOfShapes[i]->area() << endl;
      cout << "Tilpums: " << arrayOfShapes[i]->volume() << endl << endl;
   }
  system("PAUSE");	
  return 0;
}
