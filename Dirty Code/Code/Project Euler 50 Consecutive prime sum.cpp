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

#define MOD 1000000007
#define RADIANS(x)       (((1.0 * x * PI) / 180.0))
#define DEGREES(x)       (((x * 180.0) / (1.0 * PI)))
#define mx 10000000

LLI pr[mx+10];
bool ar[mx+10];


LLI modulo(LLI base, LLI exponent, LLI mod)
{
    LLI x = 1;
    LLI y = base;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            x = (x * y) % mod;
        y = (y * y) % mod;
        exponent = exponent / 2;
    }
    return x % mod;
}

/*
 * Fermat's test for checking primality
 */
bool Fermat(LLI p, int iterations)
{
    if (p == 1)
    {
        return false;
    }
    for (int i = 0; i < iterations; i++)
    {
        LLI a = rand() % (p - 1) + 1;
        if (modulo(a, p - 1, p) != 1)
        {
            return false;
        }
    }
    return true;
}



void seive()
{
    for( LLI i=3; i<=mx; i+=2 )
    {
        if( ar[i] == 0 )
            for(LLI j=i*i; j<=mx; j+=2*i )
                ar[j]=1;
    }
    LLI k=1;
    pr[0]=2;
    for( LLI i=3; i<=mx; i+=2 )
        if( ar[i] == 0 )
            pr[k++]=i;
    cout<<pr[k-1]<<endl;
}

main()
{
    seive();
    // for( LLI i=0; i<=100; i++ ) cout<<pr[i]<<" ";
    LLI n;
    while(cin>>n)
    {
        LLI sum=0;
        LLI mex=INT_MIN,pos=0,last=0;
        for( LLI i=0; pr[i]<n/2; i++ )
        {
            sum=pr[i];
            //cout<<sum<<" ";
            LLI cnt=1;
            for( int j=i+1; j<=n/2; j++ )
            {
                sum+=pr[j];
                //cout<<pr[j]<<" ";
                cnt++;
                if( Fermat(sum,50)and mex < sum and sum <= n and sum%2 == 1)
                {
                    if( cnt> pos ) pos=cnt,mex=sum,last=pr[j];
                    cout<<pr[i]<<" "<<mex<<" "<<pos<<endl;
                }
            }
         }
         cout<<mex<<" "<<pos<<" "<<last<<endl;
    }
}
