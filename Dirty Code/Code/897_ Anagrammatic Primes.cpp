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
#define MX 1001
#define RADIANS(x)       (((1.0 * x * PI) / 180.0))
#define DEGREES(x)       (((x * 180.0) / (1.0 * PI)))

LLI prime[MX];
bool status[MX];

void sieve()
{
    LLI sqrtN=double(sqrt(MX));
    for( LLI i=4; i<=MX; i+=2 ) status[i]=1;
    for( int i=3; i<sqrtN; i+=2 )
    {
        if( !status[i] )
            for(int j=i*i; j<=MX; j+=i+i)
                status[j]=1;
    }
    prime[0]=2;
    LLI k=1;
    for( int i=3; i<=MX; i+=2 )
        if(!status[i])
            prime[k++]=i;
}

vector<LLI> agam;

void is_ana( LLI num )
{
    vector<LLI>v;
    LLI sum=0,store=num;
    while(num>0)
    {
        sum=num%10;
        num/=10;
        v.PB(sum);
    }
    sort(v.begin(),v.end());
    LLI cnt=0,pr=0;
    do
    {
        cnt++;
        LLI n=0;
        for( int i=0; i<v.size(); i++ ) n=n*10+v[i];
        if(!status[n])
        {
            pr++;
        }
    }
    while(next_permutation(v.begin(),v.end()));
    if( pr == cnt )
    {
        agam.PB(store);
    }
}

int main()
{
    sieve();
    for( int i=0; i<1000; i++ )
    {
        is_ana(prime[i]);
    }
    LLI n;
    while(scanf("%lld",&n) && n )
    {
        bool ok=0;
        LLI len=agam.size(),store=0;
        if( n < MX )
        {
            for( int i=0; i<len; i++ )
            {
                if( n < agam[i] )
                {
                    store=agam[i];
                    ok=1;
                    break;
                }
            }
        }
        if(ok)
        {
            int l=log10(store)+1;
            n=log10(n)+1;
            if( store && l>n )
                store=0;
        }
        printf("%lld\n",store);
    }
    return 0;
}
