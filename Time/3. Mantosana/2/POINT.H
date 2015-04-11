#ifndef POINT_H
#define POINT_H

class Point
{
public:
   Point(float, float,int);
   ~Point();
   void setPoint(float, float);
   float getX() const;
   float getY() const;
   int identy;
private:
   float x,y;
};

#endif
