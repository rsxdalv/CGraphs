/* What's the difference between clock(), gettickcount(), QueryPerformanceCounter() 
and QueryPerformanceFrequency()?

clock
A C++ function. It returns the number of CPU ticks since the application is started. 
To convert this into seconds divide it by CLOCKS_PER_SEC.

GetTickCount
A Win32 API function. Returns the number of milliseconds since the system was started.

QueryPerformanceCounter
A Win32 API function. The performance counter is a high-resolution counter which increases over time. 
To convert this into seconds divide it by QueryPerformanceFrequency.


clock and GetTickCount have between 4 and 15 millisecond precision on most systems. QueryPerformanceCounter 
has a precision in the microsecond to nanosecond range.

clock is a wrapper around GetTickCount if you're using Microsoft's C runtime library, which, if you're 
using an MS compiler, you probably are. GetTickCount returns a value in milliseconds, but it doesn't 
increase by one millisecond after one millisecond has elapsed. It is only incremented when a system clock 
interrupt occurs, which is every four to 15 milliseconds - normally it's about 15ms, but it can be changed 
by applications. This affects the whole computer: it affects thread scheduling, and the overhead of more 
frequent interrupts also leaves less CPU time for actually running program code, so don't do it unless 
you really need it. If your computer is ticking more frequently than 15ms, some other application has 
modified the tick interrupt frequency.

QueryPerformanceCounter uses whatever high-resolution timers are available on the system. In the past, 
it was usually based on the processor's internal count of clock cycles, so would count at 2-3GHz, or 
about 0.5ns. Unfortunately some processors varied the rate that the counter would tick at when in 
low-power states, and in multi-CPU systems (i.e. with multiple processor sockets) you'd get problems 
if the CPUs weren't all the same speed. Windows now uses other more reliable sources, but they aren't 
quite as high resolution as the processor. QueryPerformanceFrequency tells you how many ticks occur in 
one second. To get milliseconds, multiply the difference of QPC samples by 1000, and divide by the result 
of QueryPerformanceFrequency.
*/


#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <assert.h>

#define SIZE 10000

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
   int a[SIZE];
   for(int i=0;i<SIZE;i++)
      a[i]=SIZE-i;
   double lastTime = GetPerfTime();
   
// sakums vietai kur jaliek kodu

   Isort(a,SIZE);
   
// beigas vietai kur jaliek kodu        

   double currTime = GetPerfTime();
   double deltaTime = max(0, currTime - lastTime);
   cout << deltaTime << endl;
   for(int i=0;i<100;i++)
   cout<<a[i];
   system("PAUSE");	
   return 0;
}
