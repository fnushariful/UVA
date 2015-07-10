#include <bits/stdc++.h>
#define debug(x)         cerr<<__LINE__<<" "<<#x<<" "<<x<<endl;

using namespace std;

#define LLI long long
#define MX 1000000

LLI prime[MX];
bool status[MX];

template<class T> inline T GCD(T a,T b)
{
    if ( a < 0 ) return GCD(-a,b);
    if ( b < 0 ) return GCD(a,-b);
    return (b == 0) ? a :GCD(b,a%b);
}

void sieve()
{
    LLI sqrtN=sqrt(MX);
    for( LLI i=3; i<=sqrtN; i+=2 )
    {
        if(!status[i])
            for( LLI j=i*i; j<=MX; j+=i+i )
                status[j]=1;
    }
    prime[0]=2;
    LLI k=1;
    for( LLI i=3; i<MX; i+=2 )
        if(!status[i])
            prime[k++]=i;
}

void fact( LLI m ,bool ok )
{
    LLI stor[1000],k=0;
    for( LLI i=0; prime[i]*prime[i]<=m; i++ )
    {
        LLI cnt=0;
        if( m% prime[i]== 0 )
        {
            while( m%prime[i] == 0 )
            {
                m/=prime[i];
                cnt++;
            }
            //cout<<cnt<<endl;
            stor[k++]=cnt;
        }
    }
    //cout<<m<<endl;
    if( m > 1 ) stor[k++]=1;

    LLI gcd=0;
    for( int i=0; i<k; i++ )
    {
        gcd=GCD(gcd,stor[i]);
        //printf("%lld ",stor[i]);
    }
    if( ok )
    {
        while((gcd&1) == 0) gcd /= 2;
        printf("%lld\n",gcd);
    }
    else
        printf("%lld\n",gcd);
}

int main()
{
    sieve();
    LLI n,m;
    LLI t=0;
    while(scanf("%lld",&n)==1 )
    {
        if( n == 0 ) break;
        bool ok=0;
        if( n<0 ) n=n*(-1),ok=1;
        fact(n,ok);
    }
    return 0;
}

