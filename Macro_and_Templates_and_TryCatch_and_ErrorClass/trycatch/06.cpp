#include <iostream>
#include <stdlib.h>

using namespace std;

class DivideByZeroError
{
   public:
      DivideByZeroError(){};
      void printMessage() {cout<<"Daliisana uz 0";};
};

float dalisana (int num1, int num2)
{
   DivideByZeroError dbe;
   if (num2==0)
      throw dbe;
   return float(num1/num2);
}

int main()
{
   int n1, n2, x=0;
   float result;
   cout << "1.sk: ";
   cin >> n1;
   cout << "2.sk: ";
   cin >> n2;

   try
   {
     float result = dalisana(n1, n2);
     cout << "Rezultaats: " << result << endl;
   }
   catch(DivideByZeroError error)
   {
      cout << "Kluuda: ";
      error.printMessage();
      cout << endl;
      system("PAUSE");	
      return 1;
   };
   
  system("PAUSE");	
  return 0;
}

