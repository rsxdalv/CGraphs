#include <iostream>
#include <string>

#ifndef H_WORKER
#define H_WORKER

class Worker
{
public:
   virtual ~Worker() {};
   virtual bool Use() const;
   virtual void Print() const = 0;
protected:
   std::string name;
   std::string surname;
};

#endif
