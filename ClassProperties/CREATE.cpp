#include <iostream>
#include "create.h"

using namespace std;

CreateAndDestroy::CreateAndDestroy(int value)
{
   data = value;
   cout << "Objekts " << data << " konstruktors";
}

CreateAndDestroy::~CreateAndDestroy()
{
   cout << "Objekts " << data << " destruktors" << endl;
}
