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
    string x,y;
    int val;
};
str mp[3000];
set< pair<string,string> >pr;

main()
{
    int n,d;
    while(cin>>n>>d)
    {
        for(  int i=0; i<n; i++ ) cin>>mp[i].x>>mp[i].y>>mp[i].val;
        int k=0;
        for( int i=0; i<n; i++ )
        {
            string st=mp[i].x,ed=mp[i].y;
            for( int j=i+1; j<n; j++ )
            {
                if( ed == mp[j].x and st == mp[j].y and mp[j].val-mp[i].val > 0 and mp[j].val-mp[i].val <=d )
                    pr.insert(mk(min(st,ed),max(st,ed)));
            }
        }
        cout<<pr.size()<<endl;
        for( set< pair<string,string> >:: iterator it=pr.begin(); it!=pr.end(); ++it )
        {
            cout<<it->xx<<" "<<it->yy<<endl;
        }
        pr.clear();
    }
}

