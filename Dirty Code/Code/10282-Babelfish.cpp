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

template<typename T>inline VS PARSE(T str)
{
    vector<string> res;
    string s;
    istringstream os(str);
    while(os>>s)res.PB(s);
    return res;
}
int main()
{
    string str,st;
    string fst,snd;
    map<string,string>mp;
    while(getline(cin,str))
    {
        if( str == "" ) break;
        vector<string> ret=PARSE(str);
        fst=ret[0];
        snd=ret[1];
        if( mp.find(snd) == mp.end() )
            mp[snd]=fst;
    }
    //getline(cin,st);
    while(getline(cin,str))
    {
        //cout<<str<<endl;
        if( str == "" ) break;
        if( mp.find(str) == mp.end() )
            cout<<"eh"<<endl;
        else cout<<mp[str]<<endl;
    }
    return 0;
}

