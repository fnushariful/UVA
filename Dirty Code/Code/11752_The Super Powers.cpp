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
#define MX  1009
#define RADIANS(x)       (((1.0 * x * PI) / 180.0))
#define DEGREES(x)       (((x * 180.0) / (1.0 * PI)))

bool status[MX];

ULLI fastExpo( ULLI b, ULLI p)
{
    ULLI res=1,x=b;
    while(p)
    {
        if(p&1) res*=x;
        x*=x;
        p=p>>1;
    }
    return res;
}

ULLI prime[MX];
ULLI k;
void sieve()
{
    LLI sqrtN=sqrt(MX);
    status[1]=0;
    status[2]=0;
    for( LLI i=4; i<=MX; i+=2 ) status[i]=1;
    for( LLI i=3; i<=sqrtN; i+=2 )
    {
        if(!status[i])
        {
            for( LLI j=i*i; j<=MX; j+=i+i )
                status[j]=1;
        }
    }
    k=1;
    prime[0]=2;
    for( LLI i=3; i<=MX; i+=2 )
    {
        if( !status[i] )
            prime[k++]=i;
    }
}

int main()
{
    sieve();
    set<ULLI> prt;
    ULLI n=18446744073709551615;
    ULLI lim=1<<16;
    for( int i=2; i<=lim; i++ )
    {
        ULLI cnt=log(n)/log(i);
        ULLI j=1;
        while( j<=cnt )
        {
            if( status[j] == 1 )
            {
                if( fastExpo(i,j)<=n && fastExpo(i,j) != 0 )
                {
                    ULLI val=fastExpo(i,j);
                    prt.insert(val);
                }
                else break;
            }
            j++;
        }
    }
    prt.insert(1);
    for( set<ULLI>::iterator it=prt.begin(); it!=prt.end(); ++it )
        cout<<*it<<endl;
    return 0;
}
