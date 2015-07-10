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
#define MX 10000009
#define RADIANS(x)       (((1.0 * x * PI) / 180.0))
#define DEGREES(x)       (((x * 180.0) / (1.0 * PI)))

LLI prime[MX];

void sieve()
{
    for( LLI i=2; i<=MX; i+=2 ) prime[i]=2;
    LLI sqrtN=sqrt(MX);
    for( LLI i=3; i<=sqrtN; i+=2 )
    {
        if( !prime[i] )
            for( LLI j=i*i; j<=MX; j+=i+i )
                prime[j]=i;
    }
    for( LLI i=3; i<=MX; i+=2 )
        if( prime[i] == 0 )
            prime[i]=i;
    //prime[1]=1;
    //for( LLI i=0; i<=100; i++ ) cout<<prime[i]<<" ";
}

LLI stor[MX],dp[MX];

void optimization()
{
    //fill(stor,1);
    dp[0]=0,dp[1]=0;
    for( LLI i=2; i<=MX; i++ )
    {
        if( i/prime[i] == 1 ) stor[i]++;
        else stor[i]=1+stor[i/prime[i]];
        dp[i]=stor[i]+dp[i-1];
        //cout<<i<<" "<<dp[i]<<endl;
    }
}

int main()
{
    sieve();
    optimization();
    LLI T,n;
    scanf("%lld",&T);
    VI stor(dp,dp+MX);
    for( LLI t=1; t<=T; t++ )
    {
        scanf("%lld",&n);
        int ans=upper_bound(stor.begin(),stor.end(),n)-stor.begin();
        printf("%d\n",ans);
    }
    return 0;
}
