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
#define pii pair<int,int>
#define xx first
#define yy second
#define st string

#define MOD 1000000007
#define MX 1000000
#define RADIANS(x)       (((1.0 * x * PI) / 180.0))
#define DEGREES(x)       (((x * 180.0) / (1.0 * PI)))

int fx[]= {1,-1,0,0};
int fy[]= {0,0,1,-1};
int cell[100][100];
int d[100][100],vis[100][100];
int row,col,bx,by,cx,cy,ax,ay,hx,hy;
void bfs(int sx,int sy)
{
    fill(vis,0);
    fill(d,0);
    vis[sx][sy]=1;
    queue<pii>q;
    q.push(pii(sx,sy));
    while(!q.empty())
    {
        pii top=q.front();
        if( top.xx == hx && top.yy == hy ) break;
        //debug(top.xx);
        //debug(top.yy);
        q.pop();
        for( int k=0; k<4; k++ )
        {
            int tx=top.xx+fx[k];
            int ty=top.yy+fy[k];
            //debug(tx);
            //debug(ty);
            //cout<<tx<<" "<<row<<" "<<ty<<" "<<col<<" "<<cell[tx][ty]<<" "<<vis[tx][ty]<<endl;
            if( (tx>=0 && tx<row) && (ty>=0 && ty<col) && (cell[tx][ty]==0 && vis[tx][ty] == 0 ))
            {
                //cout<<"OK"<<endl;
                vis[tx][ty]=1;
                d[tx][ty]=d[top.xx][top.yy]+1;
                //debug(d[tx][ty]);
                q.push(pii(tx,ty));
            }
        }
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for( int t=1; t<=T; t++ )
    {
        scanf("%d%d",&row,&col);
        char ch;
        getchar();
        for( int i=0; i<row; i++ )
        {
            for( int j=0; j<col; j++ )
            {
                scanf("%c",&ch);
                if( ch == '#' || ch == 'm' )
                    cell[i][j]=-1;
                if( ch == 'a' ) ax=i,ay=j;
                if( ch == 'c' ) cx=i,cy=j;
                if( ch == 'b' ) bx=i,by=j;
                if( ch == 'h' ) hx=i,hy=j;
            }
            getchar();
        }
        int mx=INT_MIN;
        bfs(ax,ay);
        mx=max(mx,d[hx][hy]);
        bfs(bx,by);
        mx=max(mx,d[hx][hy]);
        bfs(cx,cy);
        mx=max(mx,d[hx][hy]);
        printf("Case %d: %d\n",t,mx);
        for( int i=0; i<row; i++ )
        {
            for( int j=0; j<col; j++ )
                cell[i][j]=0;
        }
    }
    return 0;
}

