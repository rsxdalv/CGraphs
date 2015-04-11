#include <iostream>
#include <string>
#include "WWorker.h"

#ifndef HWORKER_H
#define HWORKER_H

class HourlyWorker: public WeeklyWorker
{
public:
   HourlyWorker(std::string,std::string,float, int);
   ~HourlyWorker() {};
private:
   int hours;
}   
