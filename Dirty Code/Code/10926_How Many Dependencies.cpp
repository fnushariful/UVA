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
#define MX 10000
#define RADIANS(x)       (((1.0 * x * PI) / 180.0))
#define DEGREES(x)       (((x * 180.0) / (1.0 * PI)))

VI ans,depends[MX];
int dp[1000];
int take(int p)
{
    if( dp[p] != 0 ) return dp[p];
    if( dp[p] == 0 )
    {
        int sum=0;
        for( int i=0; i<depends[p].size(); i++ )
        {
            dp[depends[p][i]]=take(depends[p][i]);
            sum+=1+dp[depends[p][i]];
        }
        return dp[p]=sum;
    }
}

int main()
{
    int x,y,n,m,a;
    //freopen("output.txt","w",stdout);
    while(cin>>n && n!=0 )
    {
        for( int i=1; i<=n; i++ )
        {
            cin>>a;
            for( int j=0; j<a; j++ )
            {
                cin>>y;
                depends[i].PB(y);
            }
        }
        int mx=INT_MIN,pos;
        for( int i=1; i<=n; i++ ) take(i);
        for( int i=1; i<=n; i++ )
            if( mx < dp[i] )
            {
                pos=i;
                mx=dp[i];
            }
        cout<<pos<<endl;
        memset(dp,0,sizeof dp);
        for( int i=0; i<=n; i++ )
            depends[i].clear();
    }
    return 0;
}


