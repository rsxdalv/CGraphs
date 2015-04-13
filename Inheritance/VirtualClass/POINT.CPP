#include <iostream>
#include "point.h"

Point::Point(float a, float b)
{
   setPoint(a,b);
}

void Point::setPoint(float a, float b)
{
   x=a;
   y=b;
}

