#include <bits/stdc++.h>

using namespace std;

#define mx 100009
#define LLI long long

int tree[mx*4+10];
void insrt(LLI indx, LLI st,LLI ed,LLI pos,LLI val)
{
    if( st  == ed )
    {
        tree[indx]=val;
        return ;
    }
    LLI mid=(st+ed)/2;
    if( pos <= mid )
        insrt(indx*2,st,mid,pos,val);
    else
        insrt(indx*2+1,mid+1,ed,pos,val);
}

LLI query( LLI indx,LLI st,LLI ed,LLI from,LLI to,LLI carry=0 )
{
    if( st == from and ed == to )
        return tree[indx]+carry;
    LLI mid=(st+ed)/2;
    if( to<=mid )
        return query(indx*2,st,mid,from,to,carry+tree[indx]);
    else if( from > mid )
        return query(indx*2+1,mid+1,ed,from,to,carry+tree[indx]);
    else
    {
        LLI p=query(indx*2,st,mid,from,mid,carry+tree[indx]);
        LLI q=query(indx*2+1,mid+1,ed,mid+1,to,carry+tree[indx]);
        return p+q;
    }
}

void update( LLI indx,LLI st,LLI ed,LLI from,LLI to,LLI val )
{
    if( st == from and ed == to )
    {
        tree[indx]+=val;
        return ;
    }
    LLI mid=(st+ed)/2;
    if( to<=mid ) update(indx*2,st,mid,from,to,val);
    else if( from > mid ) update(indx*2+1,mid+1,ed,from,to,val);
    else
    {
        update(indx*2,st,mid,from,mid,val);
        update(indx*2+1,mid+1,ed,mid+1,to,val);
    }
}

int main()
{
    LLI T;
    scanf("%lld",&T);
    for( LLI t=1; t<=T; t++ )
    {
        LLI n,q,val;
        scanf("%lld%lld",&n,&q);
        for( LLI i=1; i<=n; i++ )
        {
            scanf("%lld",&val);
            insrt(1,1,n,i,val);
        }
        getchar();
        char ch;
        printf("Case %d:\n",t);
        LLI u,v,k;
        for( LLI i=0; i<q; i++ )
        {
            scanf("%c",&ch);
            if( ch == 'w' )
            {
                scanf("%lld%lld%lld",&u,&v,&k);
                getchar();
                update(1,1,n,u,v,k);
            }
            else if( ch == 'f' )
            {
                scanf("%lld",&u);
                getchar();
                printf("%lld\n",query(1,1,n,u,u,0));
            }
            else if( ch == 'm')
            {
                scanf("%lld",&u);
                getchar();
                LLI m=query(1,1,n,u,u,0);
                update(1,1,n,u,u,-m);
            }
        }
        memset(tree,0,sizeof tree);
    }
    return 0;
}
