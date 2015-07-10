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

int main()
{
    int n,ar[100],val;
    while(cin>>n)
    {
        bool ok=0;
        vector<int>prt;
        set<int>v,ret;
        int pos;
        cin>>val;
        prt.PB(val);
        for( int i=1; i<n; i++ )
        {
            cin>>ar[i];
            if( (val-ar[i])> 0 )
            {
                //cout<<ar[i]<<" "<<val<<endl;
                //v.insert(i);
                //v.insert(i+1);
                ret.insert(ar[i]);
                ret.insert(val);
            }
            val=ar[i];
            prt.PB(val);
        }
        sort(prt.begin(),prt.end());
        //for( int i=0; i<prt.size(); i++ ) cout<<prt[i]<<" ";
        for( set<int>:: iterator it=ret.begin(); it!=ret.end(); ++it )
        {
            cout<<*it<<" ";
        }
    }
    return 0;
}

