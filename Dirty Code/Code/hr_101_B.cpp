#include <bits/stdc++.h>

using namespace std;

#define SYN ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long int LLI;
typedef unsigned  int ULLI;

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

template<typename T> inline bool isOn(T mask,T pos)
{
    return mask&(1<<pos);
}

template<class T> inline int countbit(T n)
{
    return (n == 0) ? 0 : (1+countbit(n&(n-1)));
}

template<typename T> inline int Off(T mask,T pos)
{
    return mask^(1<<pos);
}

ULLI n,T,a,b;
int main()
{
    cin>>T;
    for( int t=0; t<T; t++ )
    {
        cin>>a>>b;
        int mx=max(a,b);
        int cnt=countbit(mx);
        for( ULLI i=0; i<cnt; i++ )
        {
            if( isOn(i,a) != isOn(i,b) )
            {
                for( int j=i; j<n; j++ )
                    Off(i,a);
            }
        }
        cout<<a<<endl;
    }
    return 0;
}
