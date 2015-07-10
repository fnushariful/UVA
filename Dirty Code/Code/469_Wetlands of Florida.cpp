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

string mat[300];
int vist[300][300];
int val,cnt,k=10000;
long dx[]= {-1,-1,-1,0,0,+1,+1,+1};
long dy[]= {-1,0,+1,-1,+1,-1,0,+1};
int row,col;
void dfs( int i,int j )
{
    if( i>-1 && j>-1 && i<row && j<col && mat[i][j] == 'W' && vist[i][j] == 0 )
    {
        if( vist[i][j] == 0)
        {
            vist[i][j]=1,cnt++;
            for( int k=0; k<8; k++ )
                dfs(i+dx[k],j+dy[k]);
        }
    }
}

int main()
{
    int T,indx=0;
    string str;
    //freopen("output.txt","w",stdout);
    scanf("%d",&T);
    getchar();
    getchar();
    for( int t=1; t<=T; t++ )
    {
        indx=0;
        int in=0;
        if( t!=1 ) printf("\n");
        while( getline(cin,str) && str.size() )
        {
            //cout<<str.size()<<endl;
            if( str[0]>='0' && str[0]<='9' )
            {
                int fst=0,i=0;
                while(str[i]!=' ')
                {
                    fst=(10*fst)+(str[i]-'0');
                    i++;
                }
                i++;
                int snd=0;
                while(i<str.size())
                {
                    snd=(10*snd)+(str[i]-'0');
                    i++;
                }
                row=indx;
                col=mat[0].size();
                dfs(fst-1,snd-1);
                printf("%d\n",cnt);
                cnt=0;
                for( int i=0; i<indx; i++ )
                {
                    fill(vist[i],0);
                }
            }
            else if( isalpha(str[0]) )
            {
                mat[indx]+=str;
                mat[indx]+='*';
                indx++;
            }
        }
        for( int i=0; i<indx; i++ ) mat[i].clear();
    }
    return 0;
}
