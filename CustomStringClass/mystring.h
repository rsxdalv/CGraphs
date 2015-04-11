#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

using namespace std;

class mystring
{
   friend ostream &operator << (ostream &, const mystring &); //izvade
   friend istream &operator >> (istream &, mystring &); //ievade
   public:
      mystring(const char * = ""); //konstruktors 
      ~mystring(); //destruktors
      const mystring &operator=(const mystring &); //pieskirsana
      const mystring &operator+(const mystring &); //saliimeesana (piem. s1="ab"; s2="bc"; s3=s1+s2 -> s3="abbc")
      const mystring &operator+=(const mystring &); //saliimeesana (piem. s1="ab"; s2="bc"; s1+=s2 -> s1="abbc")
      int operator!() const;  // vai ir tuksa, atgriez 1 vai 0
      int operator==(const mystring &) const; // saliidzinaasana, jaasakriit gan garumam gan saturam, atgriez 1 vai 0
      int operator!=(const mystring &) const; // saliidzinaasana, jaasakriit gan garumam gan saturam, atgriez 1 vai 0
      int operator<(const mystring &) const; // saliidzinaasana, jaasakriit gan garumam gan saturam, atgriez 1 vai 0
      int operator>(const mystring &) const; // saliidzinaasana, jaasakriit gan garumam gan saturam, atgriez 1 vai 0
      int operator>=(const mystring &) const; // saliidzinaasana, jaasakriit gan garumam gan saturam, atgriez 1 vai 0
      int operator<=(const mystring &) const; // saliidzinaasana, jaasakriit gan garumam gan saturam, atgriez 1 vai 0
      char &operator[](int);  //atgriez simbolu no rindas
      mystring operator()(int, int); //atgriez apaksrindu, parametri: no kura jaasaak un simbolu skaits
      int getLength() const; // atgriez garumu

   private:
      char *sPtr; // pointers uz rindas saakumu
      int length; // rindinas garums
};


#endif

//HELP
//darbam ar char* var izmantot funkcijas kas paredzeetas simbolu (teksta) apstraadei
//taas mees maaciijamies pagajusajaa gadaa :)
//taas ir:
//strcat
//strchr
//strcmp
//strcpy
//strlen
//strncat
//strncmp
//strncpy
//strstr
//u.c.
//siikaak var paskatiities seit:
// http://www.cs.cf.ac.uk/Dave/C/node19.html

