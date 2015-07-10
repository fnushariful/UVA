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
#define MX 1000000
#define RADIANS(x)       (((1.0 * x * PI) / 180.0))
#define DEGREES(x)       (((x * 180.0) / (1.0 * PI)))

string str;

int len;

struct trie
{
    char ch;
    trie *child[26];
    bool ed=false;
    trie()
    {
        memset(child,NULL,sizeof child);
    }
};

void insrt(trie *node,int idx)
{
    int pos=str[idx]-'a';
    if( len-1 == idx )
    {
        if( node->child[pos] == NULL )
        {
            node->child[pos]= new trie();
        }
        node->ed=1;
        return;
    }
    if( node->child[pos] == NULL )
    {
        node->child[pos]= new trie();
    }
    insrt(node->child[pos],idx+1);
}


bool srch(trie *node,int idx)
{
    int pos=str[idx]-'a';
    if( len-1 == idx )
    {
        if( node->child[pos] == NULL ) return idx+1;
        if( node->ed == 1 ) return idx+1;
        return idx+1;
    }
    if( node->child[pos] == NULL ) return idx+1;
    else srch(node->child[pos],idx+1);
}

//void del(trie *node,int idx)
//{
//    if( node == NULL ) return;
//    int pos=str[idx]-'a';
//    if( node->child[pos] != NULL ) del(node->child[pos],idx+1);
//    delete(node) ;
//}

void del(trie *node)
{
    for(int i=0; i<26; i++)
        if(node->child[i])
            del(node->child[i]) ;
    delete(node) ;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,m,k;
    SYN;

    //trie *node=root;
    vector<string>v;
    while(cin>>n)
    {
        if( n == 0 ) break;
        for( int i=0; i<n; i++ )
        {
            cin>>str;
            v.PB(str);
        }
        int sum=0;
        for( int i=0; i<n-1; i++ )
        {
            trie *root =new trie();
            str=v[i];
            len=str.size();
            insrt(root,0);
            for( int j=i+1; j<n; j++ )
            {
                str=v[j];
                len=str.length();
                sum+=srch(root,0);
            }
            //cout<<"ok"<<endl;
            del(root);
            //cout<<"ok"<<endl;
        }
        cout<<sum<<endl;
        v.clear();
        //del(root);
    }
    return 0;
}

