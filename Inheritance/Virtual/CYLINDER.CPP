#include <iostream>
#include "cylinder.h"

Cylinder::Cylinder( float h, float r, float x, float y)
   : Circle(r, x, y)
{
   height = h>0?h:0;
}

void Cylinder::setHeight(float h)
{
   height = h>0?h:0;
}

float Cylinder::area() const
{
   return 2*Circle::area() + 2*3.14159*Circle::getRadius() * height;
}

float Cylinder::volume() const
{
   return Circle::area() * height;
}
