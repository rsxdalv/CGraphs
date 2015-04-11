#include <string>
#ifndef CILVEKS_H
#define CILVEKS_H

class Cilveks
{
public:
   Cilveks(std::string,unsigned int, float, int);
   ~Cilveks();
   void setName(std::string);
   std::string getName() const;
   void setAge(unsigned int);
   unsigned int getAge() const;
   void setMBCena(float);
   float getMBCena() const;
   int ID; 
private:
   std::string VdsUzv;
   unsigned int Vecums;
   float MBCena;
};
#endif
