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
#define MX 4294967296
#define RADIANS(x)       (((1.0 * x * PI) / 180.0))
#define DEGREES(x)       (((x * 180.0) / (1.0 * PI)))

LLI fastExpo( LLI b, LLI p)
{
    LLI res=1,x=b;
    while(p)
    {
        if(p&1) res*=x;
        x*=x;
        p=p>>1;
    }
    return res;
}

template<class T> inline T BIGMOD( T n,T m,T mod )
{
    ULLI ans = 1;
    ULLI k = n;
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

bool isprime(ULLI p)
{
    if(p < 2 || (p != 2 && !(p & 1))) return false;
    ULLI s = p - 1;
    while(!(s & 1)) s >>= 1;
    for(ULLI i = 0; i < 10; ++i)
    {
        ULLI a = rand() % (p - 1) + 1, temp = s;
        ULLI mod = ULLI(BIGMOD(ULLI(a), ULLI(temp), ULLI(p)));
        while(temp != p - 1 && mod != 1 && mod != p - 1)
        {
            mod = (ULLI(mod) * mod) % p;
            temp <<= 1;
        }
        if(mod != p - 1 && !(temp & 1)) return false;
    }
    return true;
}

int main()
{
    ULLI n;
    while( scanf("%llu",&n) && n!=0 )
    {
        ULLI val=fastExpo(2,n)-1;
        ULLI m=fastExpo(2,n-1);
        if( isprime(n) && isprime(val) ) printf("Perfect: %llu!\n",m*val);
        else if( isprime(n) && isprime(val) == 0 )
            printf("Given number is prime. But, NO perfect number is available.\n");
        else if( isprime(n) == 0 && isprime(val) == 0 ) printf("Given number is NOT prime! NO perfect number is available.\n");

    }
    return 0;
}

