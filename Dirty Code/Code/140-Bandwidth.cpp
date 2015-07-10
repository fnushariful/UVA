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

vector<pair<char,string> > v;
int chk[100];

int fun(string st)
{
    int mx=INT_MIN;
    for( int i=0; i<v.size(); i++ )
    {
        char ch=v[i].xx;
        int cnt=0;
        for( int j=0; j<st.size(); j++ )
            if( ch == st[j] )
            {
                cnt++;
                break;
            }
            else cnt++;
        //debug(cnt);
        int pos;
        pos=cnt;
        string str;
        str=v[i].yy;
        //debug(str);
        for( int j=0; j<str.size(); j++ )
        {
            char ch=str[j];
            //debug(ch);
            cnt=0;
            for( int k=0; k<st.size(); k++ )
            {
                if( st[k] == ch )
                {
                    cnt++;
                    break;
                }
                else cnt++;
            }
            //debug(abs(cnt-pos));
            mx=max(abs(cnt-pos),mx);
            //debug(mx);
        }
    }
    return mx;
}
int main()
{
    string str;
    while(cin>>str)
    {
        if( str == "#") break;
        int i=0;
        int len=str.size();
        fill(chk,0);
        v.clear();
        while(i<len)
        {
            if( str[i] == ':' )
            {
                char ch=str[i-1];
                chk[ch-'A']++;
                i++;
                string st;
                while( str[i]!=';' && i<len )
                {
//                    debug(str[i]);
//                    debug(str[i]-'A');

                    chk[str[i]-'A']++;
                    st+=str[i];
                    i++;
                }
//                debug(ch);
//                debug(st);
                v.PB( {ch,st});
            }
            i++;
        }
        string st="";
        for( int i=0; i<26; i++ )
        {
            if( chk[i]>0 ) st+=i+'A';
        }
        sort(st.begin(),st.end());
        int mi=INT_MAX;
        reverse(st.begin(),st.end());
        string prt=st;
        reverse(st.begin(),st.end());
        //debug(pt);
        //fun(pt);
        int val;
        do
        {
            int ret=fun(st);
            mi=min(ret,mi);
            if( ret == mi )
            {
//                if( pt ==st )
//                {
//                    debug(st);
//                    debug(mi);
//                    debug(ret);
//                    debug(pt);
//                    break;
//                }
                if( mi != val ) prt=st,val=mi;
                if( st>prt )
                {
                    prt=prt;
                }
                else
                {
                    prt=st;
                }
            }
            //cout<<mi<<endl;
        }
        while( next_permutation(st.begin(),st.end()));
        for( int i=0; i<prt.size(); i++ ) cout<<prt[i]<<" ";
        cout<<"-> "<<mi<<endl;
    }
    return 0;
}

