#ifndef STUDENTS_H
#define STUDENTS_H

#include "skolens.h"

class Students : public Skolens {
public:
    Students(const char, unsigned int, float, float, float, int);
    ~Students();
    void setAge(unsigned int);
    void setStipend(float);
    float getStipend() const;
private:
    float Stipend;
};
#endif
