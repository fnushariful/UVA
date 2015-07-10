#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x,y,p,q;
    while(cin>>x>>y>>p>>q)
    {
        if( x == p and y == q )
            cout<<"0 0 0"<<endl;
        if( x == p or y == q ) cout<<1<<" ";
        else cout<<2<<" ";
        if( (x+y)%2 == (p+q)%2  ) cout<<1<<" ";
        else cout<<0<<" ";
        cout<<max(abs(x-p),abs(y-q))<<endl;
    }
    return 0;
}
