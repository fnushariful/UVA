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

int root[50009];

int parent( int x )
{
    if( root[x]!= x )
    {
        return root[x]=parent(root[x]);
    }
    return root[x];
}

int main()
{
    int n,m,t=1,x,y;
    while( scanf("%d%d",&n,&m) == 2 )
    {
        if( n == 0 && m == 0 ) break;
        for( int i=1; i<=n; i++ ) root[i]=i;
        for( int i=1; i<=m; i++ )
        {
            scanf("%d%d",&x,&y);
            x=parent(x);
            y=parent(y);
            //cout<<x<<" "<<y<<endl;
            if( x!= y )
            {
                root[y]=root[x];
            }
        }
        // for( int i=1; i<=n; i++ ) cout<<root[i]<<" ";
        int cnt=0;
        for( int i=1; i<=n; i++ ) if( root[i] == i ) cnt++;
        printf("Case %d: %d\n",t,cnt);
        t++;
        fill(root,0);
    }
    return 0;
}

