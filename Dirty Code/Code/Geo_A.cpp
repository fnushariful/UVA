#include <bits/stdc++.h>

using namespace std;

int main()
{
    long T,n,val;
    cin>>T;
    for( int t=1; t<=T; t++ )
    {
        cin>>n;
        bool ok=false;
        for( int i=3; i<100000; i++ )
        {
            val=(i-2)*180;
            if( val == n*i )
            {
                cout<<"YES"<<endl;
                ok=true;
                break;
            }
        }
        if(!ok)
            cout<<"NO"<<endl;
    }
    return 0;
}
