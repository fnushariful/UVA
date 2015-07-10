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
    int n,m,q;
    while(cin>>n>>m>>q)
    {
        int ar[600][600],prt[1000];
        int val=INT_MIN;
        for( int i=1; i<=n; i++ )
        {
            int mx=INT_MIN,cnt=0;
            for( int j=1; j<=m; j++ )
            {
                cin>>ar[i][j];
                if( ar[i][j] == 1 )
                {
                    cnt++;
                    mx=max(mx,cnt);

                }
                else
                {
                    mx=max(mx,cnt);
                    cnt=0;
                }
            }
            prt[i]=mx;
            val=max(mx,val);
        }
//        for( int i=1; i<=n; i++ )
//        {
//            cout<<prt[i]<<endl;
//        }
        int x,y,ret[5009];
        for( int i=0; i<q; i++ )
        {
            cin>>x>>y;
            //cout<<x<<" "<<y<<endl;
            //debug(ar[x][y]);
            if( ar[x][y] == 1 ) ar[x][y]=0;
            else ar[x][y]=1;
            //ar[x][y]=1;
            //debug(ar[x][y]);
            int cnt=0,mx=INT_MIN;
            for( int j=1; j<=m; j++ )
            {
                if( ar[x][j] == 1 )
                {
                    cnt++;
                    mx=max(mx,cnt);
                }
                else
                {
                    //debug(cnt);
                    mx=max(mx,cnt);
                    //debug(mx);
                    cnt=0;
                }
            }
            //val=max(val,mx);
            //debug(mx);
            prt[x]=mx;
            val=*max_element(prt+1,prt+n+1);
            //debug(val);
            ret[i+1]=val;
            //debug(prt[x]);
        }
        for( int i=1; i<=q; i++ ) cout<<ret[i]<<endl;
    }
    return 0;
}

