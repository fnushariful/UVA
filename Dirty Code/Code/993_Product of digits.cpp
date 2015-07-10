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
#define MX 100000
#define RADIANS(x)       (((1.0 * x * PI) / 180.0))
#define DEGREES(x)       (((x * 180.0) / (1.0 * PI)))

int main()
{
    LLI n,T;
    scanf("%lld",&T);
    for( LLI t=1; t<=T; t++ )
    {
        scanf("%lld",&n);
        string str;
        bool ok=0;
        while( n >= 10 && !ok )
        {
            LLI pre=n;
            for( int i=9; i>=2; i-- )
            {
                if( n%i == 0 )
                {
                    //cout<<i<<endl;
                    str+=(i+'0');
                    n/=i;
                    break;
                }
            }
            if( n == pre ) ok=1;
        }
        str+=n+'0';
        reverse(str.begin(),str.end());
        if( ok ) cout<<"-1"<<endl;
        else
            cout<<str<<endl;
    }
    return 0;
}
