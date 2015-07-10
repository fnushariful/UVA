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
#define RADIANS(x)       (((1.0 * x * PI) / 180.0))
#define DEGREES(x)       (((x * 180.0) / (1.0 * PI)))



template<class T> inline T GCD(T a,T b)
{
    if ( a < 0 ) return GCD(-a,b);
    if ( b < 0 ) return GCD(a,-b);
    return (b == 0) ? a :GCD(b,a%b);
}

main()
{
    int T;
    scanf("%d",&T);
    for( int t=1; t<=T; t++ )
    {
        LLI n,ar[100009],x,y,cnt=1,mx=1;
        scanf("%lld",&n);
        if( n == 0 )
        {
            printf("-1\n");
            continue;

        }
        scanf("%lld",&y);
        for( int i=0; i<n-1; i++ )
        {
            scanf("%lld",&x);
            if( GCD(y,x) == 1 ) cnt++;
            else cnt=1;
            if( mx < cnt ) mx=cnt;
            y=x;
        }
        if( cnt == mx and cnt == 1  ) printf("-1\n");
        else printf("%lld\n",mx);
    }
}
