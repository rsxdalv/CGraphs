#include <iostream>
#include <assert.h>

using namespace std;

class array
{
      friend ostream &operator<<(ostream &, const array &);
      friend istream &operator>>(istream &, const array &);
      //!!! realizeet ievadi !!!

    public:
      array(int = 10); //defolta konstruktors
      ~array();
      const array &operator=(const array &); //masiivu pieskirsana
      int &operator[](int);
      int operator==(const array &) const;
      int operator!=(const array &) const;
      //!!! realizeet == , ja ir vienaadi izvadam 1, ja nav izvvadam 0!!!
      //!!! realizeet != , ja nav vienaadi izvadam 1, ja ir izvvadam 0!!!
      //!!! realizeet + , 1. ar 1., 2. ar 2., u.t.t.!!!
      //!!! realizeet - , 1. ar 1., 2. ar 2., u.t.t.!!!

    private:
      int size;
      int *ptr;
};

array::array(int arraySize)
{
      size = arraySize;
      ptr = new int[size];

      assert(ptr != 0);

      for (int i = 0; i < size; i++)
            ptr[i] = 0;
}

array::~array()
{
      delete[] ptr;
}

const array &array::operator=(const array &right)
{
      if (&right != this) //paarbauda vai nav tas pats masiivs, ja ir tas pats nekas nav jaadara
      {
            delete[] ptr;
            size = right.size;
            ptr = new int[size]; //atminas izdalisana masiiva koppijai
            assert(ptr != 0);

            for (int i = 0; i < size; i++)
                  ptr[i] = right.ptr[i];

            return *this; //lauj x = y = z
      }
      return *this; //lauj x = y = z
}

int array::operator==(const array &right) const
{
      if (&right == this)
            return 1;
      if (size != right.size)
            return 0;
      for (int i = 0; i < size; i++)
      {
            if (ptr[i] != right.ptr[i])
                  return 0;
      }
      return 1;
}

ostream &operator<<(ostream &output, const array &a)
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

istream &operator>>(istream &input, const array &a)
{
      int i;
      for (i = 0; i < a.size; i++)
      {

            input >> a.ptr[i] >> ' ';
      }
      return input;
}

int &array::operator[](int index)
{
      return ptr[index];
}

int main()
{
      array mas1(5), mas2(5);

      cout << "Masiivi peec inicializaacijas" << endl
           << mas1 << mas2; //tuksi
      // kad juus rakstaat "cout << mas1" kompilators aktivizee funkciju
      // "operator<<" genereejot izsaukumu operator<<(cout, mas1)

      mas1[0] = 10;
      mas1[1] = 20;
      mas1[2] = 30;
      mas1[3] = 40;
      mas1[4] = 50;
      cout << endl
           << "Masiivi satur" << endl
           << mas1 << mas2 << endl;
      mas2 = mas1;
      cout << "Masiivi satur (peec pieskirsanas)" << endl
           << mas1 << mas2 << endl;
      cin >> mas1;
      cout << "Masiivi satur (peec pieskirsanas)" << endl
           << mas1 << mas2 << endl;
      system("Pause");
      return 0;
}
