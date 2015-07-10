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

pair<int,int>pr[20009];
int cnt=0,n;
bool isstack()
{
    int rt=0;
    stack<int>st;
    for( int i=0; i<n; i++ )
    {
        if( pr[i].xx == 1 ) st.push(pr[i].yy);
        else if( pr[i].xx == 2 )
        {
            if( !st.empty())
            {
                int val=st.top();
                if( val !=  pr[i].yy ) return 0;
                st.pop();
                rt++;
            }
        }
    }
    if( cnt == rt ) return 1;
    return 0;
}

bool isqueue()
{
    int rt=0;
    queue<int>st;
    for(int i=0; i<n; i++ )
    {
        if( pr[i].xx == 1 )
            st.push(pr[i].yy);
        else if( pr[i].xx == 2 )
        {
            if(!st.empty())
            {
                int val=st.front();
                if( val != pr[i].yy ) return 0;
                st.pop();
                rt++;
            }
        }
    }
    if( cnt == rt ) return 1;
    return 0;
}

bool ispriority_queue()
{
    int rt=0;
    priority_queue<int>st;
    for( int i=0; i<n; i++ )
    {
        if( pr[i].xx == 1)
            st.push(pr[i].yy);
        else if( pr[i].xx == 2 )
        {
            if(!st.empty())
            {
                int val=st.top();
                if( val!= pr[i].yy ) return 0;
                st.pop();
                rt++;
            }
        }
    }
    if( cnt == rt ) return 1;
    return 0;
}
int main()
{
    //freopen("output.txt","w",stdout);
    string str,st,fst,snd;
    while(scanf("%d",&n)== 1)
    {
        int op,val,cnt1=0;
        cnt=0;
        for( int i=0; i<n; i++ )
        {
            scanf("%d%d",&op,&val);
            if( op == 1 ) pr[i].xx=op,pr[i].yy=val,cnt1++;
            else if( op == 2 ) pr[i].xx=op,pr[i].yy=val,cnt++;
        }
        bool fst=0,snd=0,trd=0;
        if( isstack() ) fst=1;
        if( isqueue() ) snd=1;
        if( ispriority_queue() ) trd=1;
        //cout<<fst<<" "<<snd<<" "<<trd<<endl;
        if( (fst+snd+trd == 0) || (cnt!= 0 && cnt1 == 0 ) )  cout<<"impossible"<<endl;
        else if( fst+snd+trd>1 ) cout<<"not sure"<<endl;
        else
        {
            if( fst ) cout<<"stack"<<endl;
            if( snd ) cout<<"queue"<<endl;
            if( trd ) cout<<"priority queue"<<endl;
        }
        memset(pr,-1,sizeof pr);
    }
    return 0;
}

