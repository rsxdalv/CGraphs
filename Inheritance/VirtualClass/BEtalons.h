#include <iostream>
#include <string>
#include "Etalons.h"

#ifndef BETALONS_H
#define BETALONS_H

class MultiETalons: public ETalons
{
public:
   MultiETalons(float=1.5,unsigned int=4);
   ~MultiETalons() {};
   virtual bool Use();
   virtual void Print() const;
private:
   unsigned int count;
}; 

#endif
