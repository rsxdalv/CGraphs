#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
  try
  {
    throw 1;
    throw 'a';
  }
  catch(int a)
  {
    cout << "Caught int exception:  " << a << endl;
    system("PAUSE");
    return 1;
  }
  catch(char b)
  {
    cout << "Caught char exception:  " << b << endl;
    system("PAUSE");
    return 1;
  }
  cout << "No exception detected!" << endl;
  system("PAUSE");	
  return 0;
}
