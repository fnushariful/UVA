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
#define MX 32009
#define RADIANS(x)       (((1.0 * x * PI) / 180.0))
#define DEGREES(x)       (((x * 180.0) / (1.0 * PI)))


LLI prime[MX];
bool status[MX];
pLLI pr[MX];

vector<LLI>v;
void sieve()
{
    LLI sqrtN=double(sqrt(MX));
    for( LLI i=3; i<=sqrtN; i+=2 )
    {
        if( !status[i] )
            for( LLI j=i*i; j<MX; j+=2*i )
                status[j]=1;
    }
    LLI k=1;
    prime[0]=2;
    for( LLI i=3; i<MX; i+=2 )
        if(!status[i])
            prime[k++]=i;
    pr[0].xx=2;
    for( LLI i=1; i<=k; i++ )
    {
        pr[i].xx=prime[i];
        pr[i-1].yy=prime[i]-prime[i-1];
    }
    bool ok=false;
    int val=0;
    //cout<<k<<endl;
    v.PB(val);
    for( int i=0; i<=3376; i++ )
    {
        while(pr[i].yy == pr[i+1].yy )
        {
            //cout<<pr[i].xx<<" "<<i;
            v.PB(pr[i].xx);
            i++;
            ok=true;
        }
        //cout<<"RObin"<<pr[i+1].xx<<endl;
        if( ok )
        {
            v.PB(pr[i].xx);
            v.PB(pr[i+1].xx);
            //cout<<pr[i+1].xx<<" "<<i<<endl;
            v.PB(val);
            ok=false;
        }
    }
    //for( int i=0; i<v.size(); i++ ) cout<<v[i]<<endl;
}

int main()
{
    sieve();
    LLI a,b;
    while(scanf("%lld%lld",&a,&b))
    {
        if( a == 0 && b == 0 ) break;
        if( a> b) swap(a,b);
        for( int i=0; ; i++ ) if( v[i] >= a )
            {
                //cout<<i<<endl;
                a=i;
                break;
            }
        //else cout<<v[i]<<endl;
        //cout<<v[a]<<endl;
        for( int i=a; v[i]<b &&i<666; i++ )
        {
            //cout<<i<<endl;
            if( v[i-1] == 0 )
            {
                bool ok=false;
                //cout<<"Robin"<<endl;
                for( int j=i+1; v[j]<b+1; j++ ) if( v[j] == 0 )
                    {
                        printf("%lld",v[i]);
                        for( int j=i+1; ; j++,i++ ) if( v[j] == 0 )
                            {
                                printf("\n");
                                ok=true;
                                break;
                            }
                            else printf(" %lld",v[j]);
                        if( ok ) break;
                    }
            }
        }
    }
    return 0;
}
