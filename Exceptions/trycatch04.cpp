#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
   float n1, n2;
   float result;

   cout << "1.sk: ";
   cin >> n1;
   cout << "2.sk: ";
   cin >> n2;

   try
   {
     if (n2==0) throw 0;
     result=n1/n2;
     cout << endl << result << endl;
   }
   catch(int)
   {
      cout << "Divide by zero! " << endl;
   }
   
  system("PAUSE");	
  return 0;
}
