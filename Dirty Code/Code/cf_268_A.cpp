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

int main()
{
    int n,x,y,ar[105],pr[105],p;
    while(cin>>n)
    {
        for( int i=1; i<=n; i++ ) ar[i]=1;
        cin>>x;
        for( int i=1; i<=x; i++ )
        {
            cin>>p;
            pr[p]=1;
        }
        cin>>y;
        for( int i=1; i<=y; i++  )
        {
            cin>>p;
            pr[p]=1;
        }
        int cnt=0;
        for( int i=1; i<=n; i++ )
            if( ar[i] == pr[i] )
                cnt++;
            else
            {
                cout<<"Oh, my keyboard!"<<endl;
                return 0;
            }
        //cout<<cnt<<endl;
        if( cnt == n ) cout<<"I become the guy."<<endl;
    }
}
