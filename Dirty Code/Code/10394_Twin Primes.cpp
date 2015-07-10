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
#define MX 20000009
#define RADIANS(x)       (((1.0 * x * PI) / 180.0))
#define DEGREES(x)       (((x * 180.0) / (1.0 * PI)))

LLI prime[MX];
bool status[MX];

pLLI pr[MX];
void seive()
{
    LLI sqrtN=sqrt(MX);
    for( LLI i=3; i<sqrtN; i+=2 )
    {
        if( !status[i] )
            for( int j=i*i; j<=MX; j+=i+i )
                status[j]=1;
    }
    prime[0]=2;
    LLI k=0;
    LLI pos=3;
    for( int i=5; i<=MX; i+=2 )
    {
        if(!status[i])
        {
            if( i-pos == 2 )
            {
                pr[k].xx=pos;
                pr[k].yy=i;
                k++;
            }
            pos=i;
        }
    }
}

int main()
{
    //clock_t st,ed;
    //st=clock();
    seive();
    //ed=clock();
    //cout<<(ed-st)/(double)CLOCKS_PER_SEC;
    LLI n;
    //for(int i=0; i<10; i++ ) cout<<pr[i].xx<<" "<<pr[i].yy<<endl;
    while(scanf("%lld",&n)==1)
    {
        printf("(%lld, %lld)\n",pr[n-1].xx,pr[n-1].yy);
    }
    return 0;
}
