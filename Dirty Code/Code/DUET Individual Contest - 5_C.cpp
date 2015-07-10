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
#define MSS map<string,string>

#define MOD 1000000007
#define RADIANS(x)       (((1.0 * x * PI) / 180.0))
#define DEGREES(x)       (((x * 180.0) / (1.0 * PI)))

typedef struct str
{
  string x,string y;
  int val;
};
str mp[1009];

main()
{
    int n,d;
    while(cin>>n>>d)
    {

        MSI chk;
        string st,ed;
        int t;
        for( int i=0; i<n; i++ )
        {
            cin>>mp[i].xx>>mp[i].yy>>t;
            chk[mp[i].xx]=t;
        }
        //cout<<chk.size()<<endl;
        // for( MSI :: iterator it=chk.begin(); it!=chk.end(); ++it) cout<<it->xx<<" "<<it->yy<<endl;
        int k=0;
        for( int i=0; i<n; i++ )
        {
            string st,ed;
            st=mp[i].xx,ed=mp[i].yy;
            cout<<chk[ed]<<" "<<chk[st]<<endl;
            cout<<st<<" "<<ed<<endl;
            for( int j=i+1; j<n; j++ )
                if( st == mp[j].yy and ed == mp[j].xx and (chk[ed]-chk[st])> 0 and (chk[ed]-chk[st])<= d ) pr[k].xx=ed,pr[k].yy=st,k++;//cout<<st<<" "<<ed<<endl;
        }
        cout<<k<<endl;
        for( int i=0; i<k; i++ )
            cout<<pr[i].xx<<" "<<pr[i].yy<<endl;
        chk.clear();
        //mp.clear(),pr.clear();
    }
}
