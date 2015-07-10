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

#define MOD 1000000007
#define RADIANS(x)       (((1.0 * x * PI) / 180.0))
#define DEGREES(x)       (((x * 180.0) / (1.0 * PI)))


bool cmp(pLLI x,pLLI y )
{
    if( x.xx == y.xx ) return x.yy<y.yy;
    return x.xx<y.xx;
}

int main()
{
    pLLI pr[1000];
    int n;
    while(cin>>n)
    {
        for( int i=0; i<n; i++ )
            cin>>pr[i].xx>>pr[i].yy;
        sort(pr,pr+n,cmp);
        //for( int i=0; i<n; i++ )
            //cout<<pr[i].xx<<" "<<pr[i].yy<<endl;
        int cnt=0,ans=0;
        for( int i=0; i<n; i++ )
        {
            int x=pr[i].xx,y=pr[i].yy,cnt=0;
            bool x1,x2,x3,x4;
            x1=x2=x3=x4=1;
            for( int j=0; j<n; j++ )
            {
                if( x == pr[j].xx and y > pr[j].yy and x1== true)
                {
                    //cout<<x<<" "<<y<<" "<<pr[j].xx<<" "<<pr[j].yy<<endl;
                    cnt++;
                    x1=false;
                }
                else if( x == pr[j].xx and y<pr[j].yy  and x2 == true)
                {
                    cnt++,x2=false;
                   // cout<<x<<" "<<y<<" "<<pr[j].xx<<" "<<pr[j].yy<<endl;
                }
                else if( y == pr[j].yy and x> pr[j].xx and x3 ==true)
                {
                    cnt++,x3=false;
                    //cout<<x<<" "<<y<<" "<<pr[j].xx<<" "<<pr[j].yy<<endl;
                }
                else if( y == pr[j].yy and x<pr[j].xx and x4 == true )
                {
                    cnt++,x4=false;
                    //cout<<cnt<<endl;
                    //cout<<x<<" "<<y<<" "<<pr[j].xx<<" "<<pr[j].yy<<endl;

                }
                //debug(cnt);

            }
            if( cnt == 4  ) ans++;
            //cout<<"Robin"<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}
