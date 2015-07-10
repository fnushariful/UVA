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

int high,val[100],limit,k=0;
int fun( int pos,int coto,int number)
{
    if( pos == limit )
    {
        cout<<number<<endl;
        return 1;
    }
    int high=9;
    if( coto == 1 )
    {
        high=val[pos];
        debug(high);
    }
    for( int i=0; i<=high; i++ )
    {
        int next;
        if( coto == 1 )
        {
            if( i == high ) next=1;
            else next=0;
        }
        else next =coto;
        fun(pos+1,next,10*number+i);
    }
}

int main()
{
    int m,n;
    while(cin>>m)
    {
        limit=m;
        for( int i=0; i<m; i++ ) cin>>val[i];
        fun(0,1,0);
    }
    return 0;
}

