#include <iostream>

using namespace std;

class Point
{
    
   friend ostream &operator<<(ostream &, const Point &);
   //friend void operator<<(ostream &, const Point &);
   friend istream &operator>>(istream &, Point &);
    
public:
   Point();
   ~Point();
   void setX(int);
   void setY(int);
   int getX() const;
   int getY() const;
   Point operator=(Point);
   Point operator++(); //prefiksa (++x)
   Point operator++(int); //postfiksa (x++)

private:
   int X;
   int Y;
   int ID;
   static int Counter;
};

Point::Point()
{
   ID=Counter++;
   cout << " _A " << *this << ID << endl;
}
Point::~Point()
{
   cout << " _B " << ID << endl;
}   

int Point::Counter = 0;

void Point::setX(int x)
{
    X=x;
}

void Point::setY(int y)
{
    Y=y;
}

int Point::getX() const
{
   return X;
}

int Point::getY() const
{
   return Y;
}

Point Point::operator=(Point p)
{
   X=p.X;
   Y=p.Y;
   return *this;
}

ostream &operator<<(ostream &output, const Point &p)
//void operator<<(ostream &output, const Point &p)
{
   output << "x=" << p.X << ", y=" << p.Y ;
   return output;
}

istream &operator>>(istream &input, Point &p)
{
   input >> p.X >> p.Y;
   return input;
}

Point Point::operator++()
{
    X++;
    Y++;
    return *this;
}
    
Point Point::operator++(int)
{
    Point temp = *this;
    X++;
    Y++;
    return temp;
}
    

int main()
{
   Point p1, p2;
   
   p1.setY(5);
   p1.setX(3);
   
   p2.setY(7);
   p2.setX(8);
   
   cout << "p1: " << p1.getX() << " " << p1.getY() << endl;
   cout << "p2: " << p2.getX() << " " << p2.getY() << endl << endl;
   
   
//////////////////////////////////////////////////////////////////////////
//pieskirsanas paarbaude   
   p1=p2;
   p2=p1;
   
   cout << "p1: " << p1.getX() << " " << p1.getY() << endl;
   cout << "p2: " << p2.getX() << " " << p2.getY() << endl;
   
   system("PAUSE");
   
   
//////////////////////////////////////////////////////////////////////////
//++ paarbaude 
   cout << endl;
   Point tests;
   tests = p1++;
   cout << "tests pec p1++: " << tests.getX() << " " << tests.getY() << endl;
   tests = ++p2;
   cout << "tests pec ++p2: " << tests.getX() << " " << tests.getY() << endl;
   
   system("PAUSE");
   
   
////////////////////////////////////////////////////////////////////////// 
//ievades un izvades paarbaude 
   cout << endl;
   cout << "Ievadiet pirmo punktu:" << endl;
   cin >> p1;
   cout << "Ievadiet otro punktu:" << endl;
   cin >> p2;
   cout << endl;
   
   cout << p1 << endl << p2 << endl << endl;
   //cout << p1;
   
   p1=p2; 
   cout << p1 << endl << p2 << endl;
   
   system("PAUSE"); 
   return 0;
}
