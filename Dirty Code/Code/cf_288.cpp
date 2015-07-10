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
LLI n,m,k,num,mat[1009][1009],a,b;

int main()
{
    string str;
    bool ok=0;
    while(cin>>n>>m>>k)
    {
        LLI cnt=0,pos=-1;
        for(int i=0; i<k; i++)
        {
            cin>>a>>b;
            cnt++;
            {
                if(!ok)
                {
                    if( mat[a][b+1]== 1 && mat[a+1][b] == 1 && mat[a+1][b+1] == 1 ) ok=1,pos=cnt;
                    else if( mat[a+1][b]==1 && mat[a][b-1] == 1 && mat[a+1][b-1] == 1 ) ok=1,pos=cnt;
                    else if( mat[a-1][b]==1 && mat[a][b-1] == 1 && mat[a-1][b-1] == 1 ) ok=1,pos=cnt;
                    else if( mat[a-1][b]==1 && mat[a-1][b+1] == 1 && mat[a+1][b+1] == 1 ) ok=1,pos=cnt;
                    else mat[a][b]=1;
                }
            }
        }
        if( ok == 1 && pos!=-1 ) cout<<pos<<endl;
        else cout<<0<<endl;
    }
    return 0;
}
