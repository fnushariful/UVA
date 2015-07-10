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

#define MOD 1000000007
#define RADIANS(x)       (((1.0 * x * PI) / 180.0))
#define DEGREES(x)       (((x * 180.0) / (1.0 * PI)))


int main()
{
    int n;
    while(cin>>n)
    {
        VI ar;
        int k;
//        fill(pr,0);
        for( int i=0; i<n; i++ )
        {
            cin>>k;
            ar.PB(k);
        }
        sort(ar.begin(),ar.end());
        int val=0;
        for( int i=ar.size()-1; i>=0; i-- )
        {
            //debug(i);
            val+=ar[i];
            //debug(val);
            int sum=0;
            for( int j=0; j<i; j++ )
            {
                sum+=ar[j];
               // debug(sum);
            }
            if( sum < val ) {cout<<n-i<<endl;break;}
        }
    }
    return 0;
}
