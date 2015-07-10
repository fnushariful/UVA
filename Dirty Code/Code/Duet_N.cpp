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

bool cmp(pLLI x,pLLI y)
{
    if( x.xx == y.xx ) return x.yy<y.yy;
    return x.xx>y.xx;
}

main()
{
    int n,k;
    pLLI pr[1000],ar[1000];
    while(cin>>n>>k)
    {
        for( int i=0; i<n; i++ ) cin>>pr[i].xx>>pr[i].yy;
        sort(pr,pr+n,cmp);
        for( int i=1; i<=n; i++ )
        {
            ar[i].xx=pr[i-1].xx;
            ar[i].yy=pr[i-1].yy;
        }
        //cout<<"Robin"<<endl;
        //for( int i=1; i<=n; i++ ) cout<<ar[i].xx<<" "<<ar[i].yy<<endl;

        int pos=ar[k].xx;
        int pen=ar[k].yy;
       // debug(pos);
        //debug(pen);
        //cout<<"Robin"<<endl;
       // cout<<endl<<k<<endl;
        int cnt=0;
        for( int i=1; i<=n; i++ )
            if( pos == ar[i].xx and pen ==ar[i].yy ) cnt++;
        cout<<cnt<<endl;
    }
}
