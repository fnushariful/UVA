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


int main()
{
    //freopen("output.txt","w",stdout);
    int T,n;
    scanf("%d",&T);
    for( int t=1; t<=T; t++ )
    {
        scanf("%d",&n);
        getchar();
        char str[100][100];
        for( int i=0; i<n; i++ )
        {
            for(int j=0; j<n; j++)
                cin>>str[i][j];
        }
        char val='A';
        for( int i=0; i<n; i++ )
        {
            for( int j=0; j<n; j++ )
            {
                val='A';
                if( str[i][j] == '.' )
                {
                    str[i][j]=val;
                    while( 1 )
                    {
                        if( str[i-1][j] == str[i][j] || str[i][j-1] == str[i][j] || str[i][j+1] == str[i][j] || str[i+1][j] == str[i][j] ) str[i][j]=val++;
                        else break;
                    }
                }
            }
        }
        printf("Case %d:\n",t);
        for(int i=0; i<n; i++ )
        {
            for( int j=0; j<n; j++ )
                cout<<str[i][j];
            cout<<endl;
        }

    }
    return 0;
}



/*


2
3
...
...
...
3
...
A..
...

*/
