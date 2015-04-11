#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include "date.h"

using namespace std;

class Employee {

public:
   //Employee(char *, char *);//, int, int, int, int, int, int);
   Employee(string, string, int, int, int, int, int, int);

   void print() const;
   ~Employee();

private:
   string firstName;
   string lastName;
   //char firstName[ 25 ];
   //char lastName[ 25 ];
   Date birthDate;  // kompoziicija
   Date hireDate;   // kompoziicija

};

#endif
