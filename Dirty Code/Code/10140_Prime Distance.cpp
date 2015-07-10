#include <bits/stdc++.h>

typedef long long int LLI;
typedef unsigned long long int ULLI;

#define MAX 46656
#define LMT 216
#define LEN 4830
#define RNG 1000032

using namespace std;

unsigned base[MAX/64], segment[RNG/64], primes[LEN];

#define sq(x) ((x)*(x))
#define mset(x,v) memset(x,v,sizeof(x))
#define chkC(x,n) (x[n>>6]&(1<<((n>>1)&31)))
#define setC(x,n) (x[n>>6]|=(1<<((n>>1)&31)))
#define debug(x)         cerr<<__LINE__<<" "<<#x<<" "<<x<<endl;


void sieve()
{
    unsigned i, j, k;
    for(i=3; i<LMT; i+=2)
        if(!chkC(base, i))
            for(j=i*i, k=i<<1; j<MAX; j+=k)
                setC(base, j);
    for(i=3, j=0; i<MAX; i+=2)
        if(!chkC(base, i))
            primes[j++] = i;
}

LLI stor[1000000];
LLI indx;
void segmented_sieve(int a, int b)
{
    unsigned i, j, k, cnt = (a<=2 && 2<=b)? 1 : 0;

    if (b < 2)
        return ;
    indx=0;
    if(a < 3)
    {
        stor[indx++]=2;
        a = 3;
    }
    if(a%2==0) a++;
    mset(segment,0);
    for(i=0; sq(primes[i])<=b; i++)
    {
        j = primes[i] * ( (a+primes[i]-1) / primes[i] );
        if(j%2==0) j += primes[i];
        for(k=primes[i]<<1; j<=b; j+=k)
            if(j!=primes[i])
                setC(segment, (j-a));
    }
    for(i=0; i<=b-a; i+=2)
        if(!chkC(segment, i))
        {
            if( i+a != 1)
                stor[indx++]=i+a;
        }
    //cout<<indx<<" "<<a<<" "<<b<<endl;
}

int main()
{
    //freopen("output.txt","w",stdout);
    sieve();
    long long a,b,fst,snd,fst_last,snd_last;
    while(scanf("%lld%lld",&a,&b)==2)
    {
        //cout<<a<<" "<<b<<endl;
        if( a == b || b<=2 )
        {
            printf("There are no adjacent primes.\n");
            continue;
        }
        segmented_sieve(a,b);
        //cout<<indx<<" "<<a<<" "<<b<<endl;
        long long mi=INT_MAX,mx=INT_MIN;
        fst=snd=fst_last=snd_last=0;
        for( int i=0; i<indx-1; i++ )
        {
            //cout<<stor[i]<<" ";
            long long dif=stor[i+1]-stor[i];
            if( mi > dif )
            {
                mi=dif;
                fst=stor[i];
                snd=stor[i+1];
            }
            if( mx <dif )
            {
                mx=dif;
                fst_last=stor[i],snd_last=stor[i+1];
            }
        }
        if( fst == 0 || snd == 0 || fst_last == 0 || snd_last == 0 )
            printf("There are no adjacent primes.\n");
        else
            printf("%lld,%lld are closest, %lld,%lld are most distant.\n",fst,snd,fst_last,snd_last);
        memset(stor,0,sizeof stor);
    }
    return 0;
}

