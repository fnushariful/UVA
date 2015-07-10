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
int vist[1000][1000],cnt;
char chk;
int row,col,t=1;
int dx[]= {-1,1,0,0};
int dy[]= {0,0,-1,1};
void dfs( int i,int j,char ch )
{
    if( i>-1 && j>-1 && i<row && j<col && mat[i][j] == ch )
    {
        if( vist[i][j] == 0 )
        {
            vist[i][j]=1;
            cnt++;
            for( int k=0; k<4; k++ )
                dfs(i+dx[k],j+dy[k],mat[i][j]);
        }
    }
}
pair<char,int>pr[100000];
int main()
{
    while( scanf("%d%d",&row,&col)==2 )
    {
        if( row == 0 && col ==0 ) break;
        string str;
        for( int i=0; i<row; i++ )
        {
            cin>>str;
            mat[i]+=str;
        }
        int l=0;
        for( int i=0; i<row; i++ )
        {
            for( int j=0; j<col; j++ )
                if( vist[i][j] == 0 && isalpha(mat[i][j]) )
                {
                    dfs(i,j,mat[i][j]);
                    pr[l].xx=mat[i][j];
                    pr[l].yy=cnt;
                    cnt=0;
                    l++;
                }
        }
        for( int i=0; i<l-1; i++ )
        {
            for( int j=i+1; j<l; j++ )
            {
                if( pr[i].yy<pr[j].yy )
                    swap(pr[i],pr[j]);
                else if( pr[i].yy == pr[j].yy )
                {
                    if( pr[i].xx > pr[j].xx )
                        swap(pr[i],pr[j]);
                }
            }
        }
        printf("Problem %d:\n",t++);
        for( int i=0; i<l; i++ ) printf("%c %d\n",pr[i].xx,pr[i].yy);
        for( int i=0; i<row; i++ )
        {
            fill(vist[i],0);
            mat[i].clear();
        }
    }
    return 0;
}

