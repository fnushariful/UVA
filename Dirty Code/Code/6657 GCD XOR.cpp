#include <bits/stdc++.h>

#define LLI long long
using namespace std;

template<class T> inline T GCD(T a,T b)
{
    if ( a < 0 ) return GCD(-a,b);
    if ( b < 0 ) return GCD(a,-b);
    return (b == 0) ? a :GCD(b,a%b);
}

int main()
{
    LLI n;
    int T;
    scanf("%d",&T);
    for( int t=1; t<=T; t++ )
    {
        scanf("%lld",&n);
        LLI cnt=0;
        for( int i=1; i<=n; i++ )
        {
            for( int j=1; j<=i; j++ )
            {
                int m=i^j;
                if( GCD(i,j) == m && i>j )
                {
                    cnt++;
//                    cout<<"24 "<<GCD(i,j)<<" "<<m<<endl;
//                    cout<<" 25 "<<i<<" "<<j<<endl;
                }
            }
        }
        printf("Case %d: %lld\n",t,cnt);
    }
    return 0;
}
