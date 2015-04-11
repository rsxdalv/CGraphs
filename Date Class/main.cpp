#include <iostream>

using namespace std;

class Datums
{
   friend ostream &operator<<(ostream &, const Datums &);
   friend istream &operator>>(istream &, Datums &);
   
public:
   Datums(unsigned int=1,unsigned int=1,unsigned int=1);
   ~Datums();
   const Datums &operator=(const Datums &);
   int operator==(const Datums &) const;
   int operator>=(const Datums &) const;
   int operator<=(const Datums &) const;
   int operator!=(const Datums &) const;
   int operator<(const Datums &) const;
   int operator>(const Datums &) const;
   //Datums operator-=(const unsigned int);
   //Datums operator-(const unsigned int);
   Datums operator--(int);
   Datums operator--();
   Datums operator+=(const unsigned int);
   Datums operator+(const unsigned int);
   Datums operator++(int);
   Datums operator++();
   //>, <, >=, <=, ==, != 
   //Datums operator++(int);
   //!!!aliepins@inbox.lv
   
private:
   unsigned int day;
   unsigned int month;
   unsigned int year;
   int ID;
   static int Counter;
   int checkDay(int) const;
};

const Datums &Datums::operator=(const Datums &Dat2)
{
   if(&Dat2==this) return *this;
   day=Dat2.day;
   month=Dat2.month;
   year=Dat2.year;
   return *this;
}

Datums Datums::operator+(const unsigned int a)
{
   day+=a;
   while(day>31){
      day-=31;month++;}
   while(month>12){
      month-=12;
      year++;}
   return *this;
}

Datums Datums::operator+=(const unsigned int a)
{
   day+=a;
   while(day>31){
      day-=31;month++;}
   while(month>12){
      month-=12;
      year++;}
   return *this;
}

Datums Datums::operator++()
{
   day++;
   if(!checkDay(day)) //Ja VAIRS neizpildâs noteikums par dienu.
   {
      day=1;
      month++;
   }
   //month++;
   if(month>12){
      month-=12;
      year++;}
   //year++;
   return *this;
}

Datums Datums::operator++(int)
{
   Datums postfix(1,1,1);
   postfix=*this;
   day++;
   if(!checkDay(day)) //Ja VAIRS neizpildâs noteikums par dienu.
   {
      day=1;
      month++;
   }
   //month++;
   if(month>12){
      month-=12;
      year++;}
   //year++;
   return postfix;
}

Datums Datums::operator--()
{
   day--;
   if(!day)
   {
      day=31;
      month--;
      if(!month){
      month=12;
      year--;}
      while(!checkDay(day)) day--;
   }
   //month++;
   //year++;
   return *this;
}

Datums Datums::operator--(int)
{
   Datums postfix(1,1,1);
   postfix=*this;
   day--;
   if(!day)
   {
      day=31;
      month--;
      if(!month){
      month=12;
      year--;}
      while(!checkDay(day)) day--;
   }
   //month++;
   //year++;
   return postfix;
} 

int Datums::operator>(const Datums &Dat2) const
{
    if(year>Dat2.year) if(month>Dat2.month) if(day>Dat2.day) return 1;
    return 0;
}

int Datums::operator>=(const Datums &Dat2) const
{
    if(year>=Dat2.year) if(month>=Dat2.month) if(day>=Dat2.day) return 1;
    return 0;
}

int Datums::operator<=(const Datums &Dat2) const
{
    if(year<=Dat2.year) if(month<=Dat2.month) if(day<=Dat2.day) return 1;
    return 0;
}

int Datums::operator!=(const Datums &Dat2) const
{
    if(year>=Dat2.year) if(month>=Dat2.month) if(day>=Dat2.day) return 1;
    return 0;
}

int Datums::operator<(const Datums &Dat2) const
{
    if(year>Dat2.year) if(month>Dat2.month) if(day>Dat2.day) return 1;
    return 0;
}

int Datums::operator==(const Datums &Dat2) const
{
   if(year==Dat2.year) if(month==Dat2.month) if(day==Dat2.day) return 1;
   return 0;
}   

int Datums::checkDay( int testDay ) const
{
   static const int daysPerMonth[13]=
      {0,31,28,31,30,31,30,31,31,30,31,30,31};
   if ( testDay > 0 && testDay <= daysPerMonth[ month ] )
      return testDay;
   if ( month == 2 && testDay == 29 && 
         ( year % 400 == 0 || ( year % 4 == 0 && year % 100 != 0 ) ) 
      ) return testDay;
   return 0;
}

Datums::Datums(unsigned int dy,unsigned int mn, unsigned int yr)
{
   ID=Counter++;
   if ( mn > 0 && mn <= 12 ) month = mn;
   else { 
      month = 0;
      cout << mn << " Nepareizs menesis" << endl;
   }
   day = checkDay(dy);
   if(!day) cout << dy << " Nepareiza diena/menesis" << endl;
   year = yr;
   //cout << "Datuma konstruktors " << *this<<endl;
}

Datums::~Datums()
{
   //cout << "Datuma destruktors "<< *this<< endl;
}

int Datums::Counter = 0;

ostream &operator<<(ostream &output,const Datums &dat)
{
   output <<" "<< dat.day << "." << dat.month << "." << dat.year << ".";
   return output;
} 

istream &operator>>(istream &input, Datums &dat)
{
   char dy[3];
   char mn[3];
   char yr[5];
   input.get(dy, 3);
   dat.day=atoi(dy);
   input.ignore(1);
   input.get(mn, 3);
   dat.month=atoi(mn);
   input.ignore(1);
   input.get(yr, 5);
   dat.year=atoi(yr);
   input.ignore();
   input.ignore();
}   

int main()
{
   Datums PKK(15,5,2004);
   Datums PK(14,12,2003);
   cout << "Ievade:";
   cin >> PK;
   ++PK;
   cout << "++Operator: "<< PK++ << endl;
   cout << "Operator++: "<< PK<<endl;
   --PK;
   cout << "--Operator: "<< PK-- << endl;
   cout << "Operator--: "<< PK<<endl;
   cout << "Kopesana:"<<endl;
   cout << PK << "   " << PKK<<endl;
   PK=PKK;
   cout << PK << "   " << PKK<<endl;
   Datums AK(31,12,2001);
   for(int a=0;a<10;a++)
   {
      cout<< AK << endl;
      AK+=10;
   }
   Datums NM,NM2;
   cout << "Operator <= :";
   cin >> NM;
   cin >> NM2;
   if(NM<=NM2) cout << "Mazakais-vienadais[1] :" << NM<<endl;
   else cout << "Mazakais-vienadais[2] :" << NM2<<endl;
   Datums OM,OM2;
   cout << "Operator >= :";
   cin >> OM;
   cin >> OM2;
   if(OM>=OM2) cout << "Lielakais-vienadais[1] :" << OM<<endl;
   else cout << "Lielakais-vienadais[2] :" << OM2<<endl;
   Datums PM,PM2;
   cout << "Operator == :";
   cin >> PM;
   cin >> PM2;
   if(PM==PM2) cout << "Vienadi";
   else cout << "Atskirigi";
   Datums RM,RM2;
   cout << "Operator > :";
   cin >> RM;
   cin >> RM2;
   if(RM>RM2) cout << "Lielakais[1] :" << RM<<endl;
   else cout << "Lielakais[2] :" << RM2<<endl;
   system("PAUSE");
   return 0;
}
