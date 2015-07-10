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
#define MX 1000000
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
    for( LLI i=0; i<=100; i++ ) cout<<prime[i]<<" ";
}

int main()
{
    sieve();
    return 0;
}
