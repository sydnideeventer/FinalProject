
// 
// Name: Sydni-Dee Venter
//


#include <iostream>

using namespace std;

// We have setup class framework for you.
// Please add cin/cout overload first and at the same time add the coordinates
//
// See github example as specified in the assignment handout for exaamples
//

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


int main()
{
  
  Point P1;
  
  cout << "Enter P1: ";
  cin >> P1;

  cout << "P1: ";
  cout << P1;
  cout << endl;
  
  return 0;
}
