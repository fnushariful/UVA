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

#define MOD 4294967296
#define MX 100000009
#define RADIANS(x)       (((1.0 * x * PI) / 180.0))
#define DEGREES(x)       (((x * 180.0) / (1.0 * PI)))

int status[(MX/32)+2];
bool Check(int N,int pos)
{
    return (bool)(N & (1<<pos));
}
int Set(int N,int pos)
{
    return N=N | (1<<pos);
}
int N =MX;
LLI prime[5762000];
void sieve()
{
    int i, j, sqrtN;
    sqrtN = int( sqrt( N ) );
    for( i = 3; i <= sqrtN; i += 2 )
    {
        if( Check(status[i>>5],i&31)==0)
        {
            for( j = i*i; j <= N; j += (i<<1) )
            {
                status[j>>5]=Set(status[j>>5],j & 31)   ;
            }
        }
    }
    prime[0]=2;
    LLI k=1;
    for(i=3; i<=N; i+=2)
        if( Check(status[i>>5],i&31) == 0 )
        {
            prime[k++]=i;
        }
}

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

LLI fun(LLI n)
{
    LLI sqrtN=sqrt(n),ret=1,i=0;
    for( i=0; prime[i]<=sqrtN; i++ )
    {
        LLI val=1,j;
        for( j=1; ; j++ )
        {
            if( fastExpo(prime[i],j) <= n ) val=fastExpo(prime[i],j);
            else break;
        }
        ret=((ret%MOD)*(val%MOD))%MOD;
    }
    for( ; prime[i]<=n; i++ )
    {
        ret=((ret%MOD)*(prime[i]%MOD))%MOD;
    }
    printf("%lld\n",ret);
}

int main()
{
    sieve();
    LLI N,T;
    scanf("%lld",&T);
    for( int t=1; t<=T; t++ )
    {
        scanf("%lld",&N);
        printf("Case %d: ",t);
        fun(N);
    }
    return 0;
}
