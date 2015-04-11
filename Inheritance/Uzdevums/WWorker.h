#include <iostream>
#include <string>
#include "Worker.h"

#ifndef WWORKER_H
#define WWORKER_H

class WeeklyWorker: public Worker
{
public:
   WeeklyWorker(std::string,std::string,float);
   ~WeeklyWorker() {};
   void SetName(std::string,std::string);
   float getSalary() const {return salary;}
   void Print() const;
protected:
   float salary;
};
#endif
