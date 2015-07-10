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

double dist(int x,int y,int x1,int y1)
{
    return sqrt(((x1-x)*(x1-x))+((y1-y)*(y1-y)));
}

int main()
{
    int ox,oy,ax,ay,bx,by,n;
    scanf("%d",&n);
    for( int t=1; t<=n; t++ )
    {
        scanf("%d%d%d%d%d%d",&ox,&oy,&ax,&ay,&bx,&by);
        double oa=dist(ox,oy,ax,ay);
        double ob=dist(ox,oy,bx,by);
        double ba=dist(bx,by,ax,ay);
        double val=(oa*oa)+(ob*ob)-(ba*ba);
        double de=2*oa*ob;
        //cout<<oa<<endl;
        val=val/de;
        val=acos(val);
        printf("Case %d: %0.10lf\n",t,val*oa);
    }
    return 0;
}
