#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include "point.h"

class Circle : public Point {
public:
   Circle(float r = 0.0, float x = 0, float y = 0);
   ~Circle() {};
   void setRadius(float);
   float getRadius() const;
   float area() const;
   virtual void printShapeName() const {cout << "Aplis " << endl;}
   //identifikators virtual printShapeName() sajaa vietaa nav obligaats
   //jo funkcija vienreiz nodefineeta kaa tiiri virtuaala, palieka taada visaas atvasinaataas klasees
   //bet ieteicams likt so identifikatoru atkaartoti lai vienkaaarsi neaizmirst ka funkcija ir
   //tiiri virtuaala
protected:
   float radius;
};

#endif
