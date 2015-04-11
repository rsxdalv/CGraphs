#include <iostream>
#include "skolens.h"

Skolens::Skolens(char vu, unsigned int v, float mbc, float mbp, int id) : Cilveks(vu,v,mbc,id)
{
   setAge(v);
   setMBAtlaide(mbp);
   std::cout << "Skolena konstruktors [ID:"<<id<<"]"<<std::endl;
}
Skolens::~Skolens()
{
   std::cout << "Skolena destruktors [ID:"<<ID<<"]"<< std::endl;
}
void Skolens::setAge(unsigned int v)
{
   if(v<7) Cilveks::setAge(0);
   else if(v>16) Cilveks::setAge(0);
   else Cilveks::setAge(v);
}
void Skolens::setMBAtlaide(float pc)
{
    Percent=pc/100;
}
float Skolens::getMBAtlaide() const
{
    return Percent*100;
}
float Skolens::getMBCena() const
{
    return Cilveks::getMBCena()*(1-Percent);
}
