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

LLI n,s,ar[100009];

LLI sliding_window( LLI n,LLI s )
{
    LLI j=1,res=INT_MAX,sum=0;
    for( int i=1; i<=n; i++ )
    {
        if( sum+ar[i]<= s )
        {
            sum+=ar[i];
        }
        //cout<<sum<<" "<<ar[i]<<endl;
        while( sum >= s )
        {
            sum-=ar[j];
            j++;

        }
        cout<<j<<" "<<sum<<endl;
        res=min(res,i-j+1);
    }
    cout<<res<<endl;
}


int main()
{
    while(scanf("%lld%lld",&n,&s)==2)
    {
        for( int i=1; i<=n; i++ ) scanf("%lld",&ar[i]);
        //for( int i=1; i<=n; i++ ) cout<<ar[i]<<" ";
        sliding_window(n,s);
    }
    return 0;
}


/*

10 15
5 1 2 5 10 7 2 3 2 4


*/
