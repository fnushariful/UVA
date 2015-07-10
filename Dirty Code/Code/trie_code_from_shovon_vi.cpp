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
    //debug(idx);
    if( len-1 == idx )
    {
        //debug(pos);
        if( node->child[pos] == NULL ) return false;
        //debug(idx);
        if( node->ed == 1 ) return true;
        return false;
    }
    if( node->child[pos] == NULL ) return false;
    else srch(node->child[pos],idx+1);
}

void del(trie *node,int idx)
{
    if( node == NULL ) return;
    int pos=str[idx]-'a';
    if( node->child[pos] != NULL ) del(node->child[pos],idx+1);
    delete(node) ;
}

int main()
{
    int n,m,k;

    trie *root =new trie();
    trie *node=root;
    printf("How many words to insert\n");
    while(cin>>n)
    {
        for( int i=0; i<n; i++ )
        {
            cin>>str;
            len=str.size();
            insrt(root,0);
        }
        printf("How many words for search\n");
        cin>>n;
        for( int i=0; i<n; i++ )
        {
            cin>>str;
            len=str.length();
            if( srch(root,0) ) cout<<"ok"<<endl;
            else cout<<"not ok"<<endl;
        }
        del(root,0);
    }
    return 0;
}

