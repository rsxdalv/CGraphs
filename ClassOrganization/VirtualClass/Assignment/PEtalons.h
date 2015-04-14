#include <iostream>
#include <string>
#include "Etalons.h"

#ifndef PETALONS_H
#define PETALONS_H

class PersonETalons: public ETalons
{
public:
   PersonETalons(std::string,std::string,int=5,float=2.0);
   ~PersonETalons() {};
   void Add(unsigned int=1);
   virtual bool Use();
   virtual void Print() const;
private:
   std::string vards;
   std::string uzvards;
   unsigned int count;
};

#endif
