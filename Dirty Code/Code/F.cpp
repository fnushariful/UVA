#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    long long a,b,c,d,f;
    scanf("%d",&T);
    for( int t=1; t<=T; t++ )
    {
        scanf("%lld%lld%lld%lld%lld",&a,&b,&c,&d,&f);
        long long sum=0;
        sum=a+(b*c)-(d*f);
        printf("Case %d: %lld\n",t,sum);
    }
    return 0;
}
