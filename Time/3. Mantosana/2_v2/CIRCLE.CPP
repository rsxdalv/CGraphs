#include <iostream>
#include "circle.h"

Circle::Circle(float r, float a, float b, int IDa) : Point(a,b,IDa)
{
   //Circle konstruktoraa ir izsaukts Point konstriktors
   //Point konstruktors pieskir veertiibas centra koordinaateem
   radius=r; //Circle konstruktors pats apstraadaa tikai jauno parametru r
   std::cout<< "Rinka konstruktors (X:"<<a<<" Y:"<<b<<" Radius:"<<r<<" ID:"<<IDa<<")"<<std::endl;
}

Circle::~Circle()
{
   std::cout<< "Rinka destruktors (ID:"<<identy<<")"<<std::endl; 
}

void Circle::setRadius(float r)
{
   radius=r;
}

float Circle::getRadius() const
{
   return radius;
}

float Circle::area() const
{
   return 3.14159*radius*radius;
}
