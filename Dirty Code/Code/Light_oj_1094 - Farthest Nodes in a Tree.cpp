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

vector<int>G[30009],cost[30009];
int mx=INT_MIN,visit[30009],node;
void dfs( int n, int val )
{
    if( visit[n] == 1 ) return;
    visit[n]=1;

    for( int i=0; i<G[n].size(); i++ )
    {
        int m=G[n][i];
        int c=cost[n][i];
        if( visit[m] == 0 )
        {
            dfs(m,c+val);
            if( c+val > mx )
            {
                mx=val+c;
                node=m;
            }
        }
    }
}

int main()
{
    int n,x,y,val;
    int T;
    scanf("%d",&T);
    for( int t=1; t<=T; t++ )
    {
        scanf("%d",&n);
        for( int i=0; i<n-1; i++ )
        {
            scanf("%d%d%d",&x,&y,&val);
            G[x].PB(y);
            G[y].PB(x);
            cost[x].PB(val);
            cost[y].PB(val);
        }
        dfs(x,0);
        fill(visit,0);
        dfs(node,0);
        printf("Case %d: %d\n",t,mx);
        mx=INT_MIN;
        for( int i=0; i<n; i++ )
        {
            G[i].clear();
        }
        fill(visit,0);
        fill(cost,0);
    }
    return 0;
}

