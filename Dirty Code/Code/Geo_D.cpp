#include <bits/stdc++.h>

#define PI acos(-1.0)

using namespace std;

int main()
{
    int n,ar[1000];
    while(cin>>n)
    {
        for( int i=0; i<n; i++ ) cin>>ar[i];
        sort(ar,ar+n);
        int sum=0;
        if( n% 2  == 1 )
        {
            for( int i=n-1; i>=1; i-=2 )
            {
                sum+=(ar[i]*ar[i])-(ar[i-1]*ar[i-1]);
            }
            sum+=ar[0]*ar[0];
            printf("%0.10lf\n",sum*PI);
        }
        else
        {
            for( int i=n-1; i>=0; i-=2 )
            {
                sum+=(ar[i]*ar[i])-(ar[i-1]*ar[i-1]);
            }
            printf("%0.10lf\n",sum*PI);
        }
    }
    return 0;
}
