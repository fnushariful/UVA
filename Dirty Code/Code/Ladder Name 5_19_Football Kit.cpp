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

int h[100009],aw[100009];
int main()
{
    int n;
    while(cin>>n)
    {
        pair<int,int>pr[100009],prt[100009];
        for( int i=0; i<n; i++ )
        {
            cin>>pr[i].xx>>pr[i].yy;
            h[pr[i].xx]++;
            aw[pr[i].yy]++;
            prt[i].xx=prt[i].yy=n-1;
        }
//        for( int i=0; i<n; i++ )
//            cout<<pr[i].xx<<" "<<pr[i].yy<<endl;
        for( int i=0; i<n; i++ )
        {
            int x=pr[i].xx,y=pr[i].yy;
            //debug(y);
            int val=h[y];
            //debug(val);
            if( x == y )
                prt[i].xx+=(val-1),prt[i].yy-=(val+1);
            else
            {
                prt[i].xx+=val;
                prt[i].yy-=val;
            }
        }
        for( int i=0; i<n; i++ ) cout<<prt[i].xx<<" "<<prt[i].yy<<endl;
    }
    return 0;
}

