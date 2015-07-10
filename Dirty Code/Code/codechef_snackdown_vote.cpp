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
    int T;
    scanf("%d",&T);
    for( int t=1; t<=T; t++ )
    {
        int n;
        scanf("%d",&n);
        int ar[1000];
        // cout<<"ok"<<endl;
        for( int i=0; i<n; i++ )
            scanf("%d",&ar[i]);
        //cout<<"ok"<<endl;
        int cnt=0;
        for( int i=0; i<n; i++ ) if( ar[i] == 1 ) cnt++;
        //cout<<cnt<<endl;
        if( cnt == n )
        {
            cout<<n;
            for( int i=n-1; i>=1; i-- ) cout<<" "<<i;
            cout<<endl;
        }
        else cout<<-1<<endl;
    }
    return 0;
}

