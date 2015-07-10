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

int ar[100009];
int main()
{
    int n;
    while(cin>>n)
    {
        for( int i=0; i<n; i++ ) cin>>ar[i];
        int cnt=1,val=ar[0];
        if( val != ar[1] )
            cnt+=val*2;
        else cnt+=ar[0];
        cout<<cnt<<endl;
        for( int i=1; i<n-1; i++ )
        {
            if( ar[i] == val ) cnt+=1;
            else if( ar[i] == ar[i+1] ) cnt+=ar[i];
            else cnt+=ar[i]*2;
            val=ar[i];
            cout<<cnt<<endl;
        }
        cout<<val<<" "<<cnt<<endl;
        if( val == ar[n-1] ) cout<<cnt+1+ar[n-1]<<endl;
        else
            cout<<cnt+ar[n-1]+ar[n-1]<<endl;
    }
    return 0;
}

