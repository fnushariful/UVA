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

int main()
{
    LLI n,l,ar[10000];
    bool zero,ed;
    zero=ed=false;
    double dif=0,difed=0,mm;
    while(cin>>n>>l)
    {
        for( int i=0; i<n; i++ )
        {
            cin>>ar[i];
            if( ar[i] ==  0 ) zero=true;
            if( ar[i] == n ) ed=true;
        }
        sort(ar,ar+n);
        int mx=INT_MIN;
        if( n>1 )
        {
            for( int i=0; i<n; i++ )
            {
                if( mx < (ar[i+1]-ar[i]) )
                    mx=ar[i+1]-ar[i];
            }
            mm=mx/(double)2;
        }
        //cout<<mm<<endl;
        if( !zero )
        {
            dif=ar[0];
        }
        if( !ed )
            difed=l-ar[n-1];
        //cout<<dif<<" "<<difed<<" "<<endl;
        mm=max(mm,max(dif,difed));
        printf("%.10lf\n",mm);
    }
    return 0;
}
