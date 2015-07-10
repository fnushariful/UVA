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

#define MOD 1000000007
#define RADIANS(x)       (((1.0 * x * PI) / 180.0))
#define DEGREES(x)       (((x * 180.0) / (1.0 * PI)))
LLI n,k;
LLI chk(LLI mid)
{
    LLI len=k,sum=mid;
    while( mid/len != 0 )
    {
        if( sum >= n )
            break;
        sum+=mid/len;
        len*=k;
    }
    return sum;
}

main()
{
    while(cin>>n>>k)
    {
        LLI len,i,sum;
        if( n < k  )
        {
            cout<<n<<endl;
            continue;
        }
        LLI mi=INT_MAX,pos,st=2,ed=n,mid;
        while( st<=ed )
        {
            mid=(st+ed)/2;
            LLI sum=chk(mid);
           // if( sum < n ) st=mid+1;
            //else ed=mid-1;
            if( sum == n )
            {
               pos=mid,ed=mid-1;
            }
            else st=mid+1;
            cout<<st<<" "<<ed<<" "<<mid<<" "<<endl;
        }
        mi=INT_MAX;
        if(  mi> chk(st) ) mi=chk(st),pos=st;
        else if( mi > chk(ed)  ) mi=chk(ed),pos=ed;
        else if( mi > chk(mid) ) mi=chk(mid),pos=mid;
        cout<<pos<<endl;
    }
}
