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
#define MX 100000
#define RADIANS(x)       (((1.0 * x * PI) / 180.0))
#define DEGREES(x)       (((x * 180.0) / (1.0 * PI)))

LLI prime[MX];
bool status[MX];

void sieve()
{
    LLI sqrtN=sqrt(MX)+10;
    for( int i=3; i<sqrtN; i+=2 )
    {
        if( status[i] == 0)
            for(int j=i*i; j<=MX; j+=2*i )
                status[j]=1;
    }
    prime[0]=2;
    LLI k=1;
    for( int i=3; i<MX; i+=2 )
    {
        if( status[i] == 0 )
            prime[k++]=i;
    }
    //for( int i=0; i<100; i++ ) cout<<prime[i]<<" ";
}

pair<LLI,LLI> ar[100000];
LLI m,mx=INT_MIN,k=0;
void fact(LLI n)
{
    k=0;
    m=n;
    for( int i=0; prime[i]*prime[i]<=n; i++ )
    {
        int cnt=0;
        bool ok=0;
        while( m%prime[i] == 0 )
        {
            m/=prime[i];
            cnt++;
            ok=1;
        }
        if( ok )
        {
            ar[k].xx=prime[i];
            ar[k].yy=cnt;
            k++;
        }
    }
    if( m> 1 ) ar[k].xx=m,ar[k].yy=1,k++;
}

LLI fun( LLI N,LLI p )
{
    LLI h = 0;
    while(N!=0)
    {
        h = h + N/p;
        N = N / p;
    }
    return h;
}

int main()
{
    sieve();
    LLI n,val;
    while(scanf("%lld%lld",&n,&val) == 2 )
    {
        fill(ar,0);
        fact(val);
        bool ok=0;
        //debug(k);
        //for( int i=0; i<=k; i++ ) cout<<ar[i].xx<<" "<<ar[i].yy<<endl;
        for( int i=0; i<k; i++ )
        {
            //debug(ar[i].xx);
            LLI ret=fun(n,ar[i].xx);
            if( ret < ar[i].yy )
            {
                ok=1;
                break;
            }
        }
        if( ok )
            printf("%lld does not divide %lld!\n",val,n);
        else printf("%lld divides %lld!\n",val,n);
    }
    return 0;
}

