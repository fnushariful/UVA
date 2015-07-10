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
#define MX 1000000
#define RADIANS(x)       (((1.0 * x * PI) / 180.0))
#define DEGREES(x)       (((x * 180.0) / (1.0 * PI)))

template<class T> inline T BIGMOD( T n,T m,T mod )
{
    LLI ans = 1;
    LLI k = n;
    while(m)
    {
        if( m & 1)
        {
            ans *=k;
            if( ans > mod ) ans %=mod;
        }
        k *=k;
        if(k>mod) k %= mod;
        m>>=1;
    }
    return ans;
}

LLI prime[MX];
bool status[MX];

void sieve()
{
    LLI sqrtN=sqrt(MX);
    for( LLI i=4; i<=MX; i+=2 ) status[i]=1;
    for( LLI i=3; i<=sqrtN; i+=2 )
    {
        if(!status[i])
            for(LLI j=3; j<=MX; j+=2 )
                status[j]=1;
    }
}


int main()
{
    LLI p,n;
    while(scanf("%lld%lld",&p,&n)==2)
    {
        //cout<<val<<endl;
        LLI val=0;
        if( status[p] == 1 )
        {
            val=BIGMOD(n,p,p);
        }
        if( val == n ) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}

