
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

LLI dp[100][3];
LLI N;

LLI fun(LLI pos,LLI flag,LLI num)
{
    if( pos == N ) return 1;
    if( dp[pos][flag] != -1 ) return dp[pos][flag];
    LLI ret=0;
    ret+=fun(pos+1,0,num*10+0);

    if( flag == 0 )
        ret+=fun(pos+1,1,num*10+1);
    if( ret>=1000000000 ) ret=1000000000;
    return dp[pos][flag]=ret;
}

int main()
{
    memset(dp,-1,sizeof dp);
    N=50;
    fun(0,0,0);
    for( int i=0; i<50; i++ )
    {
        for( int j=0; j<2; j++ )
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
