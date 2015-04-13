#include <iostream>
#include <string>
#include "DEtalons.h"
using namespace std;

DienETalons::DienETalons(float priced,bool usage)
{
   if(priced>0) price=priced;
   usable=usage;
   name="Diennakts ET";
   times=0;
}

void DienETalons::Print() const
{
   cout << "Nosaukums : " << name << " Cena :"<<price<<" Lietojams :"<<usable<<" Izmantots :"<<times<<endl;
}

bool DienETalons::Use()
{
   if(usable) {times++;return true;}
   cout << "Nederigs!"<<endl;
   return false;
}

void DienETalons::Used() {usable=!usable;}
