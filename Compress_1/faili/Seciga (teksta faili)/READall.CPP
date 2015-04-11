#include <iostream.h>
#include <fstream.h>
#include <conio.h>

int main()
{
   int a;
   cout << "Lasu no faila... ";

   ifstream fails;
   fails.open("fails.txt");
   fails >> a;
   while(!fails.eof())
   {
      cout << "a=" << a << endl;
      fails >> a;
   }  
   fails.close(); 
   system("Pause");
   return 0;
}
