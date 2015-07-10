#include <bits/stdc++.h>

using namespace std;

#define LLI long long
#define mx 100000

struct str
{
    int ret,pos;
};

typedef struct str mk;
mk tree[mx*4+10];

void insrt( int indx,int st,int ed,int from,int to)
{
    if( st == ed )
    {
        // cout<<"21 "<<indx<<" "<<st<<" "<<ed<<" "<<from<<" "<<to<<"  "<<tree[indx].ret<<"  "<<min(abs(st-from),abs(ed-to))<<endl;
        tree[indx].ret=max(tree[indx].ret,min(abs(st-from),abs(ed-to)));
        //cout<<"22 "<<tree[indx].ret<<endl;
        tree[indx].pos=st;
        return;
    }
    int mid=(st+ed)/2;
    if( to <= mid )
        insrt(indx*2,st,mid,from,to);
    else if( from > mid )
        insrt(indx*2+1,mid+1,ed,from,to);
    else
    {
        insrt(indx*2,st,mid,from,to);
        insrt(indx*2+1,mid+1,ed,from,to);
    }
}

int query( int indx,int st,int ed,int from )
{
    if( st == ed )
    {
        //cout<<indx<<endl;
        return tree[indx].ret;
    }
    int mid=(st+ed)/2;
    if( from <= mid )
        return query(indx*2,st,mid,from);
    else if( from > mid ) query(indx*2+1,mid+1,ed,from);
}

int main()
{
    int T,x,y,n,k;
    scanf("%d",&T);
    for( int t=1; t<=T; t++ )
    {
        scanf("%d%d",&n,&k);
        for( int i=0; i<n; i++ )
        {
            scanf("%d%d",&x,&y);
            insrt(1,1,10000,x,y);
        }
        //for( int i=1; i<26; i++ ) printf("%d %d\n",i,tree[i].ret);
        printf("Case %d:\n",t);
        for( int i=0; i<k; i++ )
        {
            scanf("%d",&x);
            int p=query(1,1,10000,x);
            printf("%d\n",p);
        }
        memset(tree,0,sizeof tree);
    }
    return 0;
}

