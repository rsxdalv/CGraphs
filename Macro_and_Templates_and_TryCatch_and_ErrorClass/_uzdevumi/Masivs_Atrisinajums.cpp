#include <iostream>
#include <assert.h>

#define incr(x,y) \
    (x+=y)

using namespace std;


class array
{
   friend ostream &operator << (ostream &, const array &);
   friend istream &operator >> (istream &, array &);

   public:
      array (int = 10); //defolta konstruktors
      array (const array&); //kopijas konstruktors
      ~array();
      const array &operator = (const array &); //masiivu pieskirsana
      array operator + (const array &);
      const array &operator += (const array &);
      int &operator[](int);
      int operator==(const array &) const;  
      int operator!=(const array &) const; 

   private:
      int size;
      int *ptr;
      int *ptrtemp;
};



array::array(int arraySize)
{
   size = arraySize;
   ptr = new int[size];
   assert(ptr != 0); //beidzam ja atmina nav izdaliita
   for (int i = 0; i < size; i++)
      ptr[i] = 0;
}

array::array(const array &origin)
{
   size = origin.size;
   ptr = new int[size];
   assert(ptr != 0); //beidzam ja atmina nav izdaliita
   for (int i = 0; i < size; i++)
      ptr[i] = origin.ptr[i];
}

array::~array()
{
   delete [] ptr;
}

const array &array::operator = (const array &right)
{
   if (&right != this) //paarbauda vai nav tas pats masiivs, ja ir tas pats nekas nav jaadara
   {
      delete [ ] ptr;
      size = right.size;
      ptr = new int[size]; //atminas izdalisana masiiva koppijai
      assert(ptr != 0);
   
      for (int i = 0; i < size; i++)
         ptr[i] = right.ptr[i];
         
      return *this; //lauj x = y = z 
   }
   return *this; //lauj x = y = z  
}

array array::operator + (const array &right)
{
   int s = (size > right.size) ? size : right.size;
   array ptrtemp(size);
   for (int i = 0; i < s; i++)
      ptrtemp.ptr[i] = ptr[i] + right.ptr[i];
   return ptrtemp; //lauj x + y + z
}

const array &array::operator += (const array &right)
{
   for (int i = 0; ( (i < size) || (i < right.size) ); i++)
      ptr[i] += right.ptr[i];
   return *this; //lauj x = y = z
}


ostream &operator << (ostream &output, const array &a)
{
   int i;
   for (i = 0; i < a.size; i++)
   {
      output << a.ptr[i] << ' ';
      if ((i + 1) % 10 == 0)
	 output << endl;
   }
   if (i % 10 != 0)
      output << endl;
   return output;
}

istream &operator >> (istream &input, array &a)
{
   for (int i = 0; i < a.size; i++)
      input >> a.ptr[i];
   return input;
}

int &array::operator[] (int index)
{
   return ptr[index];
}


int array::operator==(const array &right) const
{
   if (size != right.size)
      return 0;    // atskiraas izmeeri

   for (int i = 0; i < size; i++)
      if (ptr[i] != right.ptr[i])
         return 0; // massiivi nav vienaadi

   return 1;        // ir vienaadi
} 


int array::operator!=(const array &right) const
{
   if (size != right.size)
      return 1;    // atskiraas izmeeri

   for (int i = 0; i < size; i++)
      if (ptr[i] != right.ptr[i])
         return 1; // massiivi nav vienaadi

   return 0;        // ir vienaadi
} 


int main()
{
    int x=6;
    cout << incr(x,8);
 /*  array mas1(5), mas2(3), mas3(4);

   cout << "Masiivi peec inicializaacijas" << endl << mas1 << mas2 << mas3; //tuksi
   // kad juus rakstaat "cout << mas1" kompilators aktivizee funkciju
   // "operator<<" genereejot izsaukumu operator<<(cout, mas1)
   
   cout << endl << "Ievadiet 5 skaitlus:" << endl;
   cin >> mas1;
   cout << endl << "Masiivi satur" << endl << mas1 << mas2 << endl;
   mas1[3]=99;
   cout << endl << "Masiivi satur" << endl << mas1 << mas2 << endl;
   mas2 = mas1;
   cout << "Masiivi satur (peec pieskirsanas)" << endl << mas1 << mas2 << endl;
   mas3 = mas1 + mas2;
   cout << "Masiivu summa" << endl << mas1 << mas2 << mas3; //ar summu
   */
   system("Pause");
   return 0;
}
