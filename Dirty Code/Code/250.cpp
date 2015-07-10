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

vector<string> v[1000];
main()
{
    int n,str,len,sp;
    while(cin>>n)
    {
        str=0;
        sp=n;
        string st;
        for( int i=1; i<=(n/2)+1; i++ )
        {
            if( i%2 == 1 )
            {
                for( int j=1; j<=str/2; j++ )
                    if( j % 2 == 1) st+="#";
                    else st+=" ";
                for( int j=1; j<=sp; j++)
                    st+="#";
                for( int j=1; j<=str/2; j++ )
                    if( j % 2 == 1 )
                        st+=" ";
                    else st+="#";
            }
            else
            {
                for( int j=1; j<=ceil(str/2); j++ )
                    if( j%2 == 1) st+="#";
                    else st+=" ";
                for( int j=1; j<=sp; j++ ) st+=" ";
                for( int j=1; j<=ceil(str/2); j++ )
                    if( j % 2 == 1 ) st+="#";
                    else st+=" ";
            }
            sp=sp-2;
            str+=2;
            v[i].PB(st);
            st.clear();
            //cout<<endl;
        }
        for( int j=1; j<=n; j++ )
            if( j%2 == 1 )
                st+="#";
            else st+=" ";
        v[(n/2)+2].PB(st);

        VS ret;
        for( int i=0; i<(n/2)+2; i++ )
        {
            string tmp;
            for( int j=0; j<v[i].size(); j++ ) tmp+=v[i][j];
            ret.PB(tmp);
            tmp.clear();
        }
        for( int i=(n/2); i>=0; i-- )
        {
            string tmp;
            for( int j=0; j<v[i].size(); j++ ) tmp+=v[i][j];
            ret.PB(tmp);
            tmp.clear();
        }
        //ret.PB(ret[0]);
        for( int i=0; i<n+1; i++ ) cout<<ret[i]<<endl;
        for( int i=0; i<v[i].size(); i++ )
            v[i].clear();
    }
}
