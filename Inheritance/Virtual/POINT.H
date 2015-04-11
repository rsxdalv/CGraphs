#ifndef POINT_H
#define POINT_H

#include "shape.h"

using namespace std;

class Point : public Shape
{
public:
   Point (float=0, float=0);
   ~Point() {};
   void setPoint(float, float);
   float getX() const {return x;}
   float getY() const {return y;}
   virtual void printShapeName() const {cout << "Punkts " << endl;}
   //identifikators virtual printShapeName() sajaa vietaa nav obligaats
   //jo funkcija vienreiz nodefineeta kaa tiiri virtuaala, palieka taada visaas atvasinaataas klasees
   //bet ieteicams likt so identifikatoru atkaartoti lai vienkaaarsi neaizmirst ka funkcija ir
   //tiiri virtuaala
private:
   float x,y;
};
#endif
