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
#define MSLI map<string,LLI>
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



LLI pas[5001][5001];
void pascals(LLI n)
{
    LLI i,j;
    pas[0][0]=1;
    pas[1][0]=pas[1][1]=1;
    for(i=2; i<=n; i++)
    {
        pas[i][0]=1;
        for(j=1; j<i; j++)
        {
            pas[i][j]=((pas[i-1][j-1])%3+(pas[i-1][j])%3)%3;
        }
        pas[i][j]=1;
    }
}


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

int main()
{
    int T;
    LLI n;
    pascals(5001);
    scanf("%d",&T);
    for( int t=1; t<=T; t++ )
    {
        scanf("%lld",&n);
        LLI sum=1;
        //fill(dp,-1);
        for( int i=1; i<=n; i++ )
        {
            LLI val=pas[n][i];
            //cout<<val<<endl;
            sum=((sum%MOD)+(val%MOD))%MOD;
        }
        printf("%lld\n",sum);
    }
    return 0;
}
