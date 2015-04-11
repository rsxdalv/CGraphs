#include <iostream>

#include "students.h"

Students::Students(char vu, unsigned int v, float mbc, float mbp, float stp, int id) : Skolens(vu,v,mbc,mbp,id)
{
   setAge(v);
   setStipend(stp);
   std::cout << "Studenta konstruktors [ID:"<<id<<"]"<<std::endl;
}
Students::~Students()
{
   std::cout << "Studenta destruktors [ID:"<<ID<<"]"<<std::endl;
}
void Students::setAge(unsigned int v)
{
   if(v<19) Cilveks::setAge(0);
   else if(v>37) Cilveks::setAge(0);
   else Cilveks::setAge(v);
}
void Students::setStipend(float s)
{
   if(Stipend<0) Stipend=0;
   else Stipend=s;
}

float Students::getStipend() const
{
   return Stipend;
}
