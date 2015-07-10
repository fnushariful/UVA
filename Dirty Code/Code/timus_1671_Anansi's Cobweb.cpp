#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string.h>

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
#define MX 100009
#define RADIANS(x)       (((1.0 * x * PI) / 180.0))
#define DEGREES(x)       (((x * 180.0) / (1.0 * PI)))

LLI root[MX];
pair<LLI,LLI> pr[MX];
LLI n,ar[MX];
bool chk[MX];
vector<LLI> rst;

LLI parent( LLI x )
{
    if( root[x] != x )
        return root[x]=parent(root[x]);
    return root[x];
}

int main()
{
    LLI N,E,x,y;
    while(scanf("%lld%lld",&N,&E) == 2 )
    {
        for( int i=1; i<=N; i++ ) root[i]=i;
        for( int i=1; i<=E; i++ )
        {
            scanf("%lld%lld",&x,&y);
            pr[i].xx=x,pr[i].yy=y;
        }
        scanf("%lld",&n);
        for( int i=1; i<=n; i++ ) scanf("%lld",&ar[i]),chk[ar[i]]=1;
        for( int i=1; i<=N; i++ )
        {
            if( !chk[i] )
            {
                x=pr[i].xx;
                x=parent(x);
                y=pr[i].yy;
                y=parent(y);
                if( x != y )
                {
                    root[y]=root[x];
                }
            }
        }
        LLI prt=0;
        for( int i=1; i<=N; i++ )
        {
            if( root[i] == i ) prt++;
        }
        rst.PB(prt);
        for( int i=n; i>1; i-- )
        {
            x=pr[ar[i]].xx;
            x=parent(x);
            y=pr[ar[i]].yy;
            y=parent(y);
            if( x!=y )
            {
                prt-=1;
                root[y]=root[x];
            }
            rst.PB(prt);
        }

        x=pr[ar[1]].xx;
        x=parent(x);
        y=pr[ar[1]].yy;
        y=parent(y);
        if( x!=y )
        {
            prt-=1;
            root[y]=root[x];
        }
        //cout<<prt<<" "<<rst[rst.size()-1]<<endl;
        if( prt != rst[rst.size()-1] ) rst[rst.size()-1]=prt;
        reverse(rst.begin(),rst.end());
        printf("%lld",rst[0]);
        for( int i=1; i<rst.size(); i++ ) printf(" %lld",rst[i]);
        printf("\n");
        fill(root,0);
        fill(pr,0);
        fill(chk,0);
        fill(ar,0);
        rst.clear();
    }
    return 0;
}

