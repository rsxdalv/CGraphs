#include <iostream.h>
#include "point.h"

Point::Point(float a, float b)
{
   setPoint(a, b);
}

Point::~Point()
{
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

