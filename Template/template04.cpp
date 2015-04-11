#include <iostream> 
#include <stdlib.h> 

using namespace std;

template<class T, class T1> 
class array 
{ 
public: 
   array(int size); 
   T1 sum(); 
   T average_value(); 
   void show_array(); 
   int add_value(T); 
private: 
   T *data; 
   int size; 
   int index; 
}; 

template<class T, class T1> 
array<T, T1>::array(int s) 
{ 
   data = new T[s]; 
   if (data == NULL) 

   { 
      cout << "Pietruukst atminas, programma beidzaas." << endl; 
      exit(1); 
   } 

   size = s; 
   index = 0; 
} 

template<class T, class T1>
T1 array<T, T1>::sum() 
{ 
   T1 sum = 0; 
   for (int i = 0; i < index; i++) sum += data[i]; 
   return(sum); 
} 

template<class T, class T1> 
T array<T, T1>::average_value() 
{ 
   T1 sum =0; 
   for (int i = 0; i < index; i++) sum += data[i]; 
   return (sum / index); 
} 

template<class T, class T1> 
void array<T, T1>::show_array() 
{ 
   for (int i = 0; i < index; i++) cout << data[i] << ' '; 
   cout << endl; 
} 

template<class T, class T1> 
int array<T, T1>::add_value(T value) 
{ 
   if (index == size) 
   return(1); // masivs pilns 
   else 

   { 
      data[index] = value; 
      index++; 
      return(0);
   } 
} 

int main() 
{ 
   array<int, long> numbers(100); 
   array<float, float> values(200); 
   int i; 
   
   for (i = 0; i < 50; i++) 
      numbers.add_value(i); 
   numbers.show_array(); 
   cout << "Skaitlu summa: " << numbers.sum () << endl; 
   cout << "Videjais: " << numbers.average_value() << endl; 
   
   for (i = 0; i < 100; i++) 
      values.add_value(i * 1.1); 
   values.show_array(); 
   cout << "Skaitlu summa: " << values.sum() << endl; 
   cout << "Videjais: " << values.average_value() << endl; 
   
   system("PAUSE");	
   return 0;
}
