#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
public:
   virtual ~Shape() {};
   //destruktoram jaabuut virtuaalam lai atvasinaataas klasees tiktu izsaukti
   //atvasinaatas klases destruktori, nevis pamatklases destruktors.
   //iipasi tas ir svariigi ja destruktoraa ir delete komanda!!!
   virtual float getX() const {return 0.0;}
   virtual float getY() const {return 0.0;}
   virtual float area() const {return 0.0;}
   virtual float volume() const {return 0.0;}
   virtual void printShapeName() const = 0; //tiira virtuaala funkcija
   //tiira virtuaala funkcija - taada kurai keermenis nodefineets kaa 0
   
   //ja klasee ir kaut viena tiiri virtuaala funkcija klase arii skaitaas par virtuaalo
   //virtuaalai klasei nevar veidot objektus!!!
};

#endif
