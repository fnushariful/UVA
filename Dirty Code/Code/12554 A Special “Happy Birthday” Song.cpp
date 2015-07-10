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
    string st="Happy birthday to you Happy birthday to you Happy birthday to Rujia Happy birthday to you";
    vector<string>chk;
    int len=st.size(),i=0;
    string tmp;
    while(i<len)
    {
        if( st[i] ==' ' )
        {
            //debug(tmp);
            chk.PB(tmp);
            tmp="";
        }
        else tmp+=st[i];
        i++;
    }
    chk.PB(tmp);
    //for( int i=0; i<chk.size(); i++ ) cout<<chk[i];
    int n;
    while(cin>>n)
    {
        len=chk.size();
        vector<string>v;
        string str;
        for( int i=0; i<n; i++ )
        {
            cin>>str;
            v.PB(str);
        }
        //cout<<len<<endl;
        vector<string>prt;
        if( n<len )
        {
            for( int i=0; ; i++ )
            {
                if( i == n ) i=0;
                if( prt.size() == chk.size() ) break;
                else prt.PB(v[i]);
            }
        }
        else if( n>=len )
        {
            for( int j=0; j<n/16; j++ )
                for( int i=0; i<chk.size(); i++ ) prt.PB(v[i]);
            // cout<<prt.size()<<endl;
            len=n%16;
            //debug(len);
            len+=(16-len);
            for( int i=((n/16)*16),j=0; j<=len; i++,j++ )
            {
                // debug(i);
                if( i ==n ) i=-1;
                else prt.PB(v[i]);
            }
        }
        // debug(prt.size());
        for( int i=0,j=0; i<prt.size(); i++,j++ )
        {
            if( j== 16 ) j=0;
            cout<<prt[i]<<": "<<chk[j]<<endl;
        }
    }
    return 0;
}

