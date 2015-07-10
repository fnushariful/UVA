
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

vector<int> v[1000];
int cost[1000];
int cnt;

int bfs(int src, int w)
{
    queue<int>q;
    int vist[1000]= {0};
    q.push(src);
    vist[src]=1;
    cost[src]=0;
    while(!q.empty())
    {
        int u=q.front();
        for( int i=0; i<v[u].size(); i++ )
        {
            int val=v[u][i];
            //debug(val);
            if( !vist[val] && cost[u]+1<=w )
            {
                vist[val]=1;
                cost[val]=cost[u]+1;
                cnt++;
                //debug(cnt);
                q.push(val);
            }
        }
        q.pop();
    }
    return cnt;
}

int main()
{
    int E,N,x,y,src,des,t=1;
    //freopen("output.txt","w",stdout);
    while(scanf("%d",&N) == 1)
    {
        if( N == 0 ) break;
        map<int,int>mp;
        int k=1;
        for( int i=0; i<N; i++ )
        {
            scanf("%d%d",&x,&y);
            if( mp.find(x) == mp.end() )
            {
                mp[x]=k;
                k++;
            }
            if( mp.find(y) == mp.end() )
            {
                mp[y]=k;
                k++;
            }
            v[mp[x]].PB(mp[y]);
            v[mp[y]].PB(mp[x]);
        }
        k-=1;
        while(scanf("%d%d",&src,&des) == 2 )
        {
            if( src == 0 && des == 0 ) break;
            cnt=0;
            int val=bfs(mp[src],des);
            //cout<<val<<endl;
            if( mp[src] == 0 ) val=val+1;
            else val+=1;
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",t++,k-(val),src,des);
        }
        for( int i=0; i<=k; i++ ) v[i].clear();
        mp.clear();
        fill(cost,0);
    }
    return 0;
}

