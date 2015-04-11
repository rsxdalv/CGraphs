#include <iostream>

using namespace std;

class Point{
public:
   Point();
   int getX();
   int getY();
   Point &setX(int);
   Point &setY(int);

private:
   int x;
   int y;
};

Point::Point()
{
    x=y=0;
}    

Point &Point::setX(int a)
{
   x=a;
   return *this;
}

Point &Point::setY(int b)
{
   y=b;
   return *this;
}

int Point::getY()
{
   return y;
}

int Point::getX()
{
   return x;
}


int main()
{
   Point p1;
   p1.setX(2).setY(5);
   Point p2;
   p2.setY(8).setX(9);
   cout << p1.getX() << " " << p1.getY() << endl;
   cout << p2.getX() << " " << p2.getY() << endl;
   system("Pause");
   return 0;
}
