
// 
// Name:
//


#include <iostream>
#include <math.h> 

using namespace std;

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
  
  void setPoint1(double x, double y)
  {
    p1.setCoord(x, y);
  }
  
  Point getPoint2()
  {
    return p2;
  }
  
  void setPoint2(double x, double y)
  {
    p2.setCoord(x, y);
  }
  
  void setLine(Point pt1, Point pt2)
  {
    p1 = pt1;
    p2 = pt2;
  }
  
  bool isParallel(Line l)
  {
    return slope == l.getSlope();
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

class Triangle 
{
  public:
  
  double area;
  double perimeter;
  bool isValid;
  bool isaRight;
  bool isEqui;
  
  Triangle()
  {
    
  }
  
  Triangle(Line one, Line two, Line three)
  {
    l1 = one;
    l2 = two;
    l3 = three;
  }
  
  friend istream& operator>>(istream &input, Triangle &t) 
  {
    // Finish me second by adding proper input >> statement
    input >> t.l1;
    input >> t.l2;
    input >> t.l3;
    return input;
  }
 
  friend ostream& operator<<(ostream &output, const Triangle &t)
  {
    // Finish me thrid by adding proper output << statement
    output << t.l1 << endl;
    output << t.l2 << endl;
    output << t.l3 << endl;
    return output;
  }
  
  double getArea()
  {
    calcArea();
    return area;
  }
  
  double getPerimeter()
  {
    calcPerimeter();
    return perimeter;
  }
  
  void setLine1(Point p1, Point p2)
  {
    l1.setLine(p1, p2);
  }
  
  void setLine2(Point p1, Point p2)
  {
    l2.setLine(p1, p2);
  }
  
  void setLine3(Point p1, Point p2)
  {
    l3.setLine(p1, p2);
  }
  
  void setTriangle(Line li1, Line li2, Line li3)
  {
    l1 = li1;
    l2 = li2;
    l3 = li3;
  }
  
  bool isTriangle()
  {
    calcIfTriangle();
    return isValid;
  }
  
  bool isRight()
  {
    calcRight();
    return isaRight;
  }
  
  bool isEquilateral()
  {
    calcEqui();
    return isEqui;
  }
  
  private:
  
  Line l1;
  Line l2;
  Line l3;
  
  void calcArea()
  {
    double a = l1.getLength();
    double b = l2.getLength();
    double c = l3.getLength();
    double s = (a + b + c) / 2;
    
    area = sqrt(s * (s - a) * (s - b) * (s - c));
  }
  
  void calcPerimeter()
  {
    double a = l1.getLength();
    double b = l2.getLength();
    double c = l3.getLength();
    
    perimeter = a + b + c;
  }
  
  void calcIfTriangle()
  {
    double a = l1.getLength();
    double b = l2.getLength();
    double c = l3.getLength();
    
    if (a + b < c || b + c < a || a + c < b)
    {
      isValid = false;
    }
    else
    {
      isValid = true;
    }
  }
  
  void calcRight()
  {
    double a = l1.getLength();
    double b = l2.getLength();
    double c = l3.getLength();
    
    if(pow(a, 2) + pow(b, 2) == pow(c, 2))
    {
      isaRight = true;
    }
    else
    {
      isaRight = false;
    }
  }
  
  void calcEqui()
  {
    double a = l1.getLength();
    double b = l2.getLength();
    double c = l3.getLength();
    
    if(a == b && b == c && a == c)
    {
      isEqui = true;
    }
    else
    {
      isEqui = false;
    }
  }
};


int main() 
{
  Triangle T1;
  cout << "Enter T1: ";
  cin >> T1;
  
  cout << "T1: " << endl << T1;
  bool i = T1.isRight();
  i ? cout << "true" : cout << "false";
  return 0;
}
