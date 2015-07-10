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

int best=1023,N,val;
int cost[25][25];
int dp[25][1048675];
int dfs(int last,int bit)
{
    int ans=best;
    //if( dp[last][bit]!= -1 ) return dp[last][bit];
    //debug(last);
    debug(bit);
    if( bit == (1<<N)-1 )
    {
        int x=last;
        int y=1;
        debug(cost[x][y]);
        debug(bit);
        return cost[x][y];
    }
    for( int i=2; i<=N; i++ )
    {
        //cout<<bit<<" "<<((1<<i)-1)<<endl;

        if( !(bit&(1<<(i-1)) ) )
        {
            //cout<<bit<<" "<<((1<<i)-1)<<endl;
            int ret=cost[last][i]+dfs(i,bit|(1<<(i-1)));
            //cout<<ret-cost[last][i]<<endl;
            ans=min(ans,ret);
        }
    }
    return dp[last][bit]=ans;
}


int main()
{
    int x,y,w,E;
    scanf("%d%d",&N,&E);
    fill(dp,-1);
    for( int i=0; i<N; i++ )
    {
        for(int j=0; j<N; j++ )
            cost[i][j]=0;
    }
    for( int i=0; i<E; i++ )
    {
        scanf("%d%d%d",&x,&y,&w);
        cost[x][y]=w;
        cost[y][x]=w;
    }
    cout<<dfs(1,1)<<endl;
    for( int i=0; i<=5; i++ )
    {
        for( int j=0; j<=31; j++ )
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}


/*
1 2 4
1 3 5
1 4 3
1 5 1
2 3 9
2 4 7
2 5 3
3 4 4
3 5 2
4 5 10
*/

