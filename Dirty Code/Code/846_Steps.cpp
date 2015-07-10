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
    //freopen("output.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for( int t=1; t<=T; t++ )
    {
        LLI n,a,b;
        scanf("%lld%lld",&a,&b);
        if( (a-b) == 0 )
        {
            printf("0\n");
            continue;
        }
        if( (a-b) == 1 )
        {
            printf("1\n");
            continue;
        }
        else if( (a-b) == 2 )
        {
            printf("2\n");
            continue;
        }
        double val=sqrt(abs(a-b));
        n=val;
        if( (val-n) == 00 )
        {
            val*=2;
            val-=1;
        }
        else if( (val - n) <= 0.49 ) val=n*2;
        else
        {
            val=round(val)*2;
            val-=1;
        }
        printf("%0.Lf\n",val);
    }
    return 0;
}

