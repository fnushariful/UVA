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
#define VI vector<LLI>
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
#define MX 1000009
#define RADIANS(x)       (((1.0 * x * PI) / 180.0))
#define DEGREES(x)       (((x * 180.0) / (1.0 * PI)))


int ar[MX];
struct tree
{
    int st,ed;
    int val;
    tree *lt,*rt;

    tree(int x,int y)
    {
        st=x;
        ed=y;
        lt=NULL;
        rt=NULL;
        val=INFINITY;
    }
};

tree *root= new tree(1,100000);

void insrt( tree *node,int indx,int value )
{
    if( node->st == node->ed )
    {
        node->val=ar[indx];
        return ;
    }
    int mid=(node->st+node->ed)/2;
    if( node->lt == NULL )
        node->lt=new tree(node->st,mid);
    if( node->rt == NULL )
        node->rt=new tree(mid+1,node->ed);

    node->val=min(node->lt->val,node->rt->val);
}


int query( tree *node,int st,int ed,int x,int y )
{
    if( node->st == x && node->ed == y )
        return node->val;
}

int main()
{
    int n,m,k;
    string str,st,fst,snd;
    return 0;
}

