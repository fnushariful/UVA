
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
    int n,T;
    scanf("%d",&T);
    for( int t=1; t<=T; t++ )
    {
        int n,m;
        scanf("%d%d",&n,&m);
        getchar();
        char ar[100][100];
        int cnt=0;
        for( int i=0; i<n; i++ )
        {
            for( int j=0; j<m; j++ )
            {
                scanf("%c",&ar[i][j]);
                char ch=ar[i][j];
                if( ch == 'F') cnt++;
            }
            getchar();
        }
        if( cnt == n*m )
        {
            printf("Please sweep the mine again!\n");
            continue;
        }
        bool ok=0;
        for( int i=0; i<n; i++ )
        {
            for( int j=0; j<m; j++ )
            {
                if( ar[i][j] != 'F' )
                {
                    int val=ar[i][j]-'0',cnt=0;
                    //debug(val);
                    for( int k=0; k<8; k++ )
                    {
                        char ch=ar[i+fx[k]][j+fy[k]];
                        //debug(ch);
                        if( ch == 'F' ) cnt++;
                    }
                    if( cnt != val )
                    {
                        ok=1;
                        break;
                    }
                    //debug(cnt);
                    //debug(val);
                }
            }
            if( ok ) break;
        }
        if( !ok )
            printf("Well done Clark!\n");
        else printf("Please sweep the mine again!\n");
    }
    return 0;
}
