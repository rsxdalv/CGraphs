#include <iostream>
#include "point.h"

using namespace std;

int main()
{
   Point p(10,10);
   cout << "Point:" << endl << "x=" << p.getX() << " y=" << p.getY()
		<< endl;
  system("PAUSE");	
  return 0;
}
