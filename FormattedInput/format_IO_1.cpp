#include <iostream>

using namespace std;

class PhoneNumber
{
   friend ostream &operator << (ostream &, const PhoneNumber &);
   friend istream &operator >> (istream &, PhoneNumber &);
private:
   char areaCode[4];
   char number[9];
};

ostream &operator << (ostream &output, const PhoneNumber &num)
{
   output << "(+" << num.areaCode << ")" << num.number;
   return output;
}

istream &operator >> (istream &input, PhoneNumber &num)
{
   input.ignore(2);
   input.get(num.areaCode, 4);
   input.ignore(1);
   input.get(num.number, 9);
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

