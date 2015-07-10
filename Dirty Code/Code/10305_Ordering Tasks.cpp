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

vector<int>result;
int arr[100009];
vector<int>mat[100009];
int k,taken[100009]= {0};
int n,m;


bool chk( int p)
{
    for( int j=0; j<mat[p].size(); j++ )
    {
        char v=mat[p][j];
        //debug(v);
        bool ok=0;
        for( int k=0; k<result.size(); k++ )
        {
            if( result[k] == v ) ok=1;
        }
        if(!ok) return 0;
    }
    return 1;
}

int flag=1;
void call()
{
    if( result.size() == n )
    {
        flag=0;
        printf("%d",result[0]);
        for( int i=1; i<n; i++ )
            printf(" %d",result[i]);
        printf("\n");
        return;
    }
    for( int i=0; i<n; i++ )
    {
        int p=arr[i];
        p=chk(p);
        if( taken[i] == 0  && p)
        {

            taken[i]=1;
            result.PB(arr[i]);
            call();
            return;
            taken[i]=0;
            result.pop_back();
        }
    }
}

int main()
{
    string str;
    int t=0;
    while(scanf("%d%d",&n,&m))
    {
        if( n == 0 && m == 0 ) break;
        for( int i=0; i<n; i++ ) arr[i]=i+1;
        int x,y;
        for( int i=0; i<m; i++ )
        {
            scanf("%d%d",&x,&y);
            mat[y].PB(x);
        }
        call();
        if( flag ) printf("Sandro fails.\n");
        flag=1;
//        for( int i=0; i<1000; i++ )
//            mat[i].clear();
//        fill(taken,0);
//        result.clear();
        t++;
    }
    return 0;
}


