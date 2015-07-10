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

LLI n,cnt=0,prt;
vector<LLI> vi;
int fun(LLI pos,LLI before,LLI num)
{
    if( pos == n )
    {
        //debug(pos);
        debug(num);
        debug(cnt);
        //vi.PB(num);
        cnt+=1;
        if( cnt == n-1 ) prt=num;
        if( cnt > n ) return 0;
        return 0;
    }
    //debug(num);
    if( before == 0 && cnt<n )
    {
        for( int i=0; i<2; i++ )
        {
            //debug(pos);
            //debug(i);
            fun(pos+1,i,num*10+i);
        }
    }
    if( before == 1 )
        fun(pos+1,0,num*10+0);
    //cout<<vi.size()<<endl;
    if( cnt >n ) return 0;
}
int main()
{
    while(cin>>n)
    {
        fun(0,0,0);
        //for( int i=0; i<vi.size(); i++ ) cout<<vi[i]<<" ";
        //cout<<vi[n]<<endl;
        //vi.clear();
        cout<<prt<<endl;
        cnt=0;
    }
    return 0;
}

