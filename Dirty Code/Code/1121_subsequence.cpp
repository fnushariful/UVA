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

LLI ar[MX];

LLI sliding_window(LLI n,LLI s)
{
    LLI res=INT_MAX,j=1,sum=0;
    for( LLI i=1; i<=n; i++ )
    {
        if( sum+ar[i] <= s )
            sum+=ar[i];
        else sum+=ar[i];
        if( sum >=s )
        {
            //cout<<"44 "<<i<<endl;
            while( sum >= s )
            {
                sum-=ar[j];
                j++;
                //debug(sum);
                //debug(j);
            }
            --j;
            res=min(res,(i-j)+1);
            ++j;
            //cout<<res<<endl;
        }
    }
    return res;
}


int main()
{
    LLI n,s;
    while(scanf("%lld%lld",&n,&s)==2)
    {
        for( LLI i=1; i<=n; i++ ) scanf("%lld",&ar[i]);
        LLI res=sliding_window(n,s);
        if( res == 2147483647 ) printf("0\n");
        else printf("%lld\n",res);
    }
    return 0;
}
