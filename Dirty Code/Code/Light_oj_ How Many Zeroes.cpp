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

char str[100];
LLI limit;
LLI dp[21][2][21][10];

void makeZero()
{
    for(int i=0; i<21; i++)
    {
        for(int j=0; j<2; j++)
        {
            for(int k=0; k<21; k++)
            {
                for(int l=0; l<2; l++)
                {
                    dp[i][j][k][l] = -1;
                }
            }
        }
    }
}

LLI fun( LLI pos,LLI coto,LLI sum,LLI before,LLI num )
{
    //cout<<"55 "<<pos<<"  "<<coto<<" "<<"  "<<sum<<"  "<<before<<" "<<num<<endl;
    if( dp[pos][coto][sum][before] != -1 )
    {
        //debug(num);
        //cout<<dp[pos][coto][sum][before]<<" "<<endl;
        return dp[pos][coto][sum][before];
    }
    LLI ret=0;
    if( pos == limit )
    {
        //debug(num);
        //debug(sum);
        return sum;
    }
    int high=9;
    int low;
    if( coto == 1 )
    {
        high=str[pos]-'0';
    }
    for( int i=0; i<=high; i++ )
    {
        LLI next,cnt,nx;
        if( coto == 1 )
        {
            if( i == high ) next=1;
            else next=0;
        }
        else next=coto;

        if(  before > 0 )
        {
            if( i == 0 )
                cnt=1;
            else cnt=0;
            nx=1;
            //debug(num);
        }
        else nx=i,cnt=0;
        ret+=fun(pos+1,next,sum+cnt,nx,num*10+i);
    }
    //cout<<"80 "<<pos<<"  "<<coto<<" "<<"  "<<sum<<"  "<<before<<" "<<num<<endl;
    return dp[pos][coto][sum][before]=ret;
    //cout<<dp[pos][coto][before][sum]<<endl;     // there is a problem if i turn on this memorization line this code doesn't work
    //return ret;
}

int main()
{
    LLI n,m,T;
    scanf("%lld",&T);
    for( int t=1; t<=T; t++ )
    {
        scanf("%lld",&n);
        LLI fst;
        if( n != 0 )
        {
            memset(dp,-1,sizeof dp);
            sprintf(str,"%lld",n-1);
            limit=strlen(str);
            //cout<<str<<endl;
            fst=fun(0,1,0,0,0);
        }
        else fst=-1;
        //cout<<fst<<endl;
        memset(dp,-1,sizeof dp);
        scanf("%lld",&n);
        sprintf(str,"%lld",n);
        //cout<<str<<endl;
        limit=strlen(str);
        LLI snd=fun(0,1,0,0,0);
        //cout<<snd<<endl;
        printf("Case %d: %lld\n",t,snd-fst);
    }
    return 0;
}

