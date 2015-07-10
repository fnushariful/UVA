#include <bits/stdc++.h>

using namespace std;
#define SYN ios_base::sync_with_stdio(0);cin.tie(0);

#define mx 150009
int tree[mx*4+1],pr[mx*4+1];

void insrt(int indx,int st,int ed,int val,int one,int pos)
{
    if( st == ed )
    {
        tree[indx]=one;
        pr[indx]=val;
        return;
    }
    int mid=(st+ed)/2;
    if( pos <= mid )
        insrt(indx*2,st,mid,val,one,pos);
    else insrt(indx*2+1,mid+1,ed,val,one,pos);
    tree[indx]=tree[indx*2]+tree[indx*2+1];
}


int query(int indx,int st,int ed,int pos )
{
    if( st == ed and tree[indx]==1 )
    {
        return indx;
    }
    int mid=(st+ed)/2;
    if( pos<=tree[indx*2] )
    {
        //cout<<"31 "<<indx<<endl;
        return query(indx*2,st,mid,pos);
    }
    else
    {
        if( tree[indx*2+1]<pos-tree[indx*2] ) return 0;
        //cout<<"37 "<<indx<<" "<<tree[indx]<<endl;
        return query(indx*2+1,mid+1,ed,pos-tree[indx*2]);
    }
    //tree[indx]=tree[indx*2]+tree[indx*2+1];
}


void update(int indx,int st,int ed,int pos)
{
    if( st == ed and tree[indx]== 1 )
    {
        tree[indx]=0;
        return;
    }
    int mid=(st+ed)/2;
    if( pos<=tree[indx*2]) update(indx*2,st,mid,pos);
    else update(indx*2+1,mid+1,ed,pos-tree[indx*2]);
    tree[indx]=tree[indx*2]+tree[indx*2+1];
}
int main()
{
    SYN;
    int n,ar[150009],val;
    int T,k;
    scanf("%d",&T);
    for( int t=1; t<=T; t++ )
    {
        scanf("%d%d",&n,&k);
        for( int i=1; i<=n; i++ )
        {
            scanf("%d",&val);
            insrt(1,1,n,val,1,i);
        }
        getchar();
        char op;
        printf("Case %d:\n",t);
        for( int i=0; i<k; i++ )
        {
            scanf("%c",&op);
            if( op == 'a' )
            {
                //printf("%c\n",op);
                scanf("%d",&val);
                printf("%d\n",val);
                insrt(1,1,10,val,1,n+1);
                n++;
                int p=query(1,1,n,val);
                cout<<p<<endl;

            }
            else if( op == 'c' )
            {
                //printf("%c\n",op);
                scanf("%d",&val);
                int p=query(1,1,n,val);
                cout<<p<<endl;
                if( tree[p] == 1 )
                    printf("%d\n",pr[p]);
                else if( tree[p] == 0 )
                    printf("0\n");
                if( tree[p] != 0 )
                    update(1,1,n,val);
            }
            getchar();
        }
    }
    return 0;
}

