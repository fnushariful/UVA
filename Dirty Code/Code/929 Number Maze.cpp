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
#define MX  1005
#define RADIANS(x)       (((1.0 * x * PI) / 180.0))
#define DEGREES(x)       (((x * 180.0) / (1.0 * PI)))

LLI cost[MX][MX],vist[MX][MX],chk[MX][MX];
const int infinity = 1000000000;

struct data
{
    int r,c,dist;
    bool operator < ( const data& p ) const
    {
        return dist > p.dist;
    }
};

int dx[]= {+1,-1,+0,+0};
int dy[]= {+0,+0,+1,-1},row,col;

int dijkstra()
{
    for(int i=0; i<row; i++)
    {
        for( int j=0; j<col; j++ )
        {
            vist[i][j] =0;
            chk[i][j]=infinity;
        }
    }
    priority_queue<data> q;
    data u,v;
    u.r = 0, u.c = 0,u.dist=cost[0][0];
    //cout<<"57 "<<u.r<<" "<<u.c<<" "<<u.dist<<endl;
    chk[u.r][u.c]=cost[u.r][u.c];
    q.push(u);

    while( !q.empty() )
    {
        u=q.top();
        q.pop();
        int ucost=chk[u.r][u.c];
        //cout<<"65 "<<u.r<<" "<<u.c<<" "<<u.dist<<endl;
        if( vist[u.r][u.c] == 0 )
        {
            for(int i=0; i<4; i++)
            {
                v.r =u.r+dx[i],v.c =u.c+dy[i];
                if( vist[v.r][v.c] == 0 )
                {
                    if( v.r>=0 && v.r<row && v.c>=0 && v.c<col )
                    {
                        v.dist=ucost+cost[v.r][v.c];
                        //cout<<"76 "<<v.r<<" "<<v.c<<" "<<v.dist<<endl;
                        if( v.dist<chk[v.r][v.c] )
                        {
                            chk[v.r][v.c]=v.dist;
                            //cout<<chk[v.r][v.c]<<endl;
                            //cout<<"79 "<<v.r<<" "<<v.c<<" "<<v.dist<<endl;
//                            for(int i=0; i<row; i++ )
//                            {
//                                for( int j=0; j<col; j++ )
//                                    cout<<chk[i][j]<<" ";
//                                cout<<endl;
//                            }
//                            cout<<endl;
                            q.push( v );
                        }
                    }
                }
                //cout<<endl;
            }
            vist[u.r][u.c]=1;
        }
    }
    return chk[row-1][col-1];
}

int main()
{
    int E,N,src,des,T;
    scanf("%d",&T);
    for( int t=1; t<=T; t++ )
    {
        scanf("%d%d",&row,&col);
        for( int i=0; i<row; i++ )
        {
            for( int j=0; j<col; j++ )
                scanf("%lld",&cost[i][j]);
        }
        LLI prt=dijkstra();
        printf("%lld\n",prt);
        fill(vist,0);
    }
    return 0;
}

