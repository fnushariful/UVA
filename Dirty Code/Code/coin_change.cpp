
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
int coin[100]; //value of coins available
int make=18; //we will try to make 18
int dp[6][100],c[100];
int best1=INT_MAX,best2=INT_MAX,n;
int call(int i,int amount,int taken)
{
    if(i>=n)     //All coins have been taken
    {
        cout<<"40 "<<i<<" "<<amount<<" "<<taken<<endl;
        if(amount==0)return 1;
        else return 0;
    }
    if(dp[i][amount]!=-1) return dp[i][amount]; //no need to calculate same state twice
    int ret1=0,ret2=0;
    cout<<"46 "<<i<<" "<<amount<<" "<<taken<<endl;
    if(amount-coin[i]>=0 && taken<c[i] ) ret1=call(i,amount-coin[i],taken+1); //try to take coin i
    taken=0;
    cout<<"48 "<<i<<" "<<amount<<" "<<taken<<endl;
    ret2=call(i+1,amount,taken+1); //dont take coin
    return dp[i][amount]=ret1+ret2;
}
int main()
{
//  freopen("in","r",stdin);
    memset(dp,-1,sizeof(dp));
    while(cin>>n>>make)
    {
        for( int i=0; i<n; i++ )
            cin>>coin[i];
        for( int i=0; i<n; i++ ) cin>>c[i];
        cout<<call(0,make,0)<<endl;
    }
    return 0;
}
