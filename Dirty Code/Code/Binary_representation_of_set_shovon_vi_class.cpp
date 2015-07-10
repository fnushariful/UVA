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

LLI fastExpo( LLI b, LLI p)
{
    LLI res=1,x=b;
    while(p)
    {
        if(p&1) res*=x;
        x*=x;
        p=p>>1;
    }
    return res;
}

int main()
{
    int res,n,ar[100],div,len;
    while(scanf("%d%d",&n,&div))
    {
        res=0;
        for( int i=0; i<div; i++ ) scanf("%d",&ar[i]);
        len=fastExpo(2,div)-1;
        for( int i=1; i<=len; i++ )
        {
            int product=1,cnt=0;
            for( int j=0; j<div; j++ )
            {
                if( i & (1<<j) )
                    product*=ar[j],cnt++;
            }
            if( cnt %2 == 1 ) res+=(n/product);
            else res-=(n/product);
            cout<<res<<" "<<product<<endl;
        }
        cout<<res<<endl;
    }
    return 0;
}
