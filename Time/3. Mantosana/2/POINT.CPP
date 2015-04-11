#include <iostream>
#include "point.h"

Point::Point(float a, float b, int IDa)
{
   setPoint(a, b);
   identy=IDa;
   std::cout << "Punkta konststruktors (X:" << a << " Y:" << b <<" ID:"<<IDa<<")"<<std::endl;
}

Point::~Point()
{
   std::cout << "Punkta destruktors (ID:"<<identy<<")"<< std::endl;
}

void Point::setPoint(float a, float b)
{
   x=a;
   y=b;
}

float Point::getX() const
{
   return x;
}

float Point::getY() const
{
   return y;
}

