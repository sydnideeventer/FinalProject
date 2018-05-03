
// 
// Name: Sydni-Dee Venter
//


#include <iostream>
#include <math.h> 

using namespace std;

// We have setup class framework for you. Please copy the point 
// class you created to this file.
class Point 
{
  
  public:

  friend istream& operator>>(istream &input, Point &p ) 
  {
    // Finish me second by adding proper input >> statement
    cout << endl << "Enter x-coordinate: ";
    input >> p.x;
    cout << "Enter y-coordinate: ";
    input >> p.y;
    return input;
  }
 
  friend ostream& operator<<(ostream &output, const Point &p ) 
  {
    // Finish me thrid by adding proper output << statement
    output << "(" << p.x << ", " << p.y << ")";
    return output;
  }
 
  // Please add constructors and other functions here.
  Point()
  {
    x = 0;
    y = 0;
  }
  
  Point(double xcor, double ycor)
  {
    x = xcor;
    y = ycor;
  }
  
  void setCoord(double xcor, double ycor)
  {
    x = xcor;
    y = ycor;
  }
  
  void setXCoord(double xcor)
  {
    x = xcor;
  }
  
  double getXCoord()
  {
    return x;
  }
  
  void setYCoord(double ycor)
  {
    y = ycor;
  }
  
  double getYCoord()
  {
    return y;
  }

  private:
  
	double x;
	double y;

};

class Line 
{
  public:
  
  double length;
  double slope;
  
  friend istream& operator>>(istream &input, Line &l) 
  {
    // Finish me second by adding proper input >> statement
    input >> l.p1;
    input >> l.p2;
    return input;
  }
 
  friend ostream& operator<<(ostream &output, const Line &l)
  {
    // Finish me thrid by adding proper output << statement
    output << l.p1 << " through " << l.p2 << endl;
    return output;
  }
  
  Line()
  {
    p1.setCoord(0, 0);
    p2.setCoord(0, 0);
  }
  
  Line(Point pt1, Point pt2)
  {
    p1 = pt1;
    p2 = pt2;
  }
  
  double getSlope()
  {
    calcSlope();
    return slope;
  }
  
  double getLength()
  {
    calcLength();
    return length;
  }
  
  Point getPoint1()
  {
    return p1;
  }
  
  void setPoint1(int x, int y)
  {
    p1.setCoord(x, y);
  }
  
  Point getPoint2()
  {
    return p2;
  }
  
  void setPoint2(int x, int y)
  {
    p2.setCoord(x, y);
  }
  
  bool isParallel(Line l)
  {
    return slope == l.getSlope();
  }
  
  void setLine(Point pt1, Point pt2)
  {
    p1 = pt1;
    p2 = pt2;
  }
  
  bool intersects(Line l)
  {
    double a1 = p2.getYCoord() - p1.getYCoord();
    double b1 = p1.getXCoord() - p2.getXCoord();
    double c1 = a1*(p1.getXCoord()) + b1*(p1.getYCoord());
    
    double a2 = l.getPoint2().getYCoord() - l.getPoint1().getYCoord();
    double b2 = l.getPoint1().getXCoord() - l.getPoint2().getXCoord();
    double c2 = a2*(l.getPoint1().getXCoord()) + b2*(l.getPoint1().getYCoord());
    
    double det = a1*b2 - a2*b1;
    
    if(det == 0)
    {
      return false;
    }
    else
    {
      double x = (b2*c1 - b1*c2)/det;
      double y = (a1*c2 - a2*c1)/det;
      Point p(x, y);
      
      cout << "Intersect at " << p << endl;
    }
    
    return true;
  }
  
  Point getYIntercept()
  {
    double inter = p1.getYCoord() - slope * p1.getXCoord();
    Point p(0, inter);
    return p;
  }
  
  bool isHorizontal()
  {
    return p1.getXCoord() == p2.getXCoord();
  }
  
  bool isVertical()
  {
    return p1.getYCoord() == p2.getYCoord();
  }
  
  private:
  
  Point p1;
  Point p2;
  
  void calcSlope()
  {
    slope = (double) (p2.getYCoord() - p1.getYCoord()) / (p2.getXCoord() - p1.getXCoord());
  }
  
  void calcLength()
  {
    length = (double) sqrt(pow(p2.getXCoord() - p1.getXCoord(), 2) + pow(p2.getYCoord() - p1.getYCoord(), 2));
  }
  
};

class Circle 
{
    public:
    double radius;
    
    Circle()
    {
      
    }
    
    Circle(Point c, Point p)
    {
      center = c;
      p1 = p;
    }
    
    friend istream& operator>>(istream &input, Circle &c) 
    {
      // Finish me second by adding proper input >> statement
      input >> c.center;
      input >> c.p1;
      return input;
    }
 
    friend ostream& operator<<(ostream &output, const Circle &c)
    {
      // Finish me thrid by adding proper output << statement
      output << "Center: " << c.center;
      return output;
    }
    
    Point getCenter()
    {
      return center;
    }
    
    double getRadius()
    {
      calcRadius();
      return radius;
    }
    
    double getDiameter()
    {
      return radius * 2;
    }
    
    double getCircum()
    {
      return 2 * radius * 3.1415;
    }
    
    double getArea()
    {
      return 2 * pow(radius, 2);
    }
    
    bool intersects(Circle c2)
    {
      double x1 = center.getXCoord();
      double y1 = center.getYCoord();
      double r1 = radius;
      double x2 = c2.getCenter().getXCoord();
      double y2 = c2.getCenter().getYCoord();
      double r2 = c2.getRadius();
      
      double distSq = pow((x1 - x2), 2) + pow((y1 - y2), 2);
      double radSumSq = pow((r1 + r2), 2);
      return !(distSq > radSumSq);
    }
    
    private:
    Point center;
    Point p1;
    
    void calcRadius()
    {
      Line l1;
      l1.setLine(center, p1);
      radius = l1.getLength();
    }
};


int main() {
  Circle C1;
  
  cout << "Enter C1: ";
  cin >> C1;

  cout << "C1: ";
  cout << C1;
  cout << endl;
  
  cout << "Radius: " << C1.getRadius();
  
  return 0;
}
