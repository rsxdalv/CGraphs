#include <iostream>
#include "timeh.h"

using namespace std;

int main()
{
   Time t;
   cout << "Laiks ir: ";
   t.printTime();
   t.setTime(13, 27, 6);
   cout << endl << "Laiks ir: ";
   t.printTime();

   t.setTime(99, 99, 99);

   cout << endl << endl << "Peec nepareiza meeginaajuma: ";
   t.printTime();
   cout << endl << endl;
   system("PAUSE");	
   return 0;
}
