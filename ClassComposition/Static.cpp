#include <iostream>

using namespace std;

class Point{
public:
   Point();
   int getX();
   int getY();
   void setX(int);
   void setY(int);
   int getCount();

private:
   int x;
   int y;
   static int count;
};

Point::Point()
{
    x=y=0;
    ++count;
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

int Point::getCount()
{
   return count;
}

int Point::count = 0;

int main()
{
   Point p1;
   cout << p1.getCount() << endl;
   Point p2;
   cout << p2.getCount() << endl;
   Point p3;
   Point p4;
   cout << p1.getCount() << endl;
   system("Pause");
   return 0;
}
