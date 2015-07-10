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
#define MX 100000
#define RADIANS(x)       (((1.0 * x * PI) / 180.0))
#define DEGREES(x)       (((x * 180.0) / (1.0 * PI)))

int main()
{
    int n;
    while(cin>>n)
    {
        int ft[2*MX+10],sec[2*MX+10],val,cntft=0,cntsec=0,sesc=0,ftsc=0,f=0,s=0,ftl=0;
        for( int i=0; i<n; i++ )
        {
            cin>>val;
            if( val > 0 ) ftsc++,cntft+=val,ft[f++]=val;
            else if( val < 0 ) sesc++,cntsec+=val*(-1),sec[s++]=val*(-1);
            if( i == n-1 && val > 0 ) ftl=1;
        }
        if( cntft > cntsec ) cout<<"first"<<endl;
        else if( cntft < cntsec ) cout<<"second"<<endl;
        else
        {
            for( int i=0; i<min(f,s); i++ )
            {
                if( ft[i] > sec[i] )
                {
                    cout<<"first"<<endl;
                    return 0;
                }
                else
                {
                    cout<<"second"<<endl;
                    return 0;
                }
            }
            if( f == s )
            {
                if( ftl == 1 )cout<<"second"<<endl;
                else cout<<"first"<<endl;
            }
            else if(f > s ) cout<<"first"<<endl;
            else cout<<"second"<<endl;

        }
    }
    return 0;
}
