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

LLI fact[100];
LLI factorial(LLI n)
{
    LLI sum=1;
    fact[0]=1;
    for( int i=1; i<=20; i++ )
    {
        sum*=i;
        fact[i]=sum;
    }
}

int main()
{
    factorial(1);
    int T;
    scanf("%d",&T);
    string str;
    for( int t=1; t<=T; t++ )
    {
        cin>>str;
        int stor[30];
        fill(stor,0);
        for( int i=0; i<str.size(); i++ )
        {
            stor[str[i]-'A']++;
        }
        LLI val=str.size();
        val=fact[val];
        bool chk[30];
        fill(chk,0);
        for( int i=0; i<str.size(); i++ )
        {
            if( !chk[str[i]-'A'] )
            {
                val/=fact[stor[str[i]-'A']];
                chk[str[i]-'A']=1;
            }
        }
        printf("Data set %d: %lld\n",t,val);
    }
    return 0;
}

