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

#define MOD 20007
#define MX 2000009
#define RADIANS(x)       (((1.0 * x * PI) / 180.0))
#define DEGREES(x)       (((x * 180.0) / (1.0 * PI)))

LLI duck[MX],king[MX];
LLI cost[MX];

int main()
{
    //freopen("output.txt","w",stdout);
    LLI n,m;
    while(scanf("%lld%lld",&n,&m) == 2 )
    {
        if( n == 0 && m == 0 ) break;
        for( int i=0; i<n; i++ ) scanf("%lld",&duck[i]);
        for( int i=0; i<m; i++ ) scanf("%lld",&king[i]),cost[king[i]]++;
        //for( int i=0; i<=6; i++ ) cout<<cost[i]<<" ";

        //cout<<endl;
        sort(duck,duck+n);
        sort(king,king+m);
        LLI sum=0,cnt=0;
        for( LLI i=0; i<n; i++ )
        {
            for( LLI j=i; j<m; j++ )
                if( king[j] >= duck[i] && cost[king[j]] > 0 )
                {
                    //chk[king[j]]=1;
                    sum+=king[j];
                    cost[king[j]]--;
                    //cout<<duck[i]<<" "<<king[j]<<endl;
                    cnt++;
                    break;
                }
        }

        if( cnt == n )
            printf("%lld\n",sum);
        else printf("Loowater is doomed!\n");
        //fill(chk,0);
        fill(cost,0);
    }
    return 0;
}
