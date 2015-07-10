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
pLLI pr[10000];

bool indx[10000];
int main()
{
    LLI n,x,y;
    while(cin>>n>>x>>y)
    {
        for( int i=0; i<n; i++ ) cin>>pr[i].xx>>pr[i].yy;
        sort(pr,pr+n);
        LLI cnt=0;
        for( int i=0; i<n; i++ )
        {
            LLI a,b;
            if( indx[i] == 0 )
            {
                a=pr[i].xx,b=pr[i].yy;
                if( abs(a-x) == 0 )
                {
                    cnt++;
                    indx[i]=1;
                    continue;
                }
                cout<<cnt<<endl;
                LLI val=abs(b-y)/abs(a-x);
                for(int j=i+1; j<n; j++ )
                {
                    if( indx[j] == 0)
                    {
                        LLI man=abs(pr[j].yy-y);
                        LLI div=abs(pr[j].xx-x);
                        if( div == 0 )
                        {
                            cnt++,indx[j]=1;
                            continue;
                        }
                        else man=man/div;
                        if( man == val && indx[j] == 0 )
                        {
                            cnt++;
                            indx[j]=1;
                        }
                    }
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
