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


template<class T> inline T GCD(T a,T b)
{
    if ( a < 0 ) return GCD(-a,b);
    if ( b < 0 ) return GCD(a,-b);
    return (b == 0) ? a :GCD(b,a%b);
}

int main()
{
    int n,m,ar[10000],x,y;
    while(cin>>n>>m)
    {
        for( int i=1; i<=n; i++ ) cin>>ar[i];
        int cnt=0;
        for( int i=0; i<m; i++ )
        {
            cin>>x>>y;
            int j;
            while( 1 )
            {
                cout<<ar[x]<<" "<<ar[y]<<endl;
                for( j=2; j<1000; j++ )
                    if( ar[x]%i == 0 && ar[y]%i == 0 )
                    {
                        ar[x]/=i;
                        ar[y]/=i;
                        cnt++;
                        debug(i);
                    }
                    else break;
                    if( j> 1000 ) break;
            }
            cout<<cnt<<endl;
        }
    }
    return 0;
}
