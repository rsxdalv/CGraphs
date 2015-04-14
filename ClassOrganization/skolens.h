#include <string>
#ifndef SKOLENS_H
#define SKOLENS_H

#include "cilveks.h"

class Skolens : public Cilveks {
public:
   Skolens(std::string, unsigned int, float, float, int);
   ~Skolens();
   void setAge(unsigned int);
   void setMBAtlaide(float);
   float getMBAtlaide() const;
   float getMBCena() const;
private:
   float Percent;
};
#endif
