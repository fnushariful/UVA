#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,ar[1000],val;
    while(cin>>n>>val)
    {
        for(int i=0; i<n; i++ ) cin>>ar[i];
        int add=0;
        for( int i=0; i<n; i++ )
        {
            int a=ar[i];
            for( int j=i+1; j<n; j++ )
            {
                for( int k=i+1; k<n; )
                {
                    a=ar[i];
                    for( int cnt=0; cnt<j; cnt++,k++ )
                    {
                        a=a*ar[k];
                    }
                    if( a == val ) add++;
                    cout<<add<<endl;
                }
            }
        }
    }
    return 0;
}
