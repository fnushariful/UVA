#include <bits/stdc++.h>
#define debug(x)         cerr<<__LINE__<<" "<<#x<<" "<<x<<endl;

using namespace std;

#define LLI long long


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

#define MX 10000009

LLI prime[MX];
bool status[MX];

void sieve()
{
    LLI sqrtN=sqrt(MX);
    for( LLI i=3; i<=sqrtN; i+=2 )
    {
        if(!status[i])
            for( LLI j=i*i; j<=MX; j+=i+i )
                status[j]=1;
    }
    prime[0]=2;
    LLI k=1;
    for( LLI i=3; i<MX; i+=2 )
        if(!status[i])
            prime[k++]=i;
    //for( int i=0;i<200; i++ ) cout<<prime[i]<<" ";
}

MLLI fst,snd;
MLLI ::iterator it;
bool fact( LLI n ,LLI m )
{
    bool ok=0;
    LLI sum=0,save=n,k=0,i,cnt,stor=n;
    for( i=0; prime[i]*prime[i]<=m; i++ )
    {
        cnt=0;
        if( m% prime[i]== 0 )
        {
            while( m%prime[i] == 0 )
            {
                m/=prime[i];
                cnt++;
            }
            fst.insert(mk(prime[i],cnt));
        }
    }
    if( m > 1 )
    {
        fst.insert(mk(m,1));
    }

    for( it=fst.begin(); it!=fst.end(); ++it )
    {
        n=stor;
        LLI p=it->xx;
        //cout<<p<<endl;
        LLI h = 0;
        while(n!=0)
        {
            h = h + n/p;
            n = n / p;
        }
        snd.insert(mk(p,h));
    }
    cnt=0;
    for( it=fst.begin(); it!=fst.end(); ++it )
    {
        LLI ind=it->xx;
        LLI val=it->yy;
        //cout<<ind<<" "<<val<<" "<<snd[ind]<<endl;
        if( snd[ind] >= val ) cnt++;
    }
    //cout<<" "<<cnt<<endl<<endl;
//    cout<<"n "<<stor<<endl;
//    for( it=snd.begin(); it!=snd.end(); ++it )
//        cout<<it->xx<<" "<<it->yy<<endl;
//        cout<<fst.size()<<endl;

    if( cnt == fst.size() )
    {
        fst.clear();
        snd.clear();
        return 1;
    }
    fst.clear();
    snd.clear();
    return 0;
}

int main()
{
    sieve();
    LLI n,m;
    LLI t=0;
    while(scanf("%lld%lld",&n,&m) !=EOF )
    {
        if( m == 0 )
        {
            printf ("%lld does not divide %lld!\n", m, n);
            continue;
        }
        if ( n == 0 )
        {
            if ( m == 1 )
            {
                printf("%lld divides %lld!\n", m, n);
            }
            else
            {
                printf("%lld does not divide %lld!\n", m, n);
            }
            continue;
        }
        if( m == 1 )
        {
            printf("%lld divides %lld!\n", m, n);
            continue;
        }
        bool ok=fact(n,m);
        //cout<<ok<<endl;
        if( ok )
            printf("%lld divides %lld!\n",m,n);
        else printf("%lld does not divide %lld!\n",m,n);
    }
    return 0;
}

