#include <bits/stdc++.h>

using namespace std;

#define SYN ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long int LLI;
typedef unsigned long long int ULLI;

#define debug(x)         cerr<<__LINE__<<" "<<#x<<" "<<x<<endl;
#define IMAX ((unsigned)1<<31)-1
#define eps 1e-6
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
#define MX 1000000
#define RADIANS(x)       (((1.0 * x * PI) / 180.0))
#define DEGREES(x)       (((x * 180.0) / (1.0 * PI)))

int main()
{
    pair<double,double> ar[100];
    double x,y;
    int len=0;
    char r;
    while(cin>>r)
    {
        if( r == 'r' )
        {
            cin>>ar[len].xx>>ar[len].yy>>ar[len+1].xx>>ar[len+1].yy;
            len+=2;
        }
        else if( r == '*' )
        {
            //for( int i=0; i<len; i++ ) cout<<ar[i].xx<<" "<<ar[i].yy<<endl;
            int cnt=0;
            //len/=2;
            while(cin>>x>>y)
            {
                if( x == 9999.9 && y == 9999.9 ) return 0;
                cnt++;
                bool ok=false;
                for( int i=0,j=1; i<len; i+=2,j++ )
                {
                    if( (x+eps > ar[i].xx && x+eps< ar[i+1].xx ) && ( y+eps<ar[i].yy && y+eps>ar[i+1].yy ) )
                    {
                        //cout<<ar[i].xx<<" "<<ar[i].yy<<" "<<ar[i+1].xx<<" "<<ar[i+1].yy<<endl;
                        //if( )
                        cout<<"Point "<<cnt<<" is contained in figure "<<j<<endl;
                        ok=true;
                    }
                }
                if( !ok ) cout<<"Point "<<cnt<<" is not contained in any figure"<<endl;
            }
        }
    }
    return 0;
}
