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


double dist(double x,double y,double x1,double y1)
{
    return sqrt(((x1-x)*(x1-x))+((y1-y)*(y1-y)));
}

int root[10000];

int parent(int x)
{
    if( root[x] == x ) return root[x];
    return root[x]=parent(root[x]);
}

int main()
{
    int T;
    scanf("%d",&T);
    for( int t=1; t<=T; t++ )
    {
        int n;
        double d;
        pair<double,double>pr[10000];
        scanf("%d%lf",&n,&d);
        for( int i=1; i<=n; i++ ) root[i]=i;
        for( int  i=1; i<=n; i++ )
        {
            scanf("%lf%lf",&pr[i].xx,&pr[i].yy);
        }
        for( int i=1; i<n; i++ )
        {
            double x1=pr[i].xx,y1=pr[i].yy;
            for( int j=i+1; j<=n; j++ )
            {
                double x2=pr[j].xx,y2=pr[j].yy;
                double cmp=dist(x1,y1,x2,y2);
                if( cmp <= d )
                {
                    int x=parent(i);
                    int y=parent(j);
                    if( x!=y )
                    {
                        root[y]=root[x];
                    }
                }
            }
        }
        int cnt=0;
        for( int i=1; i<=n; i++ )
        {
            if( root[i] == i ) cnt++;
        }
        printf("Case %d: %d\n",t,cnt);
        fill(root,0);
    }
    return 0;
}

