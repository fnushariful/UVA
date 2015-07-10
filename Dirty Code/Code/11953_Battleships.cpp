#include <bits/stdc++.h>

using namespace std;

int n;
char mat[200][200];
int vis[200][200];

void chk(int x,int y)
{
    if( x < 1 || x>n ) return ;
    if( y<1   || y>n ) return ;

    if( mat[x][y] == '.' ) return;
    if( mat[x][y] == 'x' || mat[x][y] == '@' ) mat[x][y]='0';

    vis[x][y]=1;
    if( vis[x+1][y] == 0 ) chk(x+1,y);
    if( vis[x-1][y] == 0 ) chk(x-1,y);
    if( vis[x][y+1] == 0 ) chk(x,y+1);
    if( vis[x][y-1] == 0 ) chk(x,y-1);
    return ;
}

int ans=0;
int vist[200][200];
void dfs(int x,int y)
{
    if( x<1 || x>n ) return ;
    if( y<1 || y>n ) return ;

    if( mat[x][y] == 'x' )
    {
        ans++;
        memset(vis,0,sizeof vis);
        chk(x,y);
    }
    vist[x][y]=1;
    if( vist[x+1][y] == 0 ) dfs(x+1,y);
    if( vist[x-1][y] == 0 ) dfs(x-1,y);
    if( vist[x][y+1] == 0 ) dfs(x,y+1);
    if( vist[x][y-1] == 0 ) dfs(x,y-1);
}

int main()
{
    int T;
    scanf("%d",&T);
    for( int t=1; t<=T; t++ )
    {
        memset(mat,'0',sizeof mat);
        memset(vist,0,sizeof vis);
        scanf("%d\n",&n);
        for( int i=1; i<=n; i++ )
        {
            for( int j=1; j<=n; j++)
                scanf("%c",&mat[i][j]);
            getchar();
        }
        ans=0;
        dfs(1,1);
        printf("Case %d: %d\n",t,ans);
    }
    return 0;
}
