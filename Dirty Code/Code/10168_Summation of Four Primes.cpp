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
#define MX 10000009
#define RADIANS(x)       (((1.0 * x * PI) / 180.0))
#define DEGREES(x)       (((x * 180.0) / (1.0 * PI)))

LLI prime[MX];
bool status[MX];

void sieve()
{
    LLI sqrtN=sqrt(MX);
    for( LLI i=4; i<=MX; i+=2 ) status[i]=1;
    for( LLI i=3; i<=sqrtN; i+=2 )
    {
        if( !status[i] )
            for( LLI j=i*i; j<=MX; j+=i+i )
                status[j]=1;
    }
    status[2]=0;
    status[0]=status[1]=1;
}

void prt(LLI n)
{
    if( !status[n-2] )
    {
        printf(" %lld 2\n",n-2);
        return ;
    }

    for(LLI i=3; i<=MX; i+=2 )
    {
        if( !status[n-i] && !status[i] )
        {
            printf(" %lld %lld\n",n-i,i);
            return ;
        }
    }
}

int main()
{
    sieve();
    LLI n;
    while(scanf("%lld",&n) == 1)
    {
        if( n<8 )
        {
            printf("Impossible.\n");
            continue;
        }
        else if( n%2 )
        {
            printf("2 3");
            prt(n-5);
        }
        else
        {
            printf("2 2");
            prt(n-4);
        }
    }
    return 0;
}
