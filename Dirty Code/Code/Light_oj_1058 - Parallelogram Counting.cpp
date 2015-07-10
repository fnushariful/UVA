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

pLLI chk[MX+10];

bool cmp(pLLI A , pLLI B)
{
    if(A.yy == B.yy ) return A.xx < B.xx;
    return A.yy < B.yy;
}
int main()
{
    int n,T;
    pLLI ar[10000];
    scanf("%d",&T);
    for( int t=1; t<=T; t++ )
    {
        scanf("%d",&n);
        for( int i=0; i<n; i++ ) scanf("%d%d",&ar[i].xx,&ar[i].yy);
        int k=0;
        //cout<<endl;
        for( int i=0; i<n; i++ )
        {
            for( int j=i+1; j<n; j++ )
            {
                int x=(ar[i].xx+ar[j].xx);
                int y=(ar[i].yy+ar[j].yy);
                chk[k].xx=x,chk[k].yy=y;
                k++;
            }
        }
        sort(chk,chk+k,cmp);
        int ans = 0 , cnt = 1;
        for( int i=0; i<k; i++ )
        {
            if( chk[i].xx!=chk[i-1].xx || chk[i].yy!= chk[i-1].yy )
            {
                ans += (cnt*(cnt-1))/2;
                cnt = 1;
            }
            else
            {
                cnt +=1;
            }
            //debug(cnt);
            //debug(ans);
        }
        printf("Case %d: %d\n",t,ans);
    }
    return 0;
}
