#include <iostream>
#include <assert.h>
#include <string>
#include "mystring.h"
using namespace std;

// CIN >>
istream &operator >> (istream &input, mystring &dest)
{
   input>>dest.sPtr; // Parveido masivu par vajadzigo - pielidzina izmeru un ievada saturu! K�? - Hvz.
   dest.length=strlen(dest.sPtr); // Parkop� jauno izm�ru uz lenght - lai ir zin�ms.
   return input;
}
// COUT <<
ostream &operator << (ostream &output, const mystring &source) //izvade
{
   output<<source.sPtr; // Char * visu izdara!
   return output;
}   

mystring::mystring(const char* a)
{
   sPtr= new char [0];
   assert(sPtr != 0); //beidzam ja atmina nav izdaliita
   length=0; // Nulles garums.
}

mystring::~mystring()
{
   delete [] sPtr;
}

const mystring &mystring::operator=(const mystring &source){
   if(&source!=this) // stringA=stringB
   {
      delete [ ] sPtr; // izdz�� stringA
      length = source.length; // pa�em stringB izmeru
      sPtr= new char[length]; // izvieto atmi�u mas�vam ar stringB izmeru
      assert(sPtr != 0); //beidzam ja atmina nav izdaliita
      for (int i = 0; i < length; i++) // p�rkop��ana.
         sPtr[i] = source.sPtr[i];
      return *this; 
   }
   return *this;   
}   
//const mystring::mystring &operator+(const mystring &); //saliimeesana (piem. s1="ab"; s2="bc"; s3=s1+s2 -> s3="abbc")
const mystring &mystring::operator+=(const mystring &source){
   //if(sou
} //saliimeesana (piem. s1="ab"; s2="bc"; s1+=s2 -> s1="abbc")
//int mystring::operator!() const;  // vai ir tuksa, atgriez 1 vai 0
int mystring::operator==(const mystring &source) const{ // saliidzinaasana, jaasakriit gan garumam gan saturam, atgriez 1 vai 0
   if(&source==this) return 1;
   if(length==source.length) if(strcmp(*this,source.sPtr)) return 1;
   return 0;
}
//int mystring::operator!=(const mystring &) const; // saliidzinaasana, jaasakriit gan garumam gan saturam, atgriez 1 vai 0
//int mystring::operator<(const mystring &) const; // saliidzinaasana, jaasakriit gan garumam gan saturam, atgriez 1 vai 0
//int mystring::operator>(const mystring &) const; // saliidzinaasana, jaasakriit gan garumam gan saturam, atgriez 1 vai 0
//int mystring::operator>=(const mystring &) const; // saliidzinaasana, jaasakriit gan garumam gan saturam, atgriez 1 vai 0
//int mystring::operator<=(const mystring &) const; // saliidzinaasana, jaasakriit gan garumam gan saturam, atgriez 1 vai 0
//char &ystring::operator[](int);  //atgriez simbolu no rindas
//mystring mystring::operator()(int, int); //atgriez apaksrindu, parametri: no kura jaasaak un simbolu skaits

int mystring::getLength() const{
   return length;}

int main()
{
   mystring string,string2;
   cout << string.getLength() << endl;
   cout << "Ievade"<<endl;
   cin>>string;
   cout << "Rezultats" <<endl<< string << endl << string.getLength();
   system("Pause");
} 
