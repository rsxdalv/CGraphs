#include <iostream>

using namespace std;


class Test
{
   public:
      Test (int = 10); //defolta konstruktors
      int getData();

   private:
      int data;
};

Test::Test(int x)
{
   data = x;
}

int Test::getData()
{
   return data;
}


int main()
{
   int *ptr1;
   cout << *ptr1 << endl;
   cout << ptr1 << endl;
   ptr1 = new int(5);
   cout << *ptr1 << endl;
   cout << ptr1 << endl;
   delete ptr1;
   cout << *ptr1 << endl;
   *ptr1=10;
   cout << *ptr1 << endl;
   system("Pause");
      
   int *ptr2;
   ptr2 = new int[3];
   //ptr2[-1]=0;
   ptr2[0]=1;
   ptr2[1]=2;
   ptr2[2]=3;
   ptr2[3]=5;
   //*(ptr2+3)=4;
   cout << ptr2[0] << ptr2[1]<< ptr2[2] << ptr2[3] << endl;
   cout << ptr2[0] << ptr2[1]<< ptr2[2] << endl;
   delete [] ptr2;
   cout << ptr2[0] << ptr2[1]<< ptr2[2] << endl << endl;
   system("Pause");
   
   Test *ptr3;
   ptr3 = new Test(25);
   cout << ptr3->getData() << endl;
   delete ptr3;
   cout << ptr3->getData() << endl;
   system("Pause");
   
   return 0;
}
