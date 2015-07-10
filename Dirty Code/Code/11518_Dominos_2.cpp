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

vector<int>v[10009];
int vist[10009],cnt;

void dfs( int i )
{
    if( vist[i] == 0 )
    {
        vist[i]=1;
        //debug(i);
        for( int j=0; j<v[i].size(); j++ )
        {
            int val=v[i][j];
            //debug(val);
            if( vist[val] == 0 )
            {
                dfs(val);
            }
        }
    }
}

int main()
{
    //freopen("output.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for( int t=1; t<=T; t++ )
    {
        int n,m,d,x,y,val;
        scanf("%d%d%d",&n,&m,&d);
        for( int i=0; i<m; i++ )
        {
            scanf("%d%d",&x,&y);
            v[x].PB(y);
        }
        for( int i=0; i<d; i++ )
        {
            scanf("%d",&val);
            dfs(val);
        }
        for( int i=0; i<=n; i++ ) if( vist[i] == 1 ) cnt++;
        printf("%d\n",cnt);
        cnt=0;
        fill(vist,0);
        for(int i=0; i<=n; i++ )
            v[i].clear();
    }
    return 0;
}

