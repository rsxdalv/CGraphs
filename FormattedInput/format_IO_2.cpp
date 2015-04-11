#include <iostream>

using namespace std;

class PhoneNumber
{
   friend ostream &operator << (ostream &, const PhoneNumber &);
   friend istream &operator >> (istream &, PhoneNumber &);
private:
   long areaCode;
   long number;
};

ostream &operator << (ostream &output, const PhoneNumber &num)
{
   output << "(+" << num.areaCode << ")" << num.number;
   return output;
}

istream &operator >> (istream &input, PhoneNumber &num)
{
   char ac[4];
   char n[9];
   input.ignore(2);
   input.get(ac, 4);
   num.areaCode = atol(ac);
   input.ignore(1);
   input.get(n, 9);
   num.number = atol(n);
   return input;
}

int main()
{
   PhoneNumber phone;
   cout << "Ievadiet telefona numuru (+371)67123456 veidaa " << endl;
   cin >> phone;
   cout << endl << "Bija ievadiits telefona numurs: " << phone << endl;
   system("Pause");
   return 0;
}

