#include <iostream>
#include "date.h"

using namespace std;

Date::Date( int dy, int mn, int yr )
{
   if ( mn > 0 && mn <= 12 ) month = mn;
   else { 
      month = 1;
      cout << mn << " nepareizaa meenesa veertiiba, pieskirta veertiiba 1" << endl;
   }
   day = checkDay(dy);
   year = yr;
   cout << "Datuma konstruktors ";                
   cout << endl;
}


void Date::print() const
{
   cout << day << '.' << month << '.' << year << '.'; 
}


Date::~Date()
{ 
   cout << "Datuma destruktors";
   print();
   cout << endl;
}

int Date::checkDay( int testDay ) const
{
   static const int daysPerMonth[ 13 ] = 
      { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

   // paarbauda vai diena eksistee konkreetaa meenesii
   if ( testDay > 0 && testDay <= daysPerMonth[ month ] )
      return testDay;

   // paarbauda 29 februaari prieks gara gada, ir jaa
   // 1. dalaas ar 4 bez atlikuma un dalaas ar 100 ar atlikumu
   // 2. dalaas ar 400 bez atlikuma
   if ( month == 2 && testDay == 29 && 
         ( year % 400 == 0 || ( year % 4 == 0 && year % 100 != 0 ) ) 
      ) return testDay; //izgaaja paarbaudi

   cout << testDay << " nepareizaa dienas veertiiba, pieskirta veertiiba 1" << endl;

   return 1; //neizgaaja paarbaudi
}
