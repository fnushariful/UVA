#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    double ax1, ay1, ax2, ay2, bx1, by1, bx2, by2, x, y;
    while (cin >> ax1 >> ay1 >> ax2 >> ay2 >> bx1 >> by1 >> bx2 >> by2)
    {
        if (ax1 == bx1 && ay1 == by1)
        {
            x = ax2+bx2-ax1;
            y = ay2+by2-ay1;
        }
        else if (ax1 == bx2 && ay1 == by2)
        {
            x = ax2+bx1-ax1;
            y = ay2+by1-ay1;
        }
        else if (ax2 == bx1 && ay2 == by1)
        {
            x = ax1+bx2-ax2;
            y = ay1+by2-ay2;
        }
        else
        {
            x = ax1+bx1-ax2;
            y = ay1+by1-ay2;
        }
        printf("%0.3f %0.3f\n",x,y);
    }
}
