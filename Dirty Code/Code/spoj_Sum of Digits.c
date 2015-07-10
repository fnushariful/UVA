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
LLI dp[30][10][100];
LLI fun( LLI pos,LLI coto,LLI number)
{
    LLI ret=0;
    if( dp[pos][coto][number] != -1 ) return dp[pos][coto][number];
    if( pos == limit ) return sum;

    LLI high=9;

    if( coto == 1 )
    {
        high=val[pos]-'0';
        debug(high);
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
        ret+=fun(pos+1,next,number+i);
    }

    return dp[pos][coto][number]=ret;
}

int main()
{
    string m,n;
    while(cin>>m>>n)
    {
        if( m == "-1" && n == "-1" ) break;
        limit=m.size();
        for( int i=0; i<limit; i++ ) val[i]=m[i]-'0';
        val[limit-1]=val[limit-1]-1;

        LLI ret=fun(0,1,0);
        limit=n.size();
        for( int i=0; i<limit; i++ ) val[i]=n[i]-'0';
        ret=fun(0,1,0)-ret;
        printf("%lld",ret);
    }
    return 0;
}


