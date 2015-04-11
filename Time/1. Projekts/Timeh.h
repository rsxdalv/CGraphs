#ifndef TIMEH_H
#define TIMEH_H

class Time
{

public:
   Time();
   void setTime(int, int, int);
   void printTime();

private:
   int hour;   // 0-23
   int minute; // 0-59
   int second; // 0-59
};

#endif
