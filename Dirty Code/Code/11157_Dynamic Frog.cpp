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
    //freopen("output.txt","w",stdout);
    int n,d;
    int T;
    scanf("%d",&T);
    for( int t=1; t<=T; t++ )
    {
        pair<char,LLI> pr[1000];
        cin>>n>>d;
        string str;
        LLI sum=0;
        pr[0].xx='B';
        pr[0].yy=0;
        pr[n+1].xx='B';
        pr[n+1].yy=d;
        for( int i=1; i<=n; i++ )
        {
            cin>>str,pr[i].xx=str[0];
            for( int j=2; j<str.size(); j++ )
            {
                sum=(sum*10)+(str[j]-'0');
            }
            pr[i].yy=sum;
            sum=0;
        }
        n+=1;
        pair< char,bool > ch[1000];
        ch[0].xx='B';
        ch[0].yy=0;
        ch[n+1].xx='B';
        ch[n+1].yy=0;

        LLI mx=INT_MIN,val;
        for( int i=1; i<=n; i++ ) ch[i].xx=pr[i].xx,ch[i].yy=0;
        for( int i=1; i<=n; i++ )
        {
            if( ch[i].xx == 'S' && ch[i-1].yy == 1 && ch[i-1].xx != 'B' ) ch[i].yy=0;
            else if( ch[i].xx == 'B' )
            {
                ch[i].yy=1;
                if( ch[i-1].yy == 1 )
                {
                    val=pr[i].yy-pr[i-1].yy;
                }
                else val=pr[i].yy-pr[i-2].yy;
                mx=max(mx,val);
            }
            else
            {
                ch[i].yy=1;
                if( ch[i-1].yy == 1 )
                {
                    val=pr[i].yy-pr[i-1].yy;
                }
                else val=pr[i].yy-pr[i-2].yy;
                mx=max(mx,val);
            }
        }
        //cout<<mx<<endl;
        LLI pre=d;
        bool ok=0;
        for( int i=n; i>=0; i-- )
        {
            if( ch[i].yy == 0  )
            {
                ok=1;
                val=abs(pr[i].yy-pre);
                pre=pr[i].yy;
                mx=max(mx,val);
            }
            else if( ch[i].xx == 'B' )
            {
                ok=1;
                val=abs(pr[i].yy-pre);
                pre=pr[i].yy;
                mx=max(mx,val);
            }
        }
        if( !ok ) printf("Case %d: %lld\n",t,d);
        else
            printf("Case %d: %lld\n",t,mx);
        //for( int i=0; i<n; i++ ) cout<<ch[i].xx<<" "<<ch[i].yy<<endl;

    }
    return 0;
}

