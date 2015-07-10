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


LLI dp[66][33];

LLI nCr(int n, int r)
{
    if(n==r) return dp[n][r] = 1;
    if(r==0) return dp[n][r] = 1;
    if(r==1) return dp[n][r] = (LLI)n;
    if(dp[n][r]) return dp[n][r];
    return dp[n][r] = nCr(n-1,r) + nCr(n-1,r-1);
}


template<class T> inline T GCD(T a,T b)
{
    if ( a < 0 ) return GCD(-a,b);
    if ( b < 0 ) return GCD(a,-b);
    return (b == 0) ? a :GCD(b,a%b);
}


int main()
{
    LLI n,ar[10000];
    while(scanf("%lld",&n) == 1 && n!= 0)
    {
        for( int i=0; i<n; i++ ) scanf("%lld",&ar[i]);
        LLI cnt=0;
        for( int i=0; i<n; i++ )
        {
            for( int j=i+1; j<n; j++ )
            {
                if( GCD(ar[i],ar[j]) == 1)
                {
                    //cout<<ar[i]<<" "<<ar[j]<<endl;
                    cnt++;
                }
            }
        }
        n=nCr(n,2);
        //cout<<n<<endl;
        if( cnt == 0 ) printf("No estimate for this data set.\n");
        else
        {
            double val=((n*6.0)/cnt);
            val=sqrt(val);
            printf("%0.6lf\n",val);
        }
    }
    return 0;
}

