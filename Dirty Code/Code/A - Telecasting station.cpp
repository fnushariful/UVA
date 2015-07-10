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

int val;
pair<int,int>pr[100];
double dist(int m)
{
    int sum=0;
    for( int i=0; i<=val; i++ )
    {
        //debug(i);
        int dist=abs(pr[i].xx-m);
        //debug(dist);
        //debug(pr[i].yy);
        sum+=dist*pr[i].yy;
        //cout<<sum<<endl;
    }
}

int main()
{
    int n;
    while(scanf("%d",&n) == 1)
    {
        for( int i=0; i<n; i++ ) pr[i].xx=i,pr[i].yy=0;
        val=INT_MIN;
        for( int i=0; i<n; i++ )
        {
            int x,y;
            scanf("%d%d",&x,&y);
            val=max(val,x);
            pr[x].xx=x;
            pr[x].yy=y;
        }
        cout<<val<<endl;
        cout<<dist(10)<<endl;
    }
    return 0;
}

