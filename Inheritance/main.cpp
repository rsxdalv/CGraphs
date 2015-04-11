#include <iostream>

#include "cilveks.h"
#include "skolens.h"
#include "students.h"
using namespace std;

void builder()
{
   Cilveks CI("Cilveks",   10,  19.5, 1); // Vards Uzvards, Vecums, Meneðbiïetes cena, ID;
   cout << endl;
   Skolens SK("Skolens",   16, 200.0, 10,   2); //  Vards Uzvards, Vecums, Meneðbiïetes cena, Meneðbiïetes atlaide %, ID;
   cout << endl;
   Students ST("Students",  22,    50, 67, 100, 3); // Vards Uzvards, Vecums, Meneðbiïetes cena, Meneðbiïetes atlaide, stipendija, ID;
   cout << endl;
   cout << "Cilveks -" <<" V/U:"<<CI.getName()<< " Vecums:"<<CI.getAge()<<" Menesbilete:"<<CI.getMBCena()<<" ID:"<<CI.ID<<endl;
   cout << "Skolens -" <<" V/U:"<<SK.getName()<< " Vecums:"<<SK.getAge()<<" Menesbilete:"<<SK.getMBCena()<<" Atlaide:"<<SK.getMBAtlaide()<<"%"<<" ID:"<<SK.ID<<endl;
   cout << "Students -" <<" V/U:"<<ST.getName()<< " Vecums:"<<ST.getAge()<<" Menesbilete:"<<ST.getMBCena()<<" Atlaide:"<<ST.getMBAtlaide()<<"%"<<" Stipendija:"<<ST.getStipend()<<" ID:"<<ST.ID<<endl;
   getchar();
}   

int main()
{ 
   builder();
   system("PAUSE");
   return 0;
}
