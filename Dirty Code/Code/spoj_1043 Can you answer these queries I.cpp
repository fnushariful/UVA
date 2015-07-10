#include <bits/stdc++.h>

using namespace std;

typedef struct st
{
    int total,lsum,rsum,mxsum;
};

st tree[500000];
st update( st x, st y)
{
    st tmp;
    tmp.total=x.total+y.total;
    tmp.lsum=max(x.lsum,x.total+y.lsum);
    tmp.rsum=max(y.rsum,y.total+x.rsum);
    tmp.mxsum=max(x.rsum+y.lsum,max(x.mxsum,y.mxsum));
    return tmp;
}

void insrt(int ar[],int indx,int st,int ed)
{
    if( st == ed )
    {
        tree[indx].total=ar[st];
        tree[indx].lsum=tree[indx].rsum=tree[indx].mxsum=max(-100000,ar[st]);
        return;
    }
    int mid=(st+ed)/2;
    insrt(ar,indx*2,st,mid);
    insrt(ar,indx*2+1,mid+1,ed);
    tree[indx]=update(tree[indx*2],tree[indx*2+1]);
}


st query(int indx,int st,int ed,int from,int to )
{
    if( st == from and ed == to )
    {
        return tree[indx];
    }
    int mid=(st+ed)/2;
    if( to<=mid )
        return query(indx*2,st,mid,from,to);
    else if( from > mid ) return query(indx*2,mid+1,ed,from,to);
    else
    {
        return(update(query(indx*2,st,mid,from,mid),query(indx*2,mid+1,ed,mid+1,to)));
    }
}

int main()
{
    int n,a,b,c,d,ar[10000],q,x,y;
    while(cin>>n)
    {
        for( int i=0; i<n; i++ ) cin>>ar[i];
        insrt(ar,1,1,n);
        scanf("%d",&q);
        for( int i=0; i<q; i++ )
        {
            scanf("%d%d",&x,&y);
            printf("%d",query(1,1,n,x,y).mxsum);
        }
        //memset(tree,0,);
    }
    return 0;
}
