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

double dist( int x,int y,int x1,int y1 )
{
    return sqrt(((x1-x)*(x1-x))+((y1-y)*(y1-y)));
}

long double area(LLI x1,LLI y1,LLI r1,LLI x2,LLI y2,LLI r2 ,LLI d )
{
    if( d >= r1+r2 ) return 0;
    else if(d <= fabs(r1-r2) )
    {
        r1=min(r1,r2);
        return PI*r1*r1;
    }
    else
    {
        long double cosb=((d*d)+(r1*r1)-(r2*r2))/(double)(2*d*r1);
        long double cosc=((d*d)+(r2*r2)-(r1*r1))/(double)(2*d*r2);
        cosb=acos(cosb);
        cosc=acos(cosc);
        cosb*=2;
        cosc*=2;
        long double fst_cir=0.5*(r1*r1)*(cosb-(sin(cosb)));
        long double snd_cir=0.5*(r2*r2)*(cosc-(sin(cosc)));
        long double ar=fst_cir+snd_cir;
        return ar;
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for( int t=1; t<=T; t++ )
    {
        LLI x1,x2,y1,y2,r1,r2;
        scanf("%lld%lld%lld%lld%lld%lld",&x1,&y1,&r1,&x2,&y2,&r2);
        double d=dist(x1,y1,x2,y2);
        d=area(x1,y1,r1,x2,y2,r2,d);
        //debug(d);
        printf("Case %d: %.10lf\n",t,d);
    }
    return 0;
}
