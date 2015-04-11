#ifndef CIRCLE_H
#define CIRCLE_H

#include "point.h"

class Circle : public Point {
public:
   Circle(float, float, float, int);
   ~Circle();
   void setRadius(float);
   float getRadius() const;
   float area() const;
private:
   float radius;
};

#endif
