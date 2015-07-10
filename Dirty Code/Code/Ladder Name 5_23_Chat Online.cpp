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
    LLI p,q,l,r;
    while(cin>>p>>q>>l>>r)
    {
        pair<LLI,LLI>fst[10000],snd[10000];
        for( int i=0; i<p; i++ )
        {
            cin>>fst[i].xx>>fst[i].yy;
        }
        LLI x,y,cnt=0;
        for( int i=0; i<q; i++ )
        {
            cin>>x>>y;
            for( int j=0; j<p; j++ )
            {
                if( fst[j].xx == x || fst[j].yy == x || fst[j].xx == y || fst[j].yy == y ) cnt++;
            }
            for( int j=l; j<=r; j++ )
            {
                int a=x+j,b=y+j;
//                debug(a);
//                debug(b);
                for( int k=0; k<p; k++ )
                {
//                                            debug(fst[k].xx);
//                        debug(fst[k].yy);

                    if( fst[k].xx == a || fst[k].yy == a || fst[k].xx == b || fst[k].yy == b )
                    {
                        debug(a);
                        debug(b);
                        //debug(fst[k].xx);
                        //debug(fst[k].yy);
                        cnt++;
                        debug(cnt);
                    }
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}

