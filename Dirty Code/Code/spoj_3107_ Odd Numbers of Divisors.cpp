#include <bits/stdc++.h>
#include <tr1/unordered_map>

using namespace std;
using namespace tr1;

#define SYN ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long int LLI;
typedef unsigned long long int ULLI;
#define ALL(c) c.begin(), c.end()

#define debug(x)         cerr<<__LINE__<<" "<<#x<<" "<<x<<endl;
#define IMAX ((unsigned)1<<31)-1
#define eps 1e-11
#define fill(a,v) memset(a,v,sizeof (a))
#define SZ(X) ((int)X.size())
#define VLLI vector<LLI>
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
#define MX 1000009
#define RADIANS(x)       (((1.0 * x * PI) / 180.0))
#define DEGREES(x)       (((x * 180.0) / (1.0 * PI)))


unordered_map<LLI, vector<LLI> > pr;

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


LLI prime[MX];
bool status[MX];

void sieve()
{
    for( LLI i=3; i<=MX; i+=2 )
    {
        if( !status[i] )
            for( LLI j=i*i; j<=MX; j+=i+i )
                status[j]=1;
    }
    LLI k=1;
    prime[0]=2;
    for( LLI i=3; i<=MX; i+=2 )
        if(!status[i])
            prime[k++]=i;
    //for( int i=0; i<MX; i++ ) cout<<prime[i]<<" ";
}

LLI fact( LLI n )
{
    LLI sum=1;
    for( LLI i=0; prime[i]*prime[i]<=n; i++ )
    {
        LLI cnt=0;
        while(n%prime[i] == 0 )
        {
            n/=prime[i];
            cnt++;
        }
        sum*=(cnt+1);
    }
    if( n > 1 ) sum*=2;
    return sum;
}

LLI solve(LLI k, LLI lo, LLI hi)
{
    return upper_bound(ALL(pr[k]), hi) - lower_bound(ALL(pr[k]), lo);
}


int main()
{
    LLI T;
    sieve();
    LLI n;
    for( LLI i=1; i<=100009; i++ )
    {
        //LLI val=fastExpo(i,2);
        pr[fact(i*i)].PB(i*i);
        //cout<<pr[i].xx<<" "<<pr[i].yy<<endl;
    }
    LLI k,l,u;
    scanf("%lld",&T);
    for( LLI t=1; t<=T; t++ )
    {
        scanf("%lld%lld%lld",&k,&l,&u);
        printf("%lld\n",solve(k,l,u));

    }
    return 0;
}
