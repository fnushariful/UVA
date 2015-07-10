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
    int n;
    pLLI pr[1000];
    while(cin>>n)
    {
        pr[0].xx=0,pr[0].yy=0;
        for( int i=1; i<=n; i++ ) cin>>pr[i].xx;
        for( int i=1; i<=n; i++ ) cin>>pr[i].yy;
        sort(pr+1,pr+n+1);
        //for( int i=1; i<=n; i++ ) cout<<pr[i].xx<<" "<<pr[i].yy<<endl;
        LLI sum=0;
        for( int i=1; i<=n; i++ )
        {
            sum+=pr[i].xx-pr[i-1].yy;
            sum+=pr[i].yy;
        }
        reverse(pr+1,pr+n+1);
        LLI cnt=0;
        for( int i=1; i<=n; i++ )
        {
            cnt+=pr[i].xx-pr[i-1].yy;
            cnt+=pr[i].yy;
        }
        //cout<<sum<<" "<<cnt<<endl;
        cnt=min(sum,cnt);
        cout<<cnt<<endl;
    }
    return 0;
}

