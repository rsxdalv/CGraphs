#include <iostream>
#include "cylinder.h"

Cylinder::Cylinder(float h, float r, float a, float b, int IDa) : Circle(r,a,b,IDa)
{
   height=h;
   std::cout<< "Cilindra konstruktors (X:"<<a<<" Y:"<<b<<" Radius:"<<r<<" Augstums:"<<h<<" ID:"<<IDa<<")"<<std::endl;
}
Cylinder::~Cylinder()
{
   std::cout<< "Cilindra destruktors (ID:"<<identy<<")"<<std::endl;
}
void Cylinder::setHeight(float h)
{
   height=h;
}
float Cylinder::getHeight() const
{
   return height;
}
float Cylinder::area() const
{
   return Circle::area()*2+getRadius()*3.14159*height;
}
float Cylinder::cVolume() const 
{
   return area()*height;
}
