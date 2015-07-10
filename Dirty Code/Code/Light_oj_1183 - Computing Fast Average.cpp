#include <bits/stdc++.h>

using namespace std;

#define mx 100000
int tree[mx*4+10];

void insrt( int indx,int st,int ed,int from,int to,int val )
{
    if( st == from and ed == to )
    {
        tree[indx]=val;
        //cout<<indx<<" "<<tree[indx]<<endl;
        return ;
    }
    if( tree[indx]!= -1 )
    {
        tree[indx*2]=tree[indx];
        tree[indx*2+1]=tree[indx];
        tree[indx]=-1;
    }
    int mid=(st+ed)/2;
    if( to <= mid ) insrt(indx*2,st,mid,from,to,val);
    else if( from > mid ) insrt(indx*2+1,mid+1,ed,from,to,val);
    else
    {
        insrt(indx*2,st,mid,from,mid,val);
        insrt(indx*2+1,mid+1,ed,mid+1,to,val);
    }
}

int query( int indx,int st,int ed,int from,int to )
{
    if( tree[indx] != -1 )
    {
        //cout<<((to-from)+1)*tree[indx]<<" "<<indx<<endl;
        return ((to-from)+1)*tree[indx];
    }
    int mid=(st+ed)/2;
    if( to <=mid ) return query(indx*2,st,mid,from,to);
    else if( from > mid ) return query(indx*2+1,mid+1,ed,from,to);
    else return query(indx*2,st,mid,from,mid)+query(indx*2+1,mid+1,ed,mid+1,to);
}

int main()
{
    int T;
    scanf("%d",&T);
    for( int t=1; t<=T; t++ )
    {
        int n,q,op,st,ed;
        scanf("%d%d",&n,&q);
        printf("Case %d:\n",t);
        for( int i=0; i<q; i++ )
        {
            int val;
            scanf("%d%d%d",&op,&st,&ed);
            if( op == 1 )
            {
                scanf("%d",&val);
                insrt(1,1,n,st+1,ed+1,val);
            }
            else if( op == 2 )
            {
                int p=query(1,1,n,st+1,ed+1);
                int m=__gcd(p,(ed-st)+1);
                p/=m;
                int k=(ed-st+1)/m;
                printf("%d",p);
                if( k != 1)
                printf("/%d",k);
                printf("\n");

            }
        }
        memset(tree,0,sizeof tree);
    }
    return 0;
}
