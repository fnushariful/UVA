#include <bits/stdc++.h>

using namespace std;

#define SYN ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long int LLI;
typedef unsigned long long int ULLI;

#define debug(x)         cerr<<__LINE__<<" "<<#x<<" "<<x<<endl;
#define IMAX ((unsigned)1<<31)-1
#define eps 1e-3
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
    int T;
    double n,ar[MX];
    scanf("%d",&T);
    for( int t=1; t<=T; t++ )
    {
        scanf("%lf",&n);
        LLI sum=0;
        for( int i=0; i<n; i++ ) scanf("%lf",&ar[i]),sum+=ar[i];
        if( sum == 100 ) printf("YES\n");
        else if( sum > 100 )
        {
            int sub_sum=0;
            for( int i=0; i<n; i++ )
                if( ar[i] > 0 )
                    ar[i]-=1,sub_sum+=ar[i];
            if( sub_sum < 100 )
                printf("YES\n");
            else printf("NO\n");
        }
        else printf("NO\n");
        fill(ar,0);
    }
    return 0;
}
