#ifndef CYLINDER_H
#define CYLINDER_H

#include "circle.h"

class Cylinder : public Circle {

public:
   Cylinder( float h=0.0, float r=0.0, float x=0.0, float y=0.0);
   ~Cylinder() {};
   void setHeight(float);
   float getHeight() const;
   virtual float area() const;
   virtual float volume() const;
   virtual void printShapeName() const {cout << "Cilindrs " << endl;}
   //identifikators virtual printShapeName() sajaa vietaa nav obligaats
   //jo funkcija vienreiz nodefineeta kaa tiiri virtuaala, palieka taada visaas atvasinaataas klasees
   //bet ieteicams likt so identifikatoru atkaartoti lai vienkaaarsi neaizmirst ka funkcija ir
   //tiiri virtuaala

private:
   float height;

};

#endif
