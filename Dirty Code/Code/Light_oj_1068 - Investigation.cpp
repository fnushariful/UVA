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

LLI high,val[100],limit;
LLI dp[13][3][82][100],k;
LLI fun( LLI pos,LLI coto,LLI sum,LLI number)
{
    LLI ret=0;
    if( dp[pos][coto][sum][number] != -1 ) return dp[pos][coto][sum][number];
    if( pos == limit )
    {
        //debug(number);
        if( (sum%k == 0 )&& (number %k == 0) ) return 1;
        return 0;
    }

    LLI high=9;

    if( coto == 1 )
    {
        high=val[pos];
        //debug(high);
    }

    for( int i=0; i<=high; i++ )
    {
        LLI next;
        if( coto == 1 )
        {
            if( i == high ) next=1;
            else next=0;
        }
        else next =coto;
        ret+=fun(pos+1,next,(sum+i)%k,(10*number+i)%k);
    }

    return dp[pos][coto][sum][number]=ret;
}

int main()
{
    string m,n;
    int T;
    scanf("%d",&T);
    for( int t=1; t<=T; t++ )
    {
        cin>>m>>n>>k;
        limit=m.size();
        fill(dp,-1);
        for( int i=0; i<limit; i++ ) val[i]=m[i]-'0';
        val[limit-1]=val[limit-1]-1;
        LLI ret=0;
        ret=fun(0,1,0,0);
        // cout<<ret<<endl;
        fill(dp,-1);
        limit=n.size();
        for( int i=0; i<limit; i++ ) val[i]=n[i]-'0';
        ret=fun(0,1,0,0)-ret;
        //cout<<ret<<endl;
        printf("Case %d: %lld\n",t,ret);
        fill(dp,-1);
    }
    return 0;
}



