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
#define MX 10000
#define RADIANS(x)       (((1.0 * x * PI) / 180.0))
#define DEGREES(x)       (((x * 180.0) / (1.0 * PI)))

LLI prime[MX];
bool status[MX];

void sieve()
{
    LLI sqrtN=sqrt(MX);
    for( int i=3; i<=sqrtN; i+=2 )
    {
        if(!status[i])
        {
            for(int j=i*i; j<=MX; j+=i+i ) status[j]=1;
        }
    }
    prime[0]=2;
    int k=1;
    for( int i=3; i<=MX; i+=2 )
    {
        if( !status[i] )
            prime[k++]=i;
    }
}

pair<LLI,LLI> stor[10000];
void fact()
{
    for( int k=1; k<=1000; k++ )
    {
        LLI m=k,sum=1;
        for( LLI i=0; prime[i]*prime[i]<=k; i++ )
        {
            LLI cnt=0;
            if( m%prime[i] == 0 )
            {
                while(m%prime[i] == 0 )
                {
                    m/=prime[i];
                    cnt++;
                }
            }
            sum*=(cnt+1);
        }
        if( m> 1 ) sum*=2;
        // debug(sum);
        stor[k].xx=k;
        stor[k].yy=sum;
    }
}

bool cmp(pair<LLI,LLI> x, pair<LLI,LLI> y )
{
    if( x.yy == y.yy ) return x.xx>y.xx;
    return x.yy<y.yy;
}

int main()
{
    sieve();
    fact();
    sort(stor,stor+1001,cmp);
    LLI val;
    int T;
    scanf("%d",&T);
    for( LLI t=1; t<=T; t++ )
    {
        scanf("%d",&val);
        printf("Case %lld: %lld\n",t,stor[val].xx);
    }
    return 0;
}

