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
    int str,fst,snd,trd;
    while(cin>>str>>fst>>snd>>trd)
    {
        if( str == 0 && fst == 0 && snd == 0 && trd == 0 ) return 0;
        if( str == fst && fst == snd && snd == trd )
        {
            cout<<1080<<endl;
            continue;
        }
        int ret=360*2,val;
        if( fst >= str )
        {
            val=(fst-str)*9;
            val=360-val;
        }
        else if( str > fst )
        {
            val=(40-str)*9+(fst)*9;
            val=360-val;
        }
        //debug(val);
        ret+=val;
        ret+=360;
        if( snd > fst )
        {
            val=(40-fst)*9+(snd*9);
            val=abs(360-val);
        }
        else
        {
            val=(fst-snd)*9;
            val=360-val;
        }
        //debug(val);
        ret+=val;
        if( trd>snd )
        {
            val=(trd-snd)*9;
            val=360-val;
        }
        else
        {
            val=(40-snd)*9+(trd*9);
            val=360-val;
        }
        //debug(val);
        ret+=val;
        cout<<ret<<endl;
    }
    return 0;
}
