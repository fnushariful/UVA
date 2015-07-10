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

LLI mor[MX],evn[MX];
int main()
{
    //freopen("output.txt","w",stdout);
    LLI n,d,r;
    while( scanf("%lld%lld%lld",&n,&d,&r)==3 )
    {
        if( n == 0 && d == 0 && r == 0 ) break;
        for( LLI i=0; i<n; i++ ) scanf("%lld",&mor[i]);
        for( LLI i=0; i<n; i++ ) scanf("%lld",&evn[i]);
        sort(mor,mor+n);
        sort(evn,evn+n);
        reverse(evn,evn+n);
        LLI sum=0;
        for(int i=0; i<n; i++ )
        {
            if( mor[i]+evn[i] > d ) sum+=((mor[i]+evn[i])-d)*r;
        }
        printf("%lld\n",sum);
    }
    return 0;
}
