#include <iostream.h>
#include <fstream.h>
#include <conio.h>

int main()
{
   int a;
   cout << "Ievadiet a: ";
   cin >> a;

   ofstream fin;
   fin.open("fails.txt", ios::app);
   fin << a << " ";
   fin.close();
   return 0;
}
