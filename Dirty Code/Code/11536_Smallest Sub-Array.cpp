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
#define MX 1000009
#define RADIANS(x)       (((1.0 * x * PI) / 180.0))
#define DEGREES(x)       (((x * 180.0) / (1.0 * PI)))

LLI pos[MX],str[MX],n,m,k;
bool chk[MX];

LLI sliding_window( LLI n,LLI k )
{
    LLI j=INT_MAX,res=INT_MAX;
    for( LLI i=1; i<=k; i++ ) chk[i]=1,pos[i]=-1;
    for( LLI i=1; i<=n; i++ )
    {
        if( chk[str[i]] == 1 )
        {
            pos[str[i]]=i;
            j=INT_MAX;
            for( LLI l=1; l<=k; l++ ) if( j>pos[l] && pos[l]!=-1 ) j=pos[l];
        }
        LLI cnt=0;
        for( LLI l=1; l<=k; l++ )
        {
            if( pos[l] != -1 ) cnt++;
        }
        if( cnt == k )
        {
            res=min(res,i-j+1);
        }
    }
    return res;
}

int main()
{
    LLI T;
    scanf("%lld",&T);
    for( int t=1; t<=T; t++ )
    {
        scanf("%lld%lld%lld",&n,&m,&k);
        str[1]=1,str[2]=2,str[3]=3;
        for( LLI i=4; i<=n; i++ )
        {
            str[i]=((str[i-3]+str[i-2]+str[i-1])%m)+1;
        }
        LLI res=sliding_window(n,k);
        if( res == 2147483647 ) printf("Case %d: sequence nai\n",t);
        else
            printf("Case %d: %lld\n",t,res);
    }
    return 0;
}


/*

20
1 2 3 7 1 12 9 11 9 6 3 7 5 4 5 3 1 10 3 3

*/
