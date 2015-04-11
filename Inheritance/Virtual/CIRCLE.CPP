#include <iostream>
#include "circle.h"

Circle::Circle(float r, float a, float b) : Point(a,b)
{
   radius=r>0?r:0;
}

void Circle::setRadius(float r)
{
   radius=r>0?r:0;
}

float Circle::getRadius() const
{
   return radius;
}


float Circle::area() const
{
   return 3.14159*radius*radius;
}
