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
#define VI vector<double>
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
#define DD double

#define MOD 1000000007
#define MX 1000000
#define RADIANS(x)       (((1.0 * x * PI) / 180.0))
#define DEGREES(x)       (((x * 180.0) / (1.0 * PI)))

DD n,m,k,w;
VI v;
bool bsearch(DD val)
{
    for(int i=0; i<n; i++ )
        if( v[i]< val ) return false;
    for( int i=n; i<n*2; i++ )
    {
        if( v[i] < val*2  ) return false;
    }
    return true;
}

int main()
{
    while(cin>>n>>w)
    {
        for( int i=0; i<n*2; i++ )
        {
            LLI val;
            cin>>val;
            v.PB(val);
        }
        sort(v.begin(),v.end());
        LLI it=1000;
        DD low=0,high=w,ans=0;

        while(it--)
        {
            //debug(it);
            DD mid=(low+high)/2;

            bool ret=bsearch(mid);
            //debug(ret);

            if( ret )
            {
                ans=mid;
                //debug(ans);
                low=mid;
            }
            else high=mid;
        }
        if( ans*n+ans*2*n <=w  )
            printf("%.10f\n",ans*n+ans*2*n);
        else printf("%.10f\n",w);
    }
    return 0;
}

