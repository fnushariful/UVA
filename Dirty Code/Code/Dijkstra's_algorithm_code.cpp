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
#define MX  100005
#define RADIANS(x)       (((1.0 * x * PI) / 180.0))
#define DEGREES(x)       (((x * 180.0) / (1.0 * PI)))


vector<int> edge[MX],cost[MX];
const int infinity = 1000000000;

struct data
{
    int city, dist;
    bool operator < ( const data& p ) const
    {
        return dist > p.dist;
    }
};

int dijkstra(int source, int destination)
{
    int d[MX];
    for(int i=0; i<MX; i++) d[i] = infinity;

    priority_queue<data> q;
    data u,v;
    u.city = source, u.dist = 0;
    q.push(u);
    d[source] = 0;

    while( !q.empty() )
    {
        u=q.top();
        q.pop();
        int ucost=d[u.city];
        for(int i=0; i<edge[u.city].size(); i++)
        {
            v.city = edge[u.city][i], v.dist = cost[u.city][i] + ucost;
            if( d[v.city] > v.dist )
            {
                d[v.city] = v.dist;
                q.push( v );
            }
        }
    }
    return d[destination];
}


int main()
{
    int E,N,src,des,T;
    scanf("%d",&T);
    for( int t=1; t<=T; t++ )
    {
        scanf("%d%d%d%d",&N,&E,&src,&des);
        for( int i=0; i<E; i++ )
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            edge[u].PB(v);
            edge[v].PB(u);
            cost[u].PB(w);
            cost[v].PB(w);
        }
        LLI prt=dijkstra(src,des);
        if( prt == infinity )
            printf("Case #%d: unreachable\n",t);
        else
            printf("Case #%d: %lld\n",t,prt);
        for( int i=0; i<E; i++ )
            edge[i].clear(),cost[i].clear();
    }
    return 0;
}

