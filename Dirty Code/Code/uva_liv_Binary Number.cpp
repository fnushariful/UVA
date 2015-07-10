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

template<class T> string toBinary(T n)
{
    string ret="";
    while(n)
    {
        if(n%2==1) ret+='1';
        else ret+='0';
        n>>=1;
    }
    reverse(ret.begin(),ret.end());
    return ret;
}

int BitCount(unsigned int u)
{
    unsigned int uCount;

    uCount = u - ((u >> 1) & 033333333333) - ((u >> 2) & 011111111111);
    return ((uCount + (uCount >> 3)) & 030707070707) % 63;
}

int main()
{
    LLI T;
    //freopen("output.txt","w",stdout);
    scanf("%lld",&T);
    for( int t=1; t<=T; t++ )
    {
        LLI a,b,ar[1000],br[1000];
        scanf("%lld%lld",&a,&b);
        for( int i=0; i<a; i++ )
        {
            scanf("%lld",&ar[i]);
        }
        for( int i=0; i<b; i++ )
        {
            scanf("%lld",&br[i]);
        }
        for( int i=0; i<b; i++ )
        {
            LLI q=br[i],prt=INT_MAX,val;
            for( int j=0; j<a; j++ )
            {
                LLI p=ar[j];
                LLI xr=p^q;
                xr=BitCount(xr);
                if( prt > xr )
                {
                    prt=xr;
                    val=ar[j];
                }
            }
            cout<<val<<endl;
        }
    }
    return 0;
}

