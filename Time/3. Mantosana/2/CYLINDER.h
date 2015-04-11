#ifndef CYLINDER_H
#define CYLINDER_H

#include "circle.h"

class Cylinder: public Circle{
public:
   Cylinder(float,float,float,float,int);
   ~Cylinder();
   void setHeight(float);
   float getHeight() const;
   float area() const;
   float cVolume() const;
private:
   float height;
};

#endif
