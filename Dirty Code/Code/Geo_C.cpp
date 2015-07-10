#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,c,d;
    while(cin>>a>>b>>c>>d)
    {
        if( ((a+b>c) && (b+c>a )&& a+c>b) || (b+c>d && c+d>b && b+d>c ) || (c+d> a && d+a>c && c+a>d ) || (a+b>d && b+d>a && d+a>b) )
            cout<<"TRIANGLE"<<endl;
        else if( ((a+b==c) || (b+c==a )|| a+c==b) || (b+c==d || c+d==b || b+d==c ) || (c+d== a || d+a==c || c+a==d ) || (a+b==d || b+d==a || d+a ==b))
            cout<<"SEGMENT"<<endl;
        else cout<<"IMPOSSIBLE"<<endl;
    }
    return 0;
}
