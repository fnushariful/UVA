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
#define VI vector<LLI>
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
#define MX 400009
#define RADIANS(x)       (((1.0 * x * PI) / 180.0))
#define DEGREES(x)       (((x * 180.0) / (1.0 * PI)))

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
    LLI mx=INT_MIN;
    for( LLI i=0; prime[i]*prime[i]<=n; i++ )
    {
        LLI cnt=0;
        while(n%prime[i] == 0 )
        {
            n/=prime[i];
        }
        mx=max(prime[i],mx);
    }
    if( n > 1 ) mx=max(n,mx);
    return mx;
}

int main()
{
    LLI n;
    while(cin>>n)
    {
        VI v;
        if( n == 1 ) cout<<1<<endl;
        else if( n == 0 ) cout<<10<<endl;
        else
        {
            for( int i=9; i>1; i-- )
            {
                while(n%i == 0 )
                {
                    v.PB(i);
                    n/=i;
                    //cout<<i<<endl;
                }
            }
            if( n > 1 ) cout<<-1<<endl;
            else
            {
                sort(v.begin(),v.end());
                for( int i=0; i<v.size(); i++ ) cout<<v[i];
                cout<<endl;
            }
        }
    }
    return 0;
}
