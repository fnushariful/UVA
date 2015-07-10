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

int main()
{
    struct rect
    {
        double x1,x2,y1,y2,indx;
    };
    rect rt[1000];
    struct cir
    {
        double radi,c1,c2,indx;
    };
    struct tria
    {
        double x1,x2,x3,y1,y2,y3,indx;
    };
    tria tri[1000];

    cir cr[1000];
    char r;
    int rr=0,c=0,len=0,tt=0;
    while(cin>>r)
    {
        if( r == 'r' ) cin>>rt[rr].x1>>rt[rr].y1>>rt[rr].x2>>rt[rr].y2,rt[rr].indx=len,rr++;
        if( r == 'c' ) cin>>cr[c].c1>>cr[c].c2>>cr[c].radi,cr[c].indx=len,c++;
        if( r == 't' ) cin>>tri[tt].x1>>tri[tt].y1>>tri[tt].x2>>tri[tt].y2>>tri[tt].x3>>tri[tt].y3,tri[tt].indx=len,tt++;
        len++;
        if( r == '*' )
        {
            int cnt=0;
            double x,y;
            while(cin>>x>>y)
            {
                if( x == 9999.9 && y == 9999.9 ) return 0;
                cnt++;
                bool ok=false;
                int len=rr;
                for( int i=0; i<rr; i++ )
                {
                    if( (x+eps > rt[i].x1 && x+eps< rt[i].x2 ) && ( y+eps<rt[i].y1 && y+eps>rt[i].y2 ) )
                    {
                        cout<<"Point "<<cnt<<" is contained in figure "<<rt[i].indx+1<<endl;
                        ok=true;
                    }
                }
                for( int i=0; i<c; i++ )
                {
                    double d=pow((cr[i].c1-x),2)+pow((cr[i].c2-y),2);
                    d=sqrt(d);
                    //cout<<d<<" "<<cr[i].radi<<endl;
                    if( d+eps < cr[i].radi ) cout<<"Point "<<cnt<<" is contained in figure "<<cr[i].indx+1<<endl,ok=true;
                }
                for( int i=0; i<tt; i++ )
                {
                    double de=((tri[i].y2 -tri[i].y3)*(tri[i].x1 -tri[i].x3) + (tri[i].x3 -tri[i].x2)*(tri[i].y1 -tri[i].y3));
                    double a=((tri[i].y2 - tri[i].y3)*(x -tri[i].x3) + (tri[i].x3 -tri[i].x2)*(y -tri[i].y3))/de;
                    double b =((tri[i].y3 - tri[i].y1)*(x - tri[i].x3) + (tri[i].x1 - tri[i].x3)*(y - tri[i].y3))/de;
                    double c = 1-a-b;
                    if( (0<=a && a<=1 ) && ( 0<=b && b<=1 ) && ( 0<=c && c<=1 ) )
                    {
                        cout<<"Point "<<cnt<<" is contained in figure "<<tri[i].indx+1<<endl;
                        ok=true;
                    }
                }
                if( !ok ) cout<<"Point "<<cnt<<" is not contained in any figure"<<endl;
            }
        }
    }
    return 0;
}
