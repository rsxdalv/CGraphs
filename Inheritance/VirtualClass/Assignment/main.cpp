#include <iostream>
#include <string>
using namespace std;

#include "Etalons.h"
#include "DEtalons.h"
#include "BEtalons.h"
#include "PEtalons.h"

int main()
{
   DienETalons Etalons1;
   MultiETalons Etalons2(1.1,3);
   PersonETalons Etalons3("Janis","Juris",1,1.5);
   ETalons *KopEtalons[3];
   KopEtalons[0]=&Etalons1;
   KopEtalons[1]=&Etalons2;
   KopEtalons[2]=&Etalons3;
   Etalons1.Used();
   Etalons1.Print();
   Etalons2.Use();
   Etalons2.Use();
   Etalons2.Print();
   Etalons3.Print();
   Etalons1.Used();
   Etalons3.Add(1);
   Etalons3.Add(1);
   Etalons3.Add(2);
   Etalons3.Use();
   Etalons3.Use();
   Etalons3.Use();
   cout<<endl<<endl;
   for(int a=0;a<3;a++)
   {
      for(int b=0;b<5;b++){
      KopEtalons[a]->Print();
      KopEtalons[a]->Use();}
   }   
   //KopEtalons[0] = &Etalons1;
   cout<<endl<<endl;
   system("PAUSE");
   return 1;
}   
