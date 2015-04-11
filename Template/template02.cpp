#include <iostream>
#include <stdlib.h>

using namespace std;

template<class T>
void printArray(T *array, const int count)
{
   for (int i=0; i<count; i++)
      cout << array[i] << " ";
   cout << endl;
}

int main()
{
   const int x=5, y=6, z=7;
   int a[x] = {1,2,3,4,5};
   float b[y] = {1.1,2.2,3.3,4.4,5.5,6.6};
   char c[z] = "Hello!";// 7 pozicija simbolam '\0'

   printArray(a, x);
   printArray(b, y);
   printArray(c, z);
   
   system("PAUSE");	
   return 0;
}
