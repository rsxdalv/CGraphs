#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <assert.h>

#define size 10000

using namespace std;

static __int64 gCountsPerSecond;


double max(double a, double b)
{
    if (a>b) return a;
    else return b;
}

void InitPerfTimer()
{
bool exists = QueryPerformanceFrequency((LARGE_INTEGER*)&gCountsPerSecond)!=0;
assert(exists);
}

double GetPerfTime()
{
__int64 numCounts;
QueryPerformanceCounter((LARGE_INTEGER*)&numCounts);
return (double)numCounts / (double)gCountsPerSecond; 
//parveido uz sekundem un atgriez rezultatu
}

int * Bsort(int a[], int _size)
{
   for(int k=0;k<_size-1;k++)
   {
       for(int m=k+1;m<_size;m++)
       {
           if(a[k]>a[m])
           {
               int t=a[k];
               a[k]=a[m];
               a[m]=t;
           }
       }
   }
}    

int * Ssort(int a[],int _size)
{
    int min,x,y;//,siz;
    for(int b=0;b<_size;b++)
    {
        min=a[b];
        //siz=_size-b;
        for(x=b;x<_size;x++)
        {
            if(a[x]<min) {min=a[x];y=x;}
        }    
        a[y]=a[b];
        a[b]=min;
        //cout << endl<<min<<" "<<a[x]<<x<<b;
    }    
}    

int * Isort(int a[],int _size)
{
    int elem,ind;//,k;
    for(int b=1;b<_size;b++)
    {
        ind=b;
        while(a[--ind]>a[b]&&ind>=0){
            ind++;
            elem=a[ind];
            a[ind]=a[ind+1];
            a[ind+1]=elem;
        }
        //ind++;
        //elem=a[b];
        //a[b]=a[ind];
        //a[ind]=elem;
        
        //cout <<endl<< ind<<endl;
        // 10 42 12 54
    }    
}    


int main(int argc, char *argv[])
{
  
   InitPerfTimer();
   int a[size];
   for(int i=0;i<size;i++)
      a[i]=size-i;
   double lastTime = GetPerfTime();
   
// sakums vietai kur jaliek kodu

   Isort(a,size);
   
// beigas vietai kur jaliek kodu        

   double currTime = GetPerfTime();
   double deltaTime = max(0, currTime - lastTime);
   cout << deltaTime << endl;
   for(int i=0;i<100;i++)
   cout<<a[i];
   system("PAUSE");	
   return 0;
}
