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

int n,hom[109],aw[109],homt[109],awt[109],tim,pnm,hrdt[109],hrd[109],hpnam[109],apnam[109],yhpnam[109],yapnam[109];
string crd,tnam;

int main()
{
    string hm,awy;
    while(cin>>hm>>awy)
    {
        cin>>n;
        for( int i=0; i<n; i++ )
        {
            cin>>tim>>tnam>>pnm>>crd;
            if( tnam == "a" && crd == "y" ) aw[pnm]++,awt[pnm]=tim;
            else if( tnam == "h" && crd == "y" ) hom[pnm]++,homt[pnm]=tim;
            if( crd == "r" && tnam == "h" && hpnam[pnm] == 0 && yhpnam[pnm] == 0 )
            {
                hpnam[pnm]=1;
                yhpnam[pnm]=1;
                cout<<hm<<" "<<pnm<<" "<<tim<<endl;
            }
            else if( crd == "r" && tnam == "a" && apnam[pnm] == 0 && yapnam[pnm]== 0)
            {
                apnam[pnm]=1;
                yapnam[pnm]=1;
                cout<<awy<<" "<<pnm<<" "<<tim<<endl;
            }
            for( int i=1; i<=99; i++ )
            {
                if( aw[i] == 2 && yapnam[i] == 0 && apnam[i] == 0)
                {
                    cout<<awy<<" "<<i<<" "<<awt[i]<<endl;
                    aw[i]=0;
                    yapnam[i]=1;
                }
                else if ( hom[i] == 2 && yhpnam[i]==0 && hpnam[i] == 0)
                {
                    cout<<hm<<" "<<i<<" "<<homt[i]<<endl;
                    hom[i]=0;
                    yhpnam[i]=1;
                }
            }
        }
    }
    return 0;
}
