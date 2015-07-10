#include <bits/stdc++.h>
#define debug(x)         cerr<<__LINE__<<" "<<#x<<" "<<x<<endl;


using namespace std;
int indeg[10005];
int topo[10005];
vector <int> g[10005];
int main()
{
    int n,m,x,y;
    int cur= 0;
    cin >> n >> m;
    for ( int i = 0; i < m; i++ )
    {
        int x,y;
        scanf("%d %d" ,&x, &y);
        indeg[y]++;
        g[x].push_back(y);
    }
    priority_queue <int> q;
    for(int i = 1; i <= n; i++)
        if (!indeg[i]) q.push(-1*i);
    int dist[100];
    memset(dist,0,sizeof dist);
    int mx=INT_MAX;
    while(!q.empty())
    {
        int nd = -1 * q.top();
        q.pop();
        for(int i = 0; i < g[nd].size(); i++)
        {
            indeg[g[nd][i]]--;
            dist[g[nd][i]]=max(dist[g[nd][i],dist[nd]+1);
                               if (!indeg[g[nd][i]])
                               q.push(-1*g[nd][i]);
        }
                       topo[cur++] = nd;
    }
    if (cur!= n)
    {
        cout << "Sandro fails." << endl;
        return 0;
    }

    for(int i = 0; i < n-1; i++)
        printf("%d ", topo[i]);
    printf("%d\n", topo[n-1]);


    return 0;
}
