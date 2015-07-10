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

bool b[105],g[105];
int main()
{
    LLI n,m;
    while(cin>>n>>m)
    {
        LLI x,y,val;
        cin>>x;
        for( int i=0; i<x; i++ ) cin>>val,b[val]=1;
        cin>>y;
        for( int i=0; i<y; i++ ) cin>>val,g[val]=1;
        LLI cnt=0;
        for( LLI i=0; i<100009 ; i++ )
        {
            LLI bf,gf;
            bf=i%n,gf=i%m;
            if( b[bf] == 1 || g[gf] == 1 )
            {
                b[bf]=1,g[gf]=1;
            }
            for( int j=0; j<n; j++ ) if( b[j] == 1 ) cnt++;
            for( int j=0; j<m; j++ ) if( g[j] == 1 ) cnt++;
            if( cnt == n+m )
            {
                cout<<"Yes"<<endl;
                return 0;
            }
            cnt=0;
        }
        cout<<"No"<<endl;
    }
    return 0;
}

