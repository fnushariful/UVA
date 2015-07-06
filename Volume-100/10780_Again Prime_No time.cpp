
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

LLI prime[MX],status[MX];

void sieve()
{
    for( LLI i=2; i<=MX; i+=2 ) status[i]=2;
    LLI sqrtN=sqrt(MX);
    status[1]=1;
    for( LLI i=3; i<=sqrtN; i+=2 )
    {
        if(!status[i] )
            for( LLI j=i*i; j<=MX; j+=i+i )
                status[j]=i;
    }
    for( int i=0; i<=MX; i++ )
    {
        if(!status[i])
            status[i]=i;
    }
}

int main()
{
    sieve();
    LLI n,m,T;
    scanf("%lld",&T);
    for( LLI t=1; t<=T; t++ )
    {
        scanf("%lld%lld",&m,&n);
        vector<LLI> v;
        LLI val=m;
        while(val>1)
        {
            v.PB(status[val]);
            val/=status[val];
        }
        sort(v.begin(),v.end());
        LLI cot=count(v.begin(),v.end(),v[v.size()-1]);
        //        for(int i=0; i<v.size(); i++ )
//            cout<<v[i]<<" ";
//        cout<<endl;

        LLI cnt=0,ed=n;
        for( LLI i=1; i<=ed; i++ )
        {
            n=i;
            while(n>1 )
            {
                if(status[n] == v[v.size()-1] ) cnt++;
                n/=status[n];
            }
        }
        if( cnt == 0)
            printf("Case %lld:\nImpossible to divide\n",t);
        else
            printf("Case %lld:\n%lld\n",t,cnt/cot);
    }
    return 0;
}
