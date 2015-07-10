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
#define MX 1000009
#define RADIANS(x)       (((1.0 * x * PI) / 180.0))
#define DEGREES(x)       (((x * 180.0) / (1.0 * PI)))

LLI prime[MX],stor[MX];
bool status[MX];
pLLI pr[MX];

void sieve()
{
    LLI sqrtN=double(sqrt(MX));
    for( LLI i=2; i<MX; i+=2 ) status[i]=1;
    for( int i=3; i<=sqrtN; i+=2 )
    {
        if(!status[i])
            for( int j=i*i; j<=MX; j+=i+i )
                status[j]=1;
    }
    prime[0]=2;
    int k=1;
    for( LLI i=3; i<MX; i+=2 )
    {
        if(!status[i])
            prime[k++]=i;
    }
    pr[0].xx=2;
    for( int i=1; i<k; i++ )
    {
        pr[i].xx=prime[i];
        pr[i-1].yy=prime[i]-prime[i-1];
    }
}

LLI cnt[MX];
int main()
{
    sieve();
    LLI n,a,b;
    scanf("%lld",&n);
    for( int t=1; t<=n; t++ )
    {
        scanf("%lld%lld",&a,&b);
        if( a == b )
        {
            printf("No jumping champion\n");
            continue;
        }
        LLI low,up;
        for( int i=0; ; i++ ) if( pr[i].xx >= a )
            {
                low=i;
                break;
            }
        for( int i=low; ; i++ ) if( pr[i].xx >= b )
            {
                up=i;
                break;
            }
        LLI ue=INT_MIN;
        //cout<<low<<" "<<up<<endl;
        //cout<<pr[low].xx<<" "<<pr[up].yy<<endl;
        if( status[b] == 0 ) up+=1;
        for( int i=low; i<up-1; i++ )
        {
            cnt[pr[i].yy]++;
            if( ue<pr[i].yy ) ue=pr[i].yy;
            //cout<<pr[i].xx<<" "<<pr[i].yy<<endl;
        }
        LLI mx=INT_MIN;
        LLI pos=0;
        //cout<<ue<<endl;
        //for(int i=0; i<ue; i++ ) cout<<cnt[i]<<" ";
        for( int i=0; i<=ue; i++ )
        {
            if( mx<cnt[i] )
            {
                mx=cnt[i];
                pos=i;
                //cout<<mx<<" "<<pos<<endl;
            }
        }
        low=0;
        for( int i=0; i<=ue; i++ ) if( mx == cnt[i] ) low++;
        if( low > 1 || pos == 0)
            printf("No jumping champion\n");
        else
            printf("The jumping champion is %lld\n",pos);
        fill(cnt,0);
    }
    return 0;
}
