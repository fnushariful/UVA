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

#define MOD 1000000007
#define MX 1000000
#define RADIANS(x)       (((1.0 * x * PI) / 180.0))
#define DEGREES(x)       (((x * 180.0) / (1.0 * PI)))


int main()
{
    SYN;
    string str,st;
    int T;
    cin>>T;
    getline(cin,st);
    getline(cin,st);
    for( int t=1; t<=T; t++ )
    {
        if( t!= 1 ) cout<<endl;
        string str;
        map<string,int> mp;
        double cnt=0;
        while(getline(cin,str))
        {
            if( str == "" ) break;
            cnt++;
            mp[str]++;
        }
        //for(auto& x:mp ) cout<<x.xx<<" "<<x.yy<<endl;
        vector<pair<string,double> > vt;
        for( auto& x:mp )
        {
            str=x.xx;
            int val=x.yy;
            double va=(val*100)/cnt;
            vt.PB( {str,va});
        }
        for( auto& x:vt)
        {
            //printf("%0.4f\n",x.yy);
            cout<<x.xx<<" "<<setprecision(4)<<fixed<<x.yy<<endl;
        }
    }
    return 0;
}
