#include <iostream>
#include <string>
#include "Etalons.h"

#ifndef DEtalons_H
#define DEtalons_H

class DienETalons: public ETalons
{
public:
   DienETalons(float=1.50,bool=true);
   ~DienETalons() {};
   void Used();
   virtual bool Use();
   virtual void Print() const;
private:
   bool usable;
};

#endif
