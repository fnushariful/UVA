#include <bits/stdc++.h>

#define mx 100009
int tree[mx*4+10];
using namespace std;
struct stk
{
    int st,ed;
};

typedef struct stk mk;
bool cmp( mk x, mk y )
{
    if( x.st == y.st ) return x.ed<y.ed;
    return x.st<y.st;
}

void insrt( int indx,int st,int ed,int pos,int val)
{
    if( st == ed )
    {
        tree[indx]=val;
        return ;
    }
    int mid=(st+ed)>>1,lt=indx<<1,rt=lt|1;
    if( pos <= mid )
        insrt(lt,st,mid,pos,val);
    else insrt(rt,mid+1,ed,pos,val);
    tree[indx]=tree[lt]+tree[rt];
}

int query( int indx,int st,int ed,int from,int to)
{
    if( st == from and ed == to )
        return tree[indx];
    int mid=(st+ed)>>1,lt=indx<<1,rt=lt|1;
    if( to <= mid )
        return query(lt,st,mid,from,to);
    else if( from > mid )
        return query(rt,mid+1,ed,from,to);
    else
    {
        int p=query(lt,st,mid,from,mid);
        int q=query(rt,mid+1,ed,mid+1,to);
        return p+q;
    }
}
int n,ar[100009],q;
int mark[100009];
int main()
{
    mk qr[50009];
    int T,n,m;
    while( scanf("%d%d",&n,&m)== 2 )
    {
        for( int i=1; i<=n; i++ )
            scanf("%d",&ar[i]);
        for( int i=0; i<m; i++ )
        {
            qr[i].ed=m;
            scanf("%d",&qr[i].st);
        }
        sort(qr,qr+q,cmp);
        memset(mark,-1,sizeof mark);
        for( int i=0; i<m; i++ )
        {
            int j=qr[i].st;
            while( j <= qr[i].ed )
            {
                if( mark[ar[j]] == -1 )
                {
                    insrt(1,1,n,j,1);
                    mark[ar[j]]=j;
                }
                else if( mark[ar[j]] )
                {
                    insrt(1,1,n,mark[ar[j]],0);
                    mark[ar[j]]=j;
                    insrt(1,1,n,j,1);
                }
                j++;
            }
            int ans=query(1,1,n,qr[i].st,m);
            printf("%d\n",ans);
        }
        memset(tree,0,sizeof tree);
        memset(ar,0,sizeof ar);
        memset(qr,0,sizeof qr);
    }
    return 0;
}

