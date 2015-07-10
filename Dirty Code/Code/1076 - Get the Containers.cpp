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

LLI ar[1000];
LLI n,m;

int container(long x)
{
    long sum=0,c=1;
    for( int i=0; i<n; i++ )
    {
        if((sum+ar[i])<=x)
        {
            sum+=ar[i];
        }
        else
        {
            if(ar[i]>x)
                return false;
            sum=ar[i];
            c++;
        }
        if(c>m)
            return false;
    }
    return true;
}

int main()
{
    int T;
    scanf("%d",&T);
    for( int t=1; t<=T; t++ )
    {
        scanf("%lld%lld",&n,&m);
        LLI mx=INT_MIN,sum=0;
        for( LLI i=0; i<n; i++ ) scanf("%lld",&ar[i]),mx=max(ar[i],mx),sum+=ar[i];
        //cout<<mx<<" "<<sum<<endl;
        LLI low=mx,high=sum,mid=0;
        while( low<high )
        {
            mid=(low+high)/2;
            //cout<<low<<" "<<high<<" "<<mid<<endl;
            if( container(mid) )
            {
                high=mid;
                if( container((low+high)/2) )
                    mid=(low+high)/2;
                else mid=mid;
            }
            else
            {
                low=mid+1;
                if( container((low+high)/2) )
                    mid=(low+high)/2;
                else mid=mid;
            }
            //cout<<mid<<endl;

        }
        if( mid == 0 ) printf("Case %d: %lld\n",t,mx);
        else printf("Case %d: %lld\n",t,mid);
    }
    return 0;
}

