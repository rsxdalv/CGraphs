#include <iostream>
#include <string>

using namespace std;

class Time
{

public:
   Time();
   void setTime(int, int, int, string);
   void printTime();

private:
   int hour;   // 0-23
   int minute; // 0-59
   int second; // 0-59
   string ss;
};


Time::Time()
{
   hour=minute=second = 0;
}

void Time::setTime (int h, int m, int s, string str)
{
  hour = (h>=0 && h <24) ? h : 0;
  minute = (m>=0 && m<60) ? m : 0;
  second = (s>=0 && s<60) ? s : 0;
  ss=str;
}

void Time::printTime()
{
   cout << (hour < 10 ? "0" : "") << hour << ":"
		<< (minute < 10 ? "0" : "") << minute << ":"
		<< (second < 10 ? "0" : "") << second << ss;
}

int main()
{
   Time t;
   cout << "Laiks ir: ";
   t.printTime();
   t.setTime(13, 27, 6, "aaa");
   cout << endl << "Laiks ir: ";
   t.printTime();

   t.setTime(78, 10, 99, "bbb");

   cout << endl << "Peec nepareiza meeginaajuma: ";
   t.printTime();
   cout << endl << endl;
   system("Pause");
   return 0;
}


























