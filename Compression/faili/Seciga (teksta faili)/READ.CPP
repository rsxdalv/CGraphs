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
   fails.close();

   cout << "a=" << a;
   system("Pause");
   return 0;
}
