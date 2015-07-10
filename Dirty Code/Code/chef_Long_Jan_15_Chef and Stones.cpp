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

LLI A[MX+10],B[MX+10];
int main()
{
    LLI T;
    scanf("%lld",&T);
    for( int t=1; t<=T; t++ )
    {
        LLI n,k;
        scanf("%lld%lld",&n,&k);
        for( int i=0; i<n; i++ ) scanf("%lld",&A[i]);
        for( int i=0; i<n; i++ ) scanf("%lld",&B[i]);
        LLI mx=INT_MIN;
        for( int i=0; i<n; i++ )
        {
            LLI tmp=k/A[i];
            tmp=tmp*B[i];
            if( mx < tmp ) mx=tmp;
        }
        printf("%lld\n",mx);
    }
    return 0;
}
