#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for(__typeof(n) i=0; i<(n); i++)
#define FOR(i,a,b) for(__typeof(b) i=(a); i<=(b); i++)
#define CLEAR(t) memset((t), 0, sizeof(t))
typedef long double d64;
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define PI 3.1415926535897932384626433832
#define INF (1<<30)
#define eps 1e-8
#define pb push_back
#define ppb pop_back
#define bg begin
#define LL long long
#define U unsigned
#define nd 510

vector<int> edge[nd], cost[nd];
int n,m;

struct data {
    int city, dist;
    bool operator < ( const data& p ) const {
        return dist > p.dist;
    }
};

void dijkstra(int source, int d[]) {
    priority_queue<data> q;
    data u, v;
    u.city = source, u.dist = 0;
    q.push( u );
    d[ source ] = 0;

    while( !q.empty() ) {
        u = q.top();
        q.pop();
        int ucost = d[ u.city ];

        for(U i=0; i<edge[u.city].size(); i++) {
            v.city = edge[u.city][i], v.dist = cost[u.city][i];
            int res = min(d[v.city],max(v.dist,ucost));
            if(d[v.city]>res) {
                d[v.city] = res;
                q.push( v );
            }
        }
    }
}

int main() {
    //READ("in.txt");
    int t,cas=1;
    cin>>t;
    while(t--) {
        printf("Case %d:\n",cas++);
        cin>>n>>m;
        int d[n];
        memset(d,63,sizeof(d));
        REP(i,m) {
            int a,b,dis;
            scanf("%d %d %d",&a,&b,&dis);
            edge[a].pb(b);
            edge[b].pb(a);
            cost[a].pb(dis);
            cost[b].pb(dis);
        }
        int sor;
        cin>>sor;
        dijkstra(sor,d);
        REP(i,n) {
            if(d[i]==1061109567) puts("Impossible");
            else printf("%d\n",d[i]);
        }
        while(n--) {
            edge[n].clear();
            cost[n].clear();
        }
    }
    return 0;
}
