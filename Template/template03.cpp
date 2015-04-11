#include <iostream> 
#include <stdlib.h> 

using namespace std;

class array 
{ 
public: 
   array(int size); 
   long sum(); 
   int average_value(); 
   void show_array(); 
   int add_value(int) ; 
private: 
   int *data; 
   int size; 
   int index; 
}; 

array::array(int s) 

{ 
   data = new int [s]; 
   if (data == NULL) 

   { 
      cout << "Pietruukst atminas, programma beidzaas." << endl; 
      exit(1); 
   } 

   size = s; 
   index = 0; 
} 

long array::sum() 

{ 
   long sum = 0; 
   for (int i = 0; i < index; i++) sum += data[i]; 
   return(sum); 
} 

int array::average_value() 

{ 
   long sum = 0; 
   for (int i = 0; i < index; i++) sum += data[i]; 
   return (sum / index); 
} 

void array::show_array() 

{ 
   for (int i = 0; i < index; i++) cout << data[i] << ' '; 
   cout << endl; 
} 

int array::add_value(int value) 

{ 
   if (index == size) return(1); // masivs pilns 
   else 

   { 
      data[index] = value; 
      index++; 
      return(0);
   } 
} 

int main(int) 

{ 
   array numbers (100);
   int i; 
   for (i = 0; i < 50; i++) numbers.add_value(i); 
   numbers.show_array(); 
   cout << "Skaitlu summa: " << numbers.sum () << endl; 
   cout << "Videjais: " << numbers.average_value() << endl; 
      
   system("PAUSE");	
   return 0;
}
