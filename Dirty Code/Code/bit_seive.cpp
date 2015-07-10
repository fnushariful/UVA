#include <bits/stdc++.h>

#define MAX 46656
#define LMT 216
#define LEN 4830
#define RNG 100032
#define debug(x)         cerr<<__LINE__<<" "<<#x<<" "<<x<<endl;


using namespace std;

unsigned base[MAX/64], segment[RNG/64], primes[LEN];

#define sq(x) ((x)*(x))
#define mset(x,v) memset(x,v,sizeof(x))
#define chkC(x,n) (x[n>>6]&(1<<((n>>1)&31)))
#define setC(x,n) (x[n>>6]|=(1<<((n>>1)&31)))

/* Generates all the necessary prime numbers and marks them in base[]*/
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

/* Returns the prime-count within range [a,b] and marks them in segment[] */
int segmented_sieve(int a, int b)
{
    unsigned i, j, k, cnt = (a<=2 && 2<=b)? 1 : 0;
    if(b<2) return 0;
    if(a<3) a = 3;
    if(a%2==0) a++;
    mset(segment,0);
    for(i=0; sq(primes[i])<=b; i++)
    {
        j = primes[i] * ( (a+primes[i]-1) / primes[i] );
        //debug(j);
        if(j%2==0) j += primes[i];
        //debug(j);
        for( k=primes[i]<<1; j<=b; j+=k )
        {
            //debug(k);
            //debug(j);
            if(j!=primes[i])
                setC(segment, (j-a));
        }
    }
    for(i=0; i<=b-a; i+=2)
    {
        //cout<<i<<" "<<cnt<<endl;
        if(!chkC(segment, i))
            cout<<i+a<<endl;
    }
    return cnt;
}
int main()
{
    sieve();
    long long a,b;
    while(cin>>a>>b)
    {
        cout<<segmented_sieve(a,b)<<endl;
    }
    return 0;
}

