#include <iostream>

using namespace std;

class Point{
   friend void CanSetX(Point &, int);

public:
   Point();
   void setX(int);
   void setY(int);
   int getX();
   int getY();

private:
   int x;
   int y;
};


Point::Point()
{
   x=y=0;
}

void Point::setX(int a)
{
   x=a;
}

void Point::setY(int b)
{
   y=b;
}

int Point::getY()
{
   return y;
}

int Point::getX()
{
   return x;
}
/////////////////////////////////////////////////
//Taas nav klases Point funkcijas!!!
void CanSetX(Point &pnt, int a)
{
   pnt.x=a;
}

void CanNotSetX(Point &pnt, int a)
{
//   pnt.x=a;
}
/////////////////////////////////////////////////

int main()
{
   Point p;
   p.setX(5);
   p.setY(2);
   cout << p.getX() << " " << p.getY() << endl;
   CanSetX(p, 3);
   cout << p.getX() << " " << p.getY() << endl;
   //CanNotSetX(p, 1);
   cout << p.getX() << " " << p.getY() << endl;
   system("Pause");
   return 0;
}
