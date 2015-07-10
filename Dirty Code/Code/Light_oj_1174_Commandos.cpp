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

int mat[1009][1009];


int main()
{
    int T;
    scanf("%d",&T);
    for( int t=1; t<=T; t++ )
    {
        int N,R,u,v,x,y;
        scanf("%d%d",&N,&R);
        for( int i=0; i<N; i++ )
        {
            for( int j=0; j<N; j++ )
                if( mat[i][j] == 0 )
                    mat[i][j]=MX;
        }

        for( int i=0; i<R; i++ )
        {
            scanf("%d%d",&x,&y);
            mat[x][y]=1;
            mat[y][x]=1;
        }
        for( int i=0; i<N; i++ ) mat[i][i]=0;

        scanf("%d%d",&x,&y);
        for( int k=0; k<N; k++ )
        {
            for( int i=0; i<N; i++ )
            {
                for( int j=0; j<N; j++ )
                    if( mat[i][j] > (mat[i][k]+mat[k][j]) )
                        mat[i][j]=mat[i][k]+mat[k][j];
            }
        }
        int mx=INT_MIN;
        for( int i=0; i<N; i++ )
        {
            mx=max(mx,mat[x][i]+mat[i][y]);
        }
        for( int i=0; i<N; i++ )
        {
            for( int j=0; j<N; j++ )
                mat[i][j]=0;
        }
        printf("Case %d: %d\n",t,mx);
    }
    return 0;
}

