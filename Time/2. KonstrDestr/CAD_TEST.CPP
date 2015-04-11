#include <iostream>
#include "create.h"

using namespace std;

void create();  //prototips

CreateAndDestroy first(1);  //globaalais objekts

int main()
{
   cout << "   (globaalais, izveidots pirms main())" << endl;
   CreateAndDestroy second(2);
   cout << "   (lokaalais, no main())" << endl;
   create();
   CreateAndDestroy third(3);
   cout << "   (lokaalais, no main())" << endl;
   system("PAUSE");	
   return 0;
}

void create()
{
   CreateAndDestroy fourth(4);
   cout << "   (lokaalais, no create())" << endl;
   CreateAndDestroy fifth(5);
   cout << "   (lokaalais, no create())" << endl;
}
