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
#define st string

#define MOD 1000000007
#define MX 1000000
#define RADIANS(x)       (((1.0 * x * PI) / 180.0))
#define DEGREES(x)       (((x * 180.0) / (1.0 * PI)))

vector<string>v[10];

int main()
{
    v[0].PB("Alice"),v[0].PB("Ariel"),v[0].PB("Aurora"),v[0].PB("Phil"),v[0].PB("Peter"),v[0].PB("Olaf"),v[0].PB("Phoebus"),v[0].PB("Ralph"),v[0].PB("Robin");
    v[1].PB("Bambi"),v[1].PB("Belle"),v[1].PB("Bolt"),v[1].PB("Mulan"),v[1].PB("Mowgli"),v[1].PB("Mickey"),v[1].PB("Silver"),v[1].PB("Simba"),v[1].PB("Stitch");
    v[2].PB("Dumbo"),v[2].PB("Genie"),v[2].PB("Jiminy"),v[2].PB("Kuzko"),v[2].PB("Kida"),v[2].PB("Kenai"),v[2].PB("Tarzan"),v[2].PB("Tiana"),v[2].PB("Winnic");
    string str;
    int T;
    int cnt=0,cur=0,pre=0;
    cin>>T;
    for( int t=1; t<=T; t++ )
    {
        cin>>str;
        for( int i=0; i<3; i++ )
        {
            cur=i;
            for( int j=0; j<v[i].size(); j++ )
            {
                if( str == v[i][j] ) cnt+=abs(cur-pre),pre=cur;
            }
            //cout<<cnt<<endl;
        }

    }
    cout<<cnt<<endl;
    return 0;
}
