#include <iostream>
#include <assert.h>

using namespace std;

template<class T>
class array
{
   friend ostream &operator << <T>(ostream &,  array<T> const &);
   friend istream &operator >> <T>(istream &, array<T> &);

   public:
      array<T> (int = 10); //defolta konstruktors
      array<T> (const array&); //kopijas konstruktors
      ~array<T>();
      const array<T> &operator = (const array<T> &); //masiivu pieskirsana
      array<T> operator + (const array<T> &);
      const array<T> &operator += (const array<T> &);
      T &operator[](int);
      T operator==(const array<T> &) const;  
      T operator!=(const array<T> &) const; 

   private:
      int size;
      T *ptr;
      T *ptrtemp;
};


template<class T>
array<T>::array(int arraySize)
{
   size = arraySize;
   ptr = new T[size];
   assert(ptr != 0); //beidzam ja atmina nav izdaliita
   for (int i = 0; i < size; i++)
      ptr[i] = 0;
}

template<class T>
array<T>::array(const array<T> &origin)
{
   size = origin.size;
   ptr = new T[size];
   assert(ptr != 0); //beidzam ja atmina nav izdaliita
   for (int i = 0; i < size; i++)
      ptr[i] = origin.ptr[i];
}
template<class T>
array<T>::~array()
{
   delete [] ptr;
}
template<class T>
const array<T> &array<T>::operator = (const array<T> &right)
{
   if (&right != this) //paarbauda vai nav tas pats masiivs, ja ir tas pats nekas nav jaadara
   {
      delete [ ] ptr;
      size = right.size;
      ptr = new T[size]; //atminas izdalisana masiiva koppijai
      assert(ptr != 0);
   
      for (int i = 0; i < size; i++)
         ptr[i] = right.ptr[i];
         
      return *this; //lauj x = y = z 
   }
   return *this; //lauj x = y = z  
}
template<class T>
array<T> array<T>::operator + (const array<T> &right)
{
   int s = (size > right.size) ? size : right.size;
   array ptrtemp(size);
   for (int i = 0; i < s; i++)
      ptrtemp.ptr[i] = ptr[i] + right.ptr[i];
   return ptrtemp; //lauj x + y + z
}
template<class T>
const array<T> &array<T>::operator += (const array<T> &right)
{
   for (int i = 0; ( (i < size) || (i < right.size) ); i++)
      ptr[i] += right.ptr[i];
   return *this; //lauj x = y = z
}

template<class T>
ostream &operator << (ostream &output, const array<T> &a)
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

template<class T>
istream &operator >> (istream &input, array<T> &a)
{
   for (int i = 0; i < a.size; i++)
      input >> a.ptr[i];
   return input;
}

template<class T>
T &array<T>::operator[] (int index)
{
   return ptr[index];
}

template<class T>
T array<T>::operator==(const array &right) const
{
   if (size != right.size)
      return 0;    // atskiraas izmeeri

   for (int i = 0; i < size; i++)
      if (ptr[i] != right.ptr[i])
         return 0; // massiivi nav vienaadi

   return 1;        // ir vienaadi
}

template<class T>
T array<T>::operator!=(const array &right) const
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
   array<long> mas1(5), mas2(3), mas3(4);

   //cout << "Masiivi peec inicializaacijas" << endl << mas1 << mas2 << mas3; //tuksi
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
   
   system("Pause");
   return 0;
}
