#include <iostream>
#include <stdlib.h>

using namespace std;

template <class Type>
Type min2( Type a, Type b ) 
{ 
   return a < b ? a : b;
}

int main() 
{
   cout << min2(10, 20) << endl;
   cout << min2(10.0, 20.0) << endl;
   cout << min2('s','d') << endl;
   system("PAUSE");	
   return 0;
}
