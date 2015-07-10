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


LLI prime[MX+10];
bool status[MX+10];

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
    for( LLI i=3; i<=sqrtN; i+= 2)
    {
        if(!status[i])
            for( LLI j=i*i; j<=MX; j+=i+i )
                status[j]=1;
    }
    prime[0]=2;
    LLI k=1;
    for( LLI i=3; i<=MX; i+=2 )
    {
        if(!status[i])
            prime[k++]=i;
    }
    //for( int i=0; i<100; i++ ) cout<<prime[i]<<" ";
}

LLI fact(LLI n,LLI m)
{
    LLI ret=1,tmp=n;
    for( LLI i=0; prime[i]*prime[i]<=tmp; i++ )
    {
        LLI cnt1=0,cnt2=0;
        while(n%prime[i] == 0 )
        {
            n/=prime[i];
            cnt1++;
        }
        while(m%prime[i] == 0 )
        {
            m/=prime[i];
            cnt2++;
        }
        if( cnt1 > cnt2 ) ret*=fastExpo(prime[i],cnt1);
    }
    if( n > 1 && m == 1 )
    {
        ret*=n;
    }
    return ret;
}

int main()
{
    sieve();
    LLI a,b,c,T;
    scanf("%lld",&T);
    for( int t=1; t<=T; t++ )
    {
        scanf("%lld%lld",&a,&c);
        if( c%a !=0 )
        {
            printf("NO SOLUTION\n");
            continue;
        }
        LLI ret=fact(c,a);
        printf("%lld\n",ret);
    }
    return 0;
}
