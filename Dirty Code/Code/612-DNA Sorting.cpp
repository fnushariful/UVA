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

#define MOD 1000000007
#define MX 1000000
#define RADIANS(x)       (((1.0 * x * PI) / 180.0))
#define DEGREES(x)       (((x * 180.0) / (1.0 * PI)))

struct st
{
    string a;
    int ps,value;
};
st pr[100];
int fun(string str)
{
    int len=str.size();
    int ret=0;
    for(int i=0; i<len; i++ )
    {
        int cnt=0;
        int val=str[i]-'A';
        //debug(val);
        for( int j=i; j<len; j++ )
        {
            int pos=str[j]-'A';
            //debug(pos);
            if( pos < val ) cnt++;
            //debug(cnt);
        }
        ret+=cnt;
    }
    //debug(ret);
    return ret;
}
bool cmp(st A,st B)
{
    if( A.value == B.value )
        return A.ps<B.ps;
    return A.value<B.value;

}

int main()
{
    int T,n,m;
    string str;
    scanf("%d",&T);
    for( int t=1; t<=T; t++ )
    {
        if( t!= 1 ) cout<<endl;
        scanf("%d%d",&n,&m);
        for( int i=0; i<m; i++ )
        {
            cin>>str;
            int ret=fun(str);
            pr[i].a=str;
            pr[i].value=ret;
            pr[i].ps=i;
        }
        sort(pr,pr+m,cmp);
        for( int i=0; i<m; i++ ) cout<<pr[i].a<<endl;
    }
    return 0;
}

