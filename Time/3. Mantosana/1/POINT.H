#ifndef POINT_H
#define POINT_H

class Point
{
public:
   Point(float, float);
   ~Point();
   void setPoint(float, float);
   float getX() const;
   float getY() const;

private:
   float x,y;
};

#endif
