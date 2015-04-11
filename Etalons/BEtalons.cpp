#include <iostream>
#include <string>
#include "BEtalons.h"
using namespace std;

MultiETalons::MultiETalons(float priced,unsigned int counted)
{
   if(priced>0) price=priced;
   if(count) count=counted;
   name="Multi ET";
   times=0;
}

void MultiETalons::Print() const
{
   cout << "Nosaukums : " << name << " Cena :"<<price<<" Atlikums :"<<count<<" Izmantots :"<<times<<endl;
}

bool MultiETalons::Use()
{
   if(count>0) {times++;count--;return true;}
   cout << "Nederigs!"<<endl;
   return false;
}
