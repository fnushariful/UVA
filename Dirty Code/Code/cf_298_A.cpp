#include <bits/stdc++.h>

using namespace std;

#define SYN ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long int LLI;
typedef unsigned long long int ULLI;

int main()
{
    int na;
    while(cin>>na)
    {
        if( na == 1 )
        {
            cout<<1<<endl<<1<<endl;
            continue;
        }
        else if( na == 4 )
        {
            cout<<4<<endl;
            cout<<2<<" "<<4<<" "<<1<<" "<<3<<endl;
            continue;
        }
        else if( na == 2 )
        {
            cout<<1<<endl<<1<<endl;
            continue;
        }
        else if( na == 3 )
        {
            cout<<2<<endl;
            cout<<1<<" "<<3<<endl;
            continue;
        }
        int mk[5009],k=0,m;
        m=na;
        for( int i=1; i<=na; i+=2 ) mk[k++]=i;
        na=na-k;
        for( int i=2,j=0; j<na; i+=2,j++ ) mk[k++]=i;
        cout<<m<<endl;
        for( int i=0; i<k; i++ ) if( mk[i]>0 ) cout<<mk[i]<<" ";
        cout<<endl;
    }
    return 0;
}

