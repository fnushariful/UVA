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

#define MOD 1000000007
#define RADIANS(x)       (((1.0 * x * PI) / 180.0))
#define DEGREES(x)       (((x * 180.0) / (1.0 * PI)))

main()
{
    int n,k,ar[10000],m,mx;
    while(cin>>n>>m>>k)
    {
        if( m!= k )
            mx=max(m,k);
        for( int i=0; i<n; i++ ) cin>>ar[i];
        int cnt=0;
        for( int i=0; i<n; i++ )
        {
            if( ar[i] == 2 and k!= 0 ) k--;
            else if( ar[i] == 1 and m!=0 ) m--;
            else if( ar[i] == 2 and m!= 0 ) m--;
            else cnt++;
            //debug(cnt);
        }
        cout<<cnt<<endl;
    }
}
