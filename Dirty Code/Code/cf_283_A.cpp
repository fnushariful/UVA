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
    int n,ar[1009];
    while(cin>>n)
    {
        for( int i=0; i<n; i++ ) cin>>ar[i];
        int dif,mi=INT_MAX,mx=INT_MIN;
        for( int i=1; i<n-1; i++ )
        {
            mx=INT_MIN;
            for( int k=0; k<n-1; k++ )
            {
                if( i == k+1 )
                {
                    dif=ar[i+1]-ar[i-1];
                    k++;
                    //debug(dif);
                }
                else
                {
                    dif=ar[k+1]-ar[k];
                    //debug(dif);
                }
                //cout<<dif<<endl;
                if( mx < dif ) mx=dif;
            }
            if( mi > mx ) mi=mx;
            //cout<<mi<<endl;
        }
        cout<<mi<<endl;
    }
    return 0;
}
