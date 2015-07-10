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


int  fst[100],snd[100];
LLI n,m;

LLI fun(LLI n )
{
    //cout<<n<<endl;
    while(n>0)
    {
        if(n >= m ) break;
        n*=2;
    }
    LLI val=n/2;
    LLI dif=abs(val-m);
    LLI mi=abs(n-m);
    //cout<<val<<" "<<n<<endl;
    if( mi < dif ) return n;
    return val;
}

int main()
{
    while(cin>>n>>m)
    {
        LLI a=n,b=n;
        if(n>m)
        {
            cout<<n-m<<endl;
        }
        else if( n == m ) cout<<0<<endl;
        else if( n < m )
        {
            if( m%n == 0 )
            {
                LLI val=fun(n);
                //cout<<val<<endl;
                val/=n;
                cout<<val/2+(m-(val*n))<<endl;
            }
            else
            {
                //LLI dif;
                a--;
                LLI val=fun(a);
                LLI dif=((val/a)/2)+1+abs(val-m);
                LLI cnt=0;
                //cout<<"71 "<<dif<<" "<<val<<" "<<a<<endl;
                while(1)
                {
                    if( a == 1 ) break;
                    a--;
                    val=fun(a);
                    cnt=((val/a)/2)+(b-a)+abs(val-m);
                    if( cnt < dif ) dif=cnt;
                    //cout<<cnt<<" "<<dif<<" "<<val<<" "<<a<<endl;
                    cnt=0;
                }
                if( (m-b )> dif )
                    cout<<dif<<endl;
                else cout<<m-b<<endl;
            }
        }
    }
    return 0;
}

