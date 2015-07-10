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
#define MSLI map<string,LLI>
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
    LLI n,m,ar[19][19];
    for(int i=1; i<=10; i++ )
        ar[i][1]=1;
    for(int i=1; i<=10; i++ )
        ar[1][i]=1;
    while(cin>>n)
    {
        for( int i=2; i<=n; i++ )
        {
            for( int j=2; j<=n; j++ )
                ar[i][j]=ar[i][j-1]+ar[i-1][j];
        }
//        for( int i=1; i<=11; i++ )
//        {
//            for( int j=1; j<=11; j++ )
//                cout<<ar[i][j]<<" ";
//            cout<<endl;
//        }
        cout<<ar[n][n]<<endl;
    }
}
