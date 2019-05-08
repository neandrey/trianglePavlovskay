// Triangle.h
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Point.h"

class Triangle{
  public:
    Triangle(Point, Point, Point, const char*);
    Triangle(const char*);
    ~Triangle();
    Point Get_v1() const
    { return v1; }
    Point Get_v2() const
    { return v2; }
    Point Get_v3() const
    { return v3; }
    char* GetName() const
    { return name; }
    void Show() const;
    void Move(Point);
    //void ShowSideAndArea() const;
  public:
    static int count;
  private:
    Point v1, v2, v3;
    char* name;
    char* objID;
    double a;
    double b;
    double c;
};
#endif
