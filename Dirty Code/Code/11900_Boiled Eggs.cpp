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
    int n,p,q,T;
    scanf("%d",&T);
    for( int t=1; t<=T; t++ )
    {
        int ar[100];
        scanf("%d%d%d",&n,&p,&q);
        //cout<<n<<" "<<p<<" "<<q<<endl;
        for( int i=0; i<n; i++ ) scanf("%d",&ar[i]);
        sort(ar,ar+n);
        int sum=0,cnt=0;
        //bool ok=0;
        //cout<<"roibn"<<endl;
        for( int i=0; i<n; i++ )
        {
            if( sum+ar[i] <= q && cnt< p )
                sum+=ar[i],cnt++;
            else break;
            //cout<<sum<<endl;
        }
        //cout<<sum<<" "<<t<<endl;
        if(sum == 0 && cnt == 0 )
            printf("Case %d: 0\n",t);
        else
            printf("Case %d: %d\n",t,cnt);
        fill(ar,0);
        n=0,p=0,q=0;
    }
    return 0;
}
