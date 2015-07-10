#include<bits/stdc++.h>

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


int root[400009];

int parent(int x)
{
    //debug(x);
    if( root[x]!= x )
    {
        return root[x]=parent(root[x]);
    }
    return root[x];
}

int main()
{
    long T,t,h,how,pos1,pos2,i,j,p,q;
    //freopen("output.txt","w",stdout);
    scanf("%d",&T);
    //getchar();
    //getchar();
    int a,b,x,y,n,snd,fst;
    string str;
    for( int t=1; t<=T; t++ )
    {
        if( t!=1 ) printf("\n");
        scanf("%d",&n);
        fst=0,snd=0;
        getchar();
        for(int i=0; i<=n; i++ )
            root[i]=i;
        while(getline(cin,str) && str.size()!= 0 )
        {
            x=0,y=0;
            int i=2;
            while( str[i] != ' ')
            {
                x=(x*10)+(str[i]-'0');
                i++;
            }
            i++;
            //debug(i);
            while( i<str.size() )
            {
                y=(y*10)+(str[i]-'0');
                i++;
            }
            // cout<<x<<" "<<y<<endl;
            if( str[0] == 'c' )
            {
                p=parent(x);
                q=parent(y);
                if(p!=q)
                {
                    root[q]=root[p];
                }
            }
            else if( str[0] == 'q' )
            {
                p=parent(x);
                q=parent(y);
                //cout<<p<<" "<<q<<endl;
                if( p == q ) fst++;
                else snd++;
            }
        }
        printf("%d,%d\n",fst,snd);
    }
    return 0;
}
