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
#define MX  100009
#define RADIANS(x)       (((1.0 * x * PI) / 180.0))
#define DEGREES(x)       (((x * 180.0) / (1.0 * PI)))


LLI prime[MX];
bool status[MX];
LLI k;

void sieve()
{
    LLI sqrtN=sqrt(MX);
    for(int i=4; i<sqrtN; i+=2 ) status[i]=1;
    for( LLI i=3; i<=sqrtN; i+=2 )
    {
        if( !status[i])
            for( LLI j=i*i; j<=MX; j+=i+i )
                status[j]=1;
    }
    k=1;
    status[2]=0;
    prime[0]=2;
    for( LLI i=3; i<=MX; i+=2 )
        if(!status[i])
            prime[k++]=i;
    //for( int i=0; i<100; i++ ) cout<<prime[i]<<" ";
    //cout<<prime[k-1]<<endl;
}

LLI fact(LLI n)
{
    LLI stor[100009],c=0,sqrtN=sqrt(n),sum=1;
    for( LLI i=0; prime[i]<=sqrtN && i<k; i++ )
    {
        LLI val=prime[i],cnt=0;
        while(n%val == 0 )
        {
            n/=val;
            //stor[c++]=val;
            cnt++;
        }
        sum*=(cnt+1);
        //cout<<val<<endl;
    }
    //cout<<n<<endl;
    if( n> 1 ) sum*=2;
    //sum-=1;
    return sum;
}

int main()
{
    status[1]=1;
    status[0]=1;
    sieve();
    LLI n,T;
    scanf("%lld",&T);
    for( int t=1; t<=T; t++ )
    {
        int n,m;
        scanf("%d%d",&n,&m);
        if( n>m ) swap(n,m);
        vector<LLI>v;
        for( int i=n; i<=m; i++ )
        {
            if(!status[fact(i)]) v.PB(i);
        }
        if( v.size() == 0 ) printf("-1\n");
        else
        {
            printf("%d",v[0]);
            for( int i=1; i<v.size(); i++ )
                printf(" %d",v[i]);
            printf("\n");
        }
    }
    return 0;
}


