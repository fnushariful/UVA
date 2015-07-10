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

int main()
{
    int n,m;
    vector<string> v[3009];
    while(cin>>n>>m)
    {
        string st,str;
        for( int i=0; i<m; i++ )
        {
            cin>>st>>str;
            v[i].PB(st),v[i].PB(str);
        }
        for(int i=0; i<n; i++ )
        {
            cin>>st;
            for( int i=0; i<m; i++ )
            {
                if( v[i][0] == st or v[i][1] == st )
                {
                    if( v[i][0].size() == v[i][1].size() ) cout<<v[i][0];
                    else if( v[i][0].size() > v[i][1].size() ) cout<<v[i][1];
                    else cout<<v[i][0];
                    cout<<" ";
                }
            }
        }
        cout<<endl;
                 //
    }
             return 0;
}
