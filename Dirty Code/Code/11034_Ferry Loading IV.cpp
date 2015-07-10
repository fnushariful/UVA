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


int main()
{
    int T;
    scanf("%d",&T);
    string str;
    LLI lmt,n;
    for( int t=1; t<=T; t++ )
    {
        scanf("%lld%lld",&lmt,&n);
        LLI val;
        queue<LLI>lf,rt;
        for( int i=0; i<n; i++ )
        {
            scanf("%lld",&val);
            cin>>str;
            if( str == "left" ) lf.push(val);
            else rt.push(val);
        }
        lmt=lmt*100;
        LLI sum=0,cnt=0;
        while( 1 )
        {
            if( lf.empty() && rt.empty() ) break;
            while(1)
            {
                val=lf.front();
                //debug(val);
                if(sum+val<=lmt && !lf.empty())
                {
                    sum+=val;
                    //debug(sum);
                    lf.pop();

                }
                else if( sum+val>lmt || lf.empty() )
                {
                    sum=0;
                    cnt++;
                    break;
                }
            }
            if( lf.empty() && rt.empty() ) break;

            while(1)
            {
                val=rt.front();
                //debug(val);
                if(  sum+val<=lmt  && !rt.empty() )
                {
                    sum+=val;
                    //debug(sum);
                    rt.pop();
                }
                else if( sum+val>lmt || rt.empty() )
                {
                    sum=0;
                    cnt++;
                    break;
                }
            }
        }
        printf("%lld\n",cnt);
    }
    return 0;
}

