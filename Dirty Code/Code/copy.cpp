///===========================///
///                           ///
///    ID     : FlaminRage    ///
///    School : JU            ///
///                           ///
///===========================///

#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<string>
#include<algorithm>
#include<sstream>
#include<fstream>
#include<map>
#include<vector>
#include<queue>
#include<set>
#include<stack>
#include<utility>
#include<iomanip>

#define S(a) scanf("%d",&a)
#define P(a) printf("%d",a)
#define PS(s) printf(s)

#define S2(a,b) scanf("%d%d",&a,&b)
#define S3(a,b,c) scanf("%d%d%d",&a,&b,&c)

#define SLL(a) scanf("%lld",&a)
#define PLL(a) printf("%lld",a)
#define SLL2(a,b) scanf("%lld%lld",&a,&b)
#define SLL3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)

#define PCASE() printf("Case %d: ",kk++)
#define PCASENL() printf("Case %d:\n",kk++)

#define NL puts("")

#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rev(i,a,b) for(int i=a;i>=b;i--)

#define all(a) a.begin(),a.end()
//#define REV(a) reverse(all(a))

#define COUNTBIT(x) __builtin_popcount(x)

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rev(i,a,b) for(int i=a;i>=b;i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define pi (2.0*acos(0.0))
#define SET(a) memset(a,-1,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define in(a,x,y) (a>=x && a<=y)
#define eq(a,b) (_abs(a-b)<eps)
#define less(a,b) (a+eps<b)
#define great(a,b) (a>b+eps)
#define xx first
#define yy second
#define root 1

using namespace std;

int ts,kk=1,True=1;

typedef long long ll;
typedef unsigned long long ull;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vii;

template< class T > inline T _abs(T n)
{
    return (n < 0 ? -n : n);
}
template< class T > inline T _max(T a, T b)
{
    return (a > b ? a : b);
}
template< class T > inline T _min(T a, T b)
{
    return (a < b ? a : b);
}
template< class T > inline T _sq(T x)
{
    return x * x;
}
template< class T > inline T _pow(T x,T y)
{
    T z=1;
    rep(i,1,y)
    {
        z*=x;
    }
    return z;
}
template< class T > inline T _gcd(T a,T b)
{
    a=_abs(a);
    b=_abs(b);
    if(!b) return a;
    return _gcd(b,a%b);
}
template< class T > inline T _lcm(T a,T b)
{
    a=_abs(a);
    b=_abs(b);
    return (a/_gcd(a,b))*b;
}

template< class T > inline T _extended(T a,T b,T &x,T &y)
{
    a=_abs(a);
    b=_abs(b);
    T g,x1,y1;
    if(!b)
    {
        x=1;
        y=0;
        g=a;
        return g;
    }
    g=_extended(b,a%b,x1,y1);
    x=y1;
    y=x1-(a/b)*y1;
    return g;
}

template< class T > inline T getbit(T x,T i)
{
    T t=1;
    return (x&(t<<i));
}
template< class T > inline T setbit(T x,T i)
{
    T t=1;
    return (x|(t<<i));
}
template< class T > inline T resetbit(T x,T i)
{
    T t=1;
    return (x&(~(t<<i)));
}
template< class T > inline T togglebit(T x,T i)
{
    T t=1;
    return (x^(t<<i));
}


///===========================///
///      //CONSTANT//         ///
///  power    0123456789      ///
#define MX  ( 50   + 3 )
#define LOGMX 18
#define MOD   1000000007
#define inval 1000000005
#define inf   2000000000
#define eps 1e-8
///                           ///
///===========================///

template< class T > inline T _bigmod(T n,T m)
{
    T ans=1,mult=n;
    while(m)
    {
        if(m & 1)ans=(ans*mult)%MOD;
        m>>=1;
        mult=(mult*mult)%MOD;
    }
    ans%=MOD;
    return ans;
}

template< class T > inline T _modinv(T x)
{
    return _bigmod(x,(T) (MOD-2));
}

///===============///
///End of template///
///===============///

int dp[2][MX];

int func(int prev,int pos)
{
    if(!pos) return 1;
    int &ret=dp[prev][pos];
    if(ret!=-1) return ret;
    ret=0;

    ret+=func(0,pos-1);

    if(!prev) ret+=func(1,pos-1);

    return ret;
}

int main()
{
    int tot=0;
    SET(dp);
    rep(i,0,MX-1)
    {
        tot+=func(1,i);
//    cout<<i<<" ";
        if(tot>1000000000) break;
    }
    for( int i=0; i<2; i++ )
    {
        for( int j=0; j<53; j++ )
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    S(ts);
    while(ts--)
    {
        int n;
        S(n);
        PCASE();

        P(1);

        rep(k,0,MX-1)
        {
            if(n<=func(1,k))
            {
//            cout<<k<<endl;
                rev(i,k-1,0)
                {
                    rep(j,0,1)
                    {
                        if(n<=func(j,i))
                        {
                            P(j);
                            break;
                        }
                        else n-=func(j,i);
                    }
                }
                break;
            }
            else n-=func(1,k);
        }

        NL;
    }

    return 0;
}
