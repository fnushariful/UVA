#include <bits/stdc++.h>

#define LLI long long
#define mod 10000000000007

LLI nCr(LLI n,LLI m)
{
    LLI k;
    LLI i,j;
    LLI c,d;
    c=d=1;
    k=(m>(n-m))?m:(n-m);
    for(j=1,i=k+1; (i<=n); i++,j++)
    {
        c*=i;
        d*=j;
        if( !fmod(c,d) && (d!=1) )
        {
            c/=d;
            d=1;
        }
    }
    return c;
}
/* A sample main function */
int main()
{
    LLI n,m,l;
    while(scanf("%lld%lld%lld",&l,&n,&m)!=EOF)
    {
        l=l*l;
        LLI sum=0;
        for( LLI i=n; i<=m; i++ )
        {
            //printf("35 %lld\n",nCr(l,i));
            for( int j=l; j>=i; j-- )
            sum=((sum%mod)+nCr(j,1)%mod)%mod;
            printf("38 %lld\n",sum);
        }
    }
    return 0;
}
