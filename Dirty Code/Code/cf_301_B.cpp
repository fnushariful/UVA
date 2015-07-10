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

int main()
{
    int n,k,p,x,y,ar[1000];
    while(cin>>n>>k>>p>>x>>y)
    {
        LLI sum=0;
        bool ok=0;
        for( int i=0; i<k; i++ )
        {
            cin>>ar[i],sum+=ar[i];
            if( ar[i] == y ) ok=1;
        }
        if( sum+k >= x )
        {
            cout<<-1<<endl;
            return 0;
        }

        LLI d=x-sum;
        int len=n-k,cnt=n-k;
        if( ok )
        {
            for( int i=0; i<len; i++ ) cout<<1<<" ";
        }
        if(!ok)
        {
            len-=1;
            d-=y;
            cout<<y<<" ";
            if( d<len )
            {
                return 0;
                cout<<-1<<endl;
            }
            else for( int i=0; i<len; i++ ) cout<<1<<" ";

        }
    }
    return 0;
}

