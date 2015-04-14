#include <iostream>
#include "employee.h"
#include "date.h"

using namespace std;

int main()
{
   Employee manager("Bob", "Jones", 7, 24, 1949, 3, 12, 1988);
   cout << endl;
   manager.print();
   cout << endl << "Date Tests konstruktors ar nepareizaam veertiibaam" << endl;
   Date kluda( 35, 31, 1994 );
   cout << endl;

   system("PAUSE");	
   return 0;
}
