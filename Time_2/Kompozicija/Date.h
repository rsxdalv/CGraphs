#ifndef DATE_H
#define DATE_H

class Date {

public:
   Date( int = 1, int = 1, int = 1900 ); //konstruktors ar defoltaam veertiibaam
   void print() const;
   ~Date();

private:
   int day;
   int month;
   int year;
   //int checkDay(int) const; 

};

#endif
