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


int n,m;

int fun(double width)
{
    double length=((n/(double)m)*width);

    double diagonal=sqrt((length*length)+(width*width));

    diagonal=diagonal/2;

    double angle=(((diagonal*diagonal)+(diagonal*diagonal))-(width*width))/(double)(2*diagonal*diagonal);

    angle=acos(angle);

    double chap=(diagonal*angle);
    double total=((2*(length))+(2*chap));

    if( fabs(total - 400) < eps ) return 2;
    else if( (total- 400) > 0 ) return 0;
    else if( (total-400)  < 0 ) return 1;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int t=1; t<=T; t++ )
    {
        scanf("%d : %d",&n,&m);
        double low=0,high=400,mid;
        for( int i=0; i<100; i++ )
        {

            mid=((low+high)/(double)2);
            int val=fun(mid);
            //debug(low);
            //debug(high);
            if( val == 2 )
            {
                //debug(mid);
                break;
            }
            else if( val == 1 ) low=mid;
            else if( val == 0 ) high=mid;

//            debug(mid);
//            debug(low);
//            debug(high);
//            low=high;
//            high=low;
        }
        double length=((n/(double)m)*mid);
        printf("Case %d: %.10lf %.10lf\n",t,length,mid);
    }
    return 0;
}

