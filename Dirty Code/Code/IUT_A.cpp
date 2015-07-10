#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n,ar[300009],sm[300009],sum;
    while(cin>>n)
    {
        sum=0;
        cin>>ar[0];
        sum=sm[0]=ar[0];
        for( int i=1; i<n; i++ )
        {
            cin>>ar[i];
            sum+=ar[i];
        }
        long long val=sum;
        sort(ar,ar+n);
        for( int i=0; i<n; i++ )
        {
            sm[i]=sm[i-1]+ar[i];
        }
        for( int i=0; i<n-2; i++ )
            sum+=val-sm[i];
        if( n == 1 )cout<<val<<endl;
        else
            cout<<sum+val<<endl;
    }
    return 0;
}

