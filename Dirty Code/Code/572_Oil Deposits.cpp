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

char mat[200][200];
int vist[200][200];
int n,m;

void dfs(int i,int j,int val)
{
    if(i<1 || i>n ) return;
    if( j<1 || j>m ) return;
//    cout<<i<<" "<<j<<" "<<val<<endl;
    if( mat[i][j] == '@' && vist[i][j] == 0 ) vist[i][j]=val;

    if( mat[i+1][j] == '@' && vist[i+1][j] == 0 ) dfs(i+1,j,val);
    if( mat[i-1][j] == '@' && vist[i-1][j] == 0 ) dfs(i-1,j,val);
    if( mat[i-1][j+1] == '@' && vist[i-1][j+1] == 0 ) dfs(i-1,j+1,val);
    if( mat[i-1][j-1] == '@' && vist[i-1][j-1] == 0 ) dfs(i-1,j-1,val);
    if( mat[i][j-1] == '@' && vist[i][j-1] == 0 ) dfs(i,j-1,val);
    if( mat[i+1][j-1] == '@' && vist[i+1][j-1] == 0 ) dfs(i+1,j-1,val);
    if( mat[i+1][j+1] == '@' && vist[i+1][j+1] == 0 ) dfs(i+1,j+1,val);
    if( mat[i][j+1] == '@' && vist[i][j+1] == 0 ) dfs(i,j+1,val);
    return ;
}

int main()
{
    //freopen("output.txt","w",stdout);
    while(scanf("%d%d\n",&n,&m))
    {
        if( n == 0 && m == 0 ) break;
        for( int i=1; i<=n; i++ )
        {
            for( int j=1; j<=m; j++ )
                scanf("%c",&mat[i][j]);
            getchar();
        }

//        for( int i=1; i<=n; i++ )
//        {
//            for(int j=1; j<=m; j++ )
//                printf("%c",mat[i][j]);
//            printf("\n");
//        }

        int cnt=1;
        for( int i=1; i<=n; i++ )
        {
            for( int j=1; j<=m; j++ )
            {
                if( mat[i][j] == '@' && vist[i][j] == 0 )
                    dfs(i,j,cnt++);
            }
        }
        int mx=INT_MIN;
        for( int i=1; i<=n; i++ )
        {
            for( int j=1; j<=m; j++ )
                if( mx < vist[i][j] )
                    mx=vist[i][j];
        }
        printf("%d\n",mx);
        fill(vist,0);
        fill(mat,'\0');
    }
    return 0;
}

