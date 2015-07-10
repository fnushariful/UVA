#include <bits/stdc++.h>

using namespace std;

#define SYN ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long int LLI;
typedef unsigned long long int ULLI;

#define debug(x)         cerr<<__LINE__<<" "<<#x<<" "<<x<<endl;
#define IMAX ((unsigned)1<<31)-1
#define eps 1e-11
#define fill(a,v) memset(a,v,sizeof (a))
#define SZ(X) ((int)X.size())
#define VI vector<int>
#define VS vector<string>
#define PB push_back
#define MSI map<string,int>
#define MLLI map<LLI,LLI>
#define MCI map<char,int>
#define PI acos(-1.0)
#define mk make_pair
#define pLLI pair<LLI,LLI>
#define xx first
#define yy second
#define st string

#define MOD 1000000007
#define MX 1000009
#define RADIANS(x)       (((1.0 * x * PI) / 180.0))
#define DEGREES(x)       (((x * 180.0) / (1.0 * PI)))

LLI prime[MX];
bool status[MX];

void sieve()
{
    LLI sqrtN=sqrt(MX);
    for( LLI i=3; i<=sqrtN; i+=2 )
    {
        if( !status[i] )
            for( LLI j=i*i; j<=MX; j+=i+i )
                status[j]=i;
    }
    LLI k=1;
    prime[0]=2;
    for( LLI i=3; i<=MX; i+=2 )
        if( status[i] == 0 )
            prime[k++]=i;
}

LLI dir[MX];
LLI fact(LLI n)
{
    for( LLI k=1; k<=MX; k++ )
    {
        n=k;
        LLI ret=1;
        for( LLI i=0; prime[i]*prime[i]<=n; i++ )
        {
            LLI cnt=0;
            bool ok=0;
            while(n%prime[i] == 0 )
            {
                n/=prime[i];
                ok=1;
                cnt++;
            }
            if( ok ) ret*=(cnt+1);
        }
        if( n > 1 ) ret*=2;
        dir[k]=ret;
    }
    return 0;
}

LLI dp[MX],stor[MX],sav[MX];
int main()
{
    sieve();
    LLI T,n;
    dp[0]=sav[0]=1;
    fact(n);
    for( LLI i=1; i<=MX; i++ )
    {
        dp[i]=dp[i-1]+dir[dp[i-1]];
        stor[dp[i]]=1;
        if( stor[i] != 0 ) sav[i]=1+sav[i-1];
        else sav[i]=sav[i-1];
    }
    scanf("%lld",&T);
    for( LLI t=1; t<=T; t++ )
    {
        LLI u,l,cnt=0;
        scanf("%lld%lld",&u,&l);
        if( u == 1 ) printf("Case %lld: %lld\n",t,sav[l]);
        else printf("Case %lld: %lld\n",t,(sav[l]-sav[u-1]));
    }
    return 0;
}

