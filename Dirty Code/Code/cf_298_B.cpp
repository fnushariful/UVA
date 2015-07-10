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
    int a,b,n,d;
    while(cin>>a>>b)
    {
        cin>>n>>d;
        int val,sum=a;
        if( n%2 == 0 ) val=n/2;
        else val=(n-1)/2;
        for( int i=0; i<val-1; i++ )
        {
            a=a+d;
            sum+=a;
            //debug(a);
            //debug(sum);
        }
        sum+=b;
        for( int i=0; i<val-1; i++ )
        {
            b=b+d;
            sum+=b;
            //debug(b);
            //debug(sum) ;
        }
        if( n%2 == 1 )
        {
            a=a+d;
            b=b+d;
            //debug(a);
            //debug(b);
            a=min(a,b);
            sum+=a;
        }
        cout<<sum<<endl;
    }
    return 0;
}

