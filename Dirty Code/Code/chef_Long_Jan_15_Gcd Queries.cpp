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

LLI ar[MX];

template<class T> inline T GCD(T a,T b)
{
    if ( a < 0 ) return GCD(-a,b);
    if ( b < 0 ) return GCD(a,-b);
    return (b == 0) ? a :GCD(b,a%b);
}

int main()
{
    LLI T;
    scanf("%lld",&T);
    for(int t=1; t<=T; t++ )
    {
        LLI n,Q;
        scanf("%lld%lld",&n,&Q);
        for( int i=1; i<=n; i++ ) scanf("%lld",&ar[i]);
        LLI l,r;
        for( int q=1; q<=Q; q++ )
        {
            scanf("%lld%lld",&l,&r);
            LLI gcd=0;
            for( int i=1; i<l-1; i++ )
            {
                //cout<<ar[i]<<" "<<ar[i+1]<<endl;
                LLI tmp=GCD(ar[i],ar[i+1]);
                //debug(tmp);
                gcd=GCD(tmp,gcd);
                //cout<<gcd<<endl;
            }
            if( gcd == 0 && l!= 1 ) gcd=ar[1];
            LLI gd=0;
            for( int i=r+1; i<n; i++ )
            {
                LLI tmp=GCD(ar[i],ar[i+1]);
                gd=GCD(gd,tmp);
                //cout<<gd<<endl;
            }
            if( gd == 0 && r!= n) gd=ar[n];
            gcd=GCD(gd,gcd);
            printf("%lld\n",gcd);
        }
    }
    return 0;
}

/*

1
10 10
9 6 12 7 11 13 14 10000 17 17

*/
