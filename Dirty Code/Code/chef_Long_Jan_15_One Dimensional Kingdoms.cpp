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
#define MX 100009
#define RADIANS(x)       (((1.0 * x * PI) / 180.0))
#define DEGREES(x)       (((x * 180.0) / (1.0 * PI)))

bool cmp( pLLI x, pLLI y )
{
    if( x.xx == y.xx ) return x.yy>y.yy;
    return x.xx<y.xx;
}

pLLI ar[MX],inp[MX];

int main()
{
    int T;
    scanf("%d",&T);
    for( int t=1; t<=T; t++ )
    {
        LLI n,a,b,k=0;
        scanf("%lld",&n);
        for( int i=0; i<n; i++ )
        {
            scanf("%lld%lld",&a,&b);
            inp[i].xx=a,inp[i].yy=b;
        }
        sort(inp,inp+n,cmp);
        for( int i=0; i<n; i++ )
        {
            bool ok=false;
            a=inp[i].xx,b=inp[i].yy;
            for( int j=0; j<k; j++ )
            {
                if( ar[i].xx<=a && a<= ar[j].yy )
                {
                    ar[j].yy=max(ar[j].yy,b);
                    ar[j].xx=min(ar[j].xx,a);
                    ok=true;
                    break;
                }
            }
            if( !ok ) ar[k].xx=a,ar[k].yy=b,k++;
        }
        printf("%lld\n",k);
        fill(inp,0);
        fill(ar,0);
    }
    return 0;
}
