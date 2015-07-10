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
    string str;
    int t=1;
    while(cin>>str)
    {
        if( str == "#" ) break;
        if( str == "HELLO" ) printf("Case %d: ENGLISH\n",t);
        else if( str == "HOLA" ) printf("Case %d: SPANISH\n",t);
        else if( str == "HALLO" ) printf("Case %d: GERMAN\n",t);
        else if( str == "BONJOUR") printf("Case %d: FRENCH\n",t);
        else if( str == "CIAO") printf("Case %d: ITALIAN\n",t);
        else if( str == "ZDRAVSTVUJTE") printf("Case %d: RUSSIAN\n",t);
        else printf("Case %d: UNKNOWN\n",t);
        t++;
    }
    return 0;
}

