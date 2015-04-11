#include <iostream>
#include "timeh.h"

using namespace std;

Time::Time()
{
   hour=minute=second = 0;
}

void Time::setTime (int h, int m, int s)
{
  hour = (h >= 0 && h <24) ? h : 0;
  minute = (m>=0 && m<60) ? m : 0;
  second = (s>=0 && s<60) ? s:0;
}

void Time::printTime()
{
   cout << (hour < 10 ? "0" : "") << hour << ":"
		<< (minute < 10 ? "0" : "") << minute << ":"
		<< (second < 10 ? "0" : "") << second;
}
