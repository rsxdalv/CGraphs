#include <iostream>
#include <string>

#ifndef H_ETALONS
#define H_ETALONS

class ETalons
{
public:
   virtual ~ETalons() {};
   virtual bool Use() = 0;
   virtual void Print() const = 0;
protected:
   std::string name;
   float price;
   unsigned int times;
};

#endif
