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
#define MLLI map<LLI,LLI>
#define PI acos(-1.0)
#define mk make_pair
#define pLLI pair<LLI,LLI>
#define xx first
#define yy second

#define MOD 1000000007
#define RADIANS(x)       (((1.0 * x * PI) / 180.0))
#define DEGREES(x)       (((x * 180.0) / (1.0 * PI)))

bool cmp(pLLI x, pLLI y )
{
    if( x.xx == y.xx )
        return x.yy<y.yy;
    return x.xx<y.xx;
}

pLLI pr[10000009];
main()
{
    LLI n,p,ar[100009];
    while(cin>>n>>p)
    {
        MLLI mp;
        for( int i=0; i<n; i++ )
        {
            cin>>ar[i];
            mp[ar[i]]++;
        }
        sort(ar,ar+n);
        LLI s=0,a1,a2;
        for( map<LLI,LLI>:: iterator it=mp.begin(); it!=mp.end(); it++ )
        {
            LLI x=it->first;
            LLI y=it->second;
            LLI len=y*n;
            if( len+s >= p )
            {
                a1=x;
                LLI s2=0;
                for( MLLI:: iterator it2=mp.begin(); it2!=mp.end(); it2++ )
                {
                    LLI x2=it2->first;
                    LLI y2=it2->second;
                    LLI len2=y*y2;
                    if( len2+s2 >= p-s )
                    {
                        a2=x2;
                        break;
                    }
                    s2+=len2;
                }
                break;
            }
            s+=len;
        }
        cout<<a1<<" "<<a2<<endl;
    }
}
