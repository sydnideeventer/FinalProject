/*
    Fill me in
*/

#include <iostream>
#include <vector>

#include "LList.h"

using namespace std;

int main()
{
    LList a;
    for(int i = 0; i < 10; i++)
    {
        a.push_back(i);
    }
    
    LList b;
    b.push_back(60);
    
    LList c = a;
    
    bool e = (c == b);
    
    cout << e;
    
    cout << "[";
    for(unsigned int i = 1; i < c.size(); i++)
    {
        cout << c.getAt(i-1) << ", ";
    }
    if(c.size() > 0)
    {
        cout << c.getAt(c.size() - 1);
    }
    cout << "]";
    
    return 0;
}

