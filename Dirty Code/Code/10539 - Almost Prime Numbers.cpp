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

#define MOD 100000007
#define MX 1000009
#define RADIANS(x)       (((1.0 * x * PI) / 180.0))
#define DEGREES(x)       (((x * 180.0) / (1.0 * PI)))

LLI prime[MX];
bool status[MX];

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

void sieve()
{
    LLI sqrtN=sqrt(MX);
    for( LLI i=3; i<=sqrtN; i+=2 )
    {
        if(!status[i])
            for( LLI j=i*i; j<=MX; j+=i+i )
                status[j]=1;
    }
    LLI k=1;
    prime[0]=2;
    for( LLI i=3; i<=MX; i+=2 )
    {
        if(!status[i])
            prime[k++]=i;
    }
}

LLI stor[MOD];
LLI fun(LLI n)
{
    LLI sqrtN=sqrt(n),cnt=0,k=0;
    for( int i=0; prime[i]<=sqrtN; i++ )
    {
        LLI j=2;
        while( 1 )
        {
            if( fastExpo(prime[i],j)<=n )
            {
                stor[k++]=fastExpo(prime[i],j);
                j++;
            }
            else
            {
                break;
            }
        }
    }
    sort(stor,stor+k);
    return k;
}

int main()
{
    sieve();
    LLI n,a,b;
    LLI k=fun(1000000000001);
    LLI T;
    scanf("%lld",&T);
    for( int t=1; t<=T; t++ )
    {
        scanf("%lld%lld",&a,&b);
        LLI val=upper_bound(stor,stor+k,b)-stor;
        LLI v=lower_bound(stor,stor+k,a)-stor;
        val=val-v;
        printf("%lld\n",val);
    }
    return 0;
}
