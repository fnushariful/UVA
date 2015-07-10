
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

string mat[1000];
int vist[1000][1000],cnt,row,col;

int dx[]= {-1,1,0,0};
int dy[]= {0,0,-1,1};

void dfs(int i,int j)
{
    //cout<<i<<" "<<j<<" "<<mat[i][j]<<endl;
    if( i>-1 && j>-1 && i<row && j<col &&  mat[i][j] == '.'  )
    {
        if( vist[i][j] == 0 )
        {
            cnt++;
            vist[i][j]=1;
            for( int k=0; k<4; k++ )
                dfs(i+dx[k],j+dy[k]);
        }
    }
}

int main()
{
    int T,x,y;
    string str;
    scanf("%d",&T);
    for( int t=1; t<=T; t++ )
    {
        scanf("%d%d",&col,&row);
        for( int i=0; i<row; i++ )
        {
            cin>>str;
            for(int j=0; j<str.size(); j++ ) if( str[j] == '@' ) x=i,y=j;
            mat[i]+=str;
        }
        mat[x][y]='.';
        dfs(x,y);
        //cout<<x<<" "<<y<<endl;
        printf("Case %d: %d\n",t,cnt);
        for( int i=0; i<row; i++ )
        {
            mat[i].clear();
        }
        fill(vist,0);
        cnt=0;
    }
    return 0;
}
