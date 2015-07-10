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
#define VI vector<LLI>
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
#define MX 10000009
#define RADIANS(x)       (((1.0 * x * PI) / 180.0))
#define DEGREES(x)       (((x * 180.0) / (1.0 * PI)))

struct srt
{
    string str;
    int a,b;
};
srt st[100];

bool cmp( srt fst,srt se )
{
    if( fst.a == se.a )
    {
        if( fst.b == se.b )
            return fst.str<se.str;
        return fst.b<se.b;
    }
    return fst.a>se.a;
}

int main()
{
    LLI t,T;
    scanf("%lld",&T);
    for( int t=1; t<=T; t++ )
    {
        int de,ak;
        for( int i=0; i<10; i++ )
        {
            cin>>st[i].str>>st[i].a>>st[i].b;
        }
        sort(st,st+10,cmp);
        cout<<endl<<endl;
        for( int i=0; i<10; i++ )
            cout<<st[i].str<<" "<<st[i].a<<" "<<st[i].b<<endl;
    }
    return 0;
}

