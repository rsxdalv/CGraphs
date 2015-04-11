#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
  try
  {
    throw 1;
    cout << "Invisible text :)";
  }
  catch(int a)
  {
    cout << "Caught exception number:  " << a << endl;
    system("PAUSE");
    return 1;
  }
  cout << "No exception detected!" << endl;
  system("PAUSE");	
  return 0;
}
