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

vector<int>v[100010],stor;
int vist[100010];

void dfs(int val)
{
    if( vist[val] ) return;
    vist[val]=1;
    for( int i=0; i<v[val].size(); i++ )
    {
        dfs(v[val][i]);
    }
}

int main()
{
    int N,T,E,x,y;
    scanf("%d",&T);
    for( int t=1; t<=T; t++ )
    {
        scanf("%d%d",&N,&E);
        for( int i=0; i<E; i++ )
        {
            scanf("%d%d",&x,&y);
            v[x].PB(y);
        }
        for( int i=1; i<=N; i++ )
        {
            if( vist[i] == 0 )
            {
                dfs(i);
                stor.PB(i);
            }
        }
        fill(vist,0);
        int res=0;
        for( int i=stor.size()-1; i>=0; i-- )
        {
            if( vist[stor[i]] == 0 )
            {
                dfs(stor[i]);
                res++;
            }
        }
        printf("%d\n",res);
        for( int i=0; i<=N; i++ )
            v[i].clear();
        fill(vist,0);
        stor.clear();
    }
    return 0;
}

