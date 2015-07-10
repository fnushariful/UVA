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

main()
{
    int n,k,l,r,s,t;
    while(cin>>n>>k>>l>>r>>s>>t)
    {
        int val=t/k;
        if( val*k == t )
        {
            n-=k;
            for( int i=0; i<k; i++ ) cout<<val<<" ";
        }
        else
        {
            for( int i=0; i<k-1; i++ ) cout<<val<<" ";
            cout<<t-val*(k-1)<<" ";
            n-=k;
        }
        int p=s-t;
        int avg=(l+r)/2;
        if( avg*n == p )
            for( int i=0; i<n; i++ ) cout<<avg<<" ";
        else
        {
            int val=p/n;
            if(  val*n == p )
                for( int i=0; i<n; i++ ) cout<<val<<" ";

        }
        cout<<endl;
    }
}
