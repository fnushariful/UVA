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
#define MX 2000000
#define RADIANS(x)       (((1.0 * x * PI) / 180.0))
#define DEGREES(x)       (((x * 180.0) / (1.0 * PI)))


int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    LLI T,g,t=1;
    while(scanf("%lld",&g) == 1)
    {
        if( g == 0 ) break;
        printf("Scenario #%lld\n",t++);
        LLI n,val;
        map<LLI,LLI>mp;
        for( int i=1; i<=g; i++ )
        {
            scanf("%lld",&n);
            //cout<<n<<endl;
            for( int j=0; j<n; j++ )
            {
                scanf("%lld",&val);
                if( mp.find(val) == mp.end() )
                {
                    mp[val]=i;
                }
            }
        }
        //cout<<"OK"<<endl;
        string str;
        vector<LLI> v;
        while(cin>>str)
        {
            //cout<<str<<endl;
            if( str == "STOP" ) break;
            else if( str == "ENQUEUE" )
            {
                cin>>val;
                v.PB(val);
                //debug(val);
            }
            else if( str == "DEQUEUE" )
            {
                LLI ret=v[0];
                val=mp[ret];
                int len=v.size();
                vector<LLI>tmp;
                tmp.PB(ret);
                for( int i=1; i<len; i++ )
                {
                    if( mp[v[i]] == val )
                    {
                        tmp.PB(v[i]);
                    }
                }
                for( int i=0; i<len; i++ )
                {
                    if( mp[v[i]] != val )
                        tmp.PB(v[i]);
                }
                //for( int i=0; i<tmp.size(); i++ ) cout<<tmp[i]<<" ";
                v.clear();
                v=tmp;
                printf("%lld\n",v[0]);
                v.erase(v.begin()+0);
            }
        }
        printf("\n");
    }
    return 0;
}

