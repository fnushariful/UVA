#include <bits/stdc++.h>

using namespace std;
#define PI acos(-1.0)
#define eps 1e-6

int main()
{
    double n,R,r;
    while(cin>>n>>R>>r)
    {
        if( n == 1 && r==R )
        {
            cout<<"YES"<<endl;
            return 0;
        }
        double val=r*r*PI;
        double tw=val*3;
        val=val*n;
        R=R*R*PI;
        R-=tw;
        if( val < R ) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
