#include <bits/stdc++.h>

#define N 1000000
using namespace std;

long long pow(int i, int p)
{
    long long sum = i;
    for ( int k = 2; k <= p; k++ )
    {
        sum *= i;
    }

    return sum;
}
int main ()
{
    long long n,T;
    scanf("%lld",&T);
    for( int t=1; t<=T; t++ )
    {
        scanf("%lld", &n);
        int length;
        if ( n < 0 )
        {
            bool fl=0;
            length = sqrt (n * -1);
            for ( int i = -2; i >= -length; i-- )
            {
                long long ans = i;
                int p = 2;
                while ( ans > n )
                {
                    ans = pow(i, p);
                    p++;
                    //cout<<ans<<" "<<p<<endl;

                }
                if ( ans == n )
                {
                    printf ("Case %d: %d\n",t,p - 1);
                    fl=1;
                    break;
                }
            }
            if( fl == 0 )
                printf("Case %d: 1\n",t);

        }
        else
        {
            bool fl=0;
            length = sqrt (n);
            for( int i = 2; i <= length; i++ )
            {
                long long ans = i;
                int p = 2;
                while ( ans < n )
                {
                    ans = pow (i, p);
                    p++;
                    //cout<<ans<<" "<<p<<endl;
                }
                if ( ans == n )
                {
                    printf ("Case %d: %d\n",t,p - 1);
                    fl=1;
                    break;
                }
            }
            if( fl == 0 )
                printf("Case %d: 1\n",t);
        }
    }
    return 0;
}
