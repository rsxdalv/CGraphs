#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
  char *a;
  try
  {
    a = new char[0xFFffFFFF];
  }
  catch(...) //ker jeb kadas kludas
  {
    cout << "Not enough memory:  " << endl;
    //kludas apstrade
    system("PAUSE");
    return 1;
  }
  cout << "No exception detected!" << endl;
  system("PAUSE");	
  return 0;
}
