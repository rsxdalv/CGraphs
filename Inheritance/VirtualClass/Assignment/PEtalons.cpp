#include <iostream>
#include <string>
#include "PEtalons.h"
using namespace std;

PersonETalons::PersonETalons(string name1,string name2,int counted,float priced)
{
   if(priced>0) price=priced;
   if(count) count=counted;
   name="Person ET";
   vards=name1;
   uzvards=name2;
   times=0;
}

void PersonETalons::Print() const
{
   cout << "Nosaukums : " << name << " Cena :"<<price<<" Atlikums :"<<count<<" Izmantots :"<<times<<endl;
   cout << "Pieskirts : " << vards << " "<<uzvards<<endl;
}

bool PersonETalons::Use()
{
   if(count>0) {times++;count--;return true;}
   cout << "Nederigs!"<<endl;
   return false;
}

void PersonETalons::Add(unsigned int a)
{
   count+=a;
}   
