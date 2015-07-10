

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

#define MOD 1000000007
#define MX 1000009
#define RADIANS(x)       (((1.0 * x * PI) / 180.0))
#define DEGREES(x)       (((x * 180.0) / (1.0 * PI)))

int fx[]= {+0,+0,+1,-1,-1,+1,-1,+1};
int fy[]= {-1,+1,+0,+0,+1,+1,-1,-1};

char s[100000];
int main()
{
    //freopen("output.txt","w",stdout);
    int n,T=1,m;
    while(scanf("%d%d",&n,&m) == 2)
    {
        if( n == 0 && m == 0 ) break;
        getchar();
        char ar[110][110];
        int cnt=0;
        for( int i=0; i<n; i++ )
        {
            for( int j=0; j<m; j++ )
            {
                scanf("%c",&ar[i][j]);
            }
            getchar();
        }
        if( T != 1 ) cout<<endl;
        printf("Field #%d:\n",T++);
        bool ok=0;
        char chk[110][110];
        for( int i=0; i<n; i++ )
        {
            for( int j=0; j<m; j++ )
            {
                if( ar[i][j] != '*' )
                {
                    int val=ar[i][j]-'0',cnt=0;
                    //debug(val);
                    char ch;
                    for( int k=0; k<8; k++ )
                    {
                        ch=ar[i+fx[k]][j+fy[k]];
                        //debug(ch);
                        if( ch == '*' ) cnt++;
                    }
                    ch=cnt+'0';
                    chk[i][j]=ch;
                }
                else
                {
                    chk[i][j]='*';
                }
            }
        }
        for( int i=0; i<n; i++ )
        {
            for( int j=0; j<m; j++ )
                cout<<chk[i][j];
            cout<<endl;
        }
        fill(ar,'\0');
    }
    return 0;
}
