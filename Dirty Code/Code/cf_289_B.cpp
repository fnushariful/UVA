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
    int n,k,ar[109];
    while(cin>>n>>k)
    {
        bool ok=0;
        int mx=INT_MIN,mi=INT_MAX;
        for( int i=0; i<n; i++ )
        {
            cin>>ar[i];
            if( mx<ar[i] ) mx=ar[i];
            if( mi> ar[i]) mi=ar[i];
        }
        if( (mx-mi) > k )
        {
            cout<<"NO"<<endl;
            return 0;
        }
        {
            int me=min(mi,k);
            cout<<"YES"<<endl;
            for( int i=0; i<n; i++ )
            {
                int j=1,c=0;
                if( ar[i] > k )
                {
                    if( ar[i]%2 == 0 && me%2 == 0 )
                        mi=ar[i]/me;
                    else
                        mi=(ar[i]/me);
                    for( j=j; c<me; c++,j++ )
                    {
                        for(int k=0; k<mi; k++ )
                            cout<<j<<" ";
                    }
                    c=c*mi;
                }
                for( j=j; c<ar[i] && c<k; j++,c++ )
                    cout<<j<<" ";
                //if( c <ar[i] ) cout<<j-1;
                cout<<endl;
                //cout<<c<<" "<<j<<endl;
            }
        }
    }
    return 0;
}
