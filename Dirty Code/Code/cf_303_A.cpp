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

pair<int,int>pr[100009],lt,rt,tmp,tmp1;

int main()
{
    int n;
    while(cin>>n)
    {
        for( int i=0; i<n; i++ ) cin>>pr[i].xx>>pr[i].yy;
        int cnt=0;
        lt.xx=pr[0].xx-pr[0].yy;
        lt.yy=pr[0].xx;
        cnt++;
        pr[n].xx=INT_MAX;
        int l=pr[0].xx;
        for( int i=1; i<n; i++ )
        {
            tmp.xx=pr[i].xx-pr[i].yy;
            tmp1.yy=pr[i].xx+pr[i].yy;
            if( l < tmp.xx )
            {
                cnt++;
                l=pr[i].xx;
            }
            else if( pr[i].xx+pr[i].yy<pr[i+1].xx )
            {
                l=pr[i].xx+pr[i].yy;
                cnt++;
            }
            else l=pr[i].xx;
            //debug(cnt);
        }
        cout<<cnt<<endl;
    }
    return 0;
}
