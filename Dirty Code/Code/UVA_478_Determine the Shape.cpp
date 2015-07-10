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
#define st string

#define MOD 1000000007
#define MX 1000000
#define RADIANS(x)       (((1.0 * x * PI) / 180.0))
#define DEGREES(x)       (((x * 180.0) / (1.0 * PI)))

struct tria
{
    double x1,x2,x3,y1,y2,y3;
};
tria tri[1000];

int main()
{
    double x,y;
    int len=0;
    char r;
    while(cin>>r)
    {
        if( r == 't' )
        {
            cin>>tri[len].x1>>tri[len].y1>>tri[len].x2>>tri[len].y2>>tri[len].x3>>tri[len].y3,len++;
        }
        if( r == '*' )
        {
            int cnt=0;
            while(cin>>x>>y)
            {
                cnt++;
                bool ok=false;
                for( int i=0; i<len; i++ )
                {
                    //cout<<tri[i].x1<<" "<<tri[i].y1<<" "<<tri[i].x2<<" "<<tri[i].y2<<" "<<tri[i].x3<<" "<<tri[i].y3<<endl;
                    double de=((tri[i].y2 -tri[i].y3)*(tri[i].x1 -tri[i].x3) + (tri[i].x3 -tri[i].x2)*(tri[i].y1 -tri[i].y3));
                    double a=((tri[i].y2 - tri[i].y3)*(x -tri[i].x3) + (tri[i].x3 -tri[i].x2)*(y -tri[i].y3))/de;
                    double b =((tri[i].y3 - tri[i].y1)*(x - tri[i].x3) + (tri[i].x1 - tri[i].x3)*(y - tri[i].y3))/de;
                    double c = 1-a-b;
                    //cout<<de<<" "<<a<<" "<<b<<" "<<c<<endl;
                    if( (0<=a && a<=1 ) && ( 0<=b && b<=1 ) && ( 0<=c && c<=1 ) )
                    {
                        cout<<"Point "<<cnt<<" is contained in figure "<<i+1<<endl;
                        ok=true;
                    }
                }
                if( !ok ) cout<<"Point "<<cnt<<" is not contained in figure"<<endl;
            }
        }
    }
    return 0;
}
