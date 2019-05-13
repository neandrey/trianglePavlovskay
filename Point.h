// Point.h
#ifndef POINT_H
#define POINT_H
enum ORIENT {LEFT, RIGHT, AHEAD, BEHIND, BETWEEN };
class Triangle;

class Point{
  public:
    double x, y;
  public:
    Point(double _x = 0, double _y = 0) : x(_x), y(_y)
  {}
    void Show() const;
    void operator+= (Point&);
    Point operator+ (Point&);
    Point operator- (Point&);
    double Length() ;
    ORIENT Classify(Point&, Point&) ;
    bool InTriangle(Triangle&) ; 
};
#endif
//---------------------------
