#include <iostream> 
#include <stdlib.h> 

using namespace std;

#define Swap(a,b) {int c=b; b=a; a=c;}

#define SwapUnify(a,b,t) \
		{                \
		   t temp=a;     \
		   a=b;          \
		   b=temp;       \
		}

#define Max 10
#define For_Each for(int i = 0; i < Max; i++)

int main()
{
   int x = 5, y = 10;
   float n = 5.5, m = 6.6;
   int a[Max];

   Swap(x,y);
   cout << "x=" << x << " y=" << y << endl;
   SwapUnify(n,m,float);
   cout << "n=" << n << " m=" << m << endl;

   For_Each
   {
	  cout << i << " ";
   }
   cout << endl;

   system("PAUSE");	
   return 0;
}
