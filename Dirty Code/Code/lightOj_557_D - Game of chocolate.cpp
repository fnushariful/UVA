
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
    int T;
    scanf("%d",&T);
    for( int t=1; t<=T; t++ )
    {
        int x1,y1,x2,y2,sum,sum1,sum2,sum3;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        sum=(x1*(x2+1));
        cout<<sum<<endl;
        sum2=((x1+y1)*((x2+1)+y2));
        cout<<sum2<<endl;
        double p=sum/(double)sum2;
        sum=(y1*(y2+1));
        sum1=((x1+y1)*(x2+(y2+1)));
        double q=sum/(double)sum1;
        p=p+q;
        printf("Case %d: %lf\n",t,p);
    }
}
