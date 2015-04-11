#include <iostream>
#include <string>
#include "employee.h"
#include "date.h"

using namespace std;
  
Employee::Employee(//char *first, char *last, int bd, int bm, int by, int hd, int hm, int hy )),
                   string first, string last, int bd, int bm, int by, int hd, int hm, int hy )
   : birthDate(bd, bm, by),  // birthDate inicializaacija
     hireDate(hd, hm, hy)    // hireDateba inicializaacija
{

   //int length = strlen( first );
   //length = ( length < 25 ? length : 24 );
   //strncpy( firstName, first, length );
   //firstName[ length ] = '\0';

   //length = strlen( last );
   //length = ( length < 25 ? length : 24 );
   //strncpy( lastName, last, length );
   //lastName[ length ] = '\0';

   firstName = first;
   lastName = last;

   cout << "Employee konstruktors: "
        << firstName << ' ' << lastName << endl;
}


void Employee::print() const
{
   cout << lastName << ", " << firstName << endl << "Pienemts uz darbu: ";
   hireDate.print();
   cout << "  Dzimsanas datums: ";
   birthDate.print();
   cout << endl;
}

Employee::~Employee()
{ 
   cout << "Employee destruktors: " 
        << lastName << ", " << firstName << endl;
}
