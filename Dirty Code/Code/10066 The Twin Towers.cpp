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

int str1[1001],str2[1001];
int dp[1001][1001],row,col;
int fun(int i,int j)
{
    if( i == row || j == col ) return 0;
    if( dp[i][j] != -1 ) return dp[i][j];
    int ret;
    if( str1[i] == str2[j] )
        ret=1+fun(i+1,j+1);
    else
    {
        ret=max(fun(i+1,j),max(fun(i,j+1),fun(i+1,j+1)));
    }
    return dp[i][j]=ret;
}

int main()
{
    //freopen("output.txt","w",stdout);
    int t=1;
    while(scanf("%d%d",&row,&col) == 2 )
    {
        fill(str1,0);
        fill(str2,0);
        if( row == 0 && col == 0 ) break;
        for( int i=0; i<row; i++ ) scanf("%d",&str1[i]);
        for( int i=0; i<col; i++ ) scanf("%d",&str2[i]);
        fill(dp,-1);
        printf("Twin Towers #%d\n",t++);
        int ret=fun(0,0);
        printf("Number of Tiles : %d\n",ret);
        printf("\n");
    }
    return 0;
}

