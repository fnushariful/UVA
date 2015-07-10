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
    int T;
    scanf("%d",&T);
    for( int t=1; t<=T; t++ )
    {
        LLI n,val,pre=0,ar[100009];
        ar[0]=0;
        scanf("%lld",&n);
        LLI mx=INT_MIN;
        if( n == 0 ) mx=1;
        for( LLI i=1; i<=n; i++ )
        {
            scanf("%lld",&val);
            ar[i]=val;
            LLI dif=abs(pre-val);
            pre=val;
            mx=max(dif,mx);
        }
        // for(int i=0; i<=n; i++ ) cout<<ar[i]<<" ";
        val=mx;
        LLI cnt=0;
        //cout<<endl<<mx<<endl;
        for( int i=1; i<=n; i++ )
        {
            if( abs(ar[i]-ar[i-1]) == mx ) cnt++,mx--;
            else if( abs(ar[i]-ar[i-1]) < mx ) cnt++;
        }
        //cout<<cnt<<endl;
        //if( mx == -2147483648 ) mx=1;
        if( cnt == n ) mx=val;
        else mx=val+1;
        printf("Case %d: %lld\n",t,mx);
    }
    return 0;
}

