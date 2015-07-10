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
    int n,m,k;
    int t=1;
    while(cin>>n>>m)
    {
        if( n == 0 && m == 0 ) break;
        list<int> prt;
        n=min(n,1000);
        printf("Case %d:\n",t++);
        for( int i=1; i<=n; i++ ) prt.push_back(i);
        char ch;
        int val;
        LLI cnt=n;
        for( int i=0; i<m; i++ )
        {
            cin>>ch;
            if( ch == 'E' )
            {
                cin>>val;
                prt.remove(val);
                prt.push_front(val);
            }
            else if( ch == 'N' )
            {
                val=prt.front();
                cout<<val<<endl;
                prt.pop_front();
                prt.push_back(val);
            }
        }
    }
    return 0;
}

