#include <bits/stdc++.h>

using namespace std;

#define MX 100000

struct str
{
    int sum,mx,num;
} tree[MX*4+1];

void insrt( int indx, int st, int ed, int from, int to, int val)
{
    if( st == ed )
    {
        tree[indx].num=val;
        tree[indx].sum=1;
        tree[indx].mx=1;
        return;
    }
    int mid=(st+ed)/2;
    if( to<= mid )
    {

        insrt(indx*2,st,mid,from,to,val);
        if( tree[indx].num!=tree[indx*2].num )
        {
            //cout<<" 28 "<<indx<<endl;
            tree[indx].sum=1;
            tree[indx].num=val;
            tree[indx].mx=max(tree[indx].mx,tree[indx].sum);

        }
        else
        {
            //cout<<" 34 "<<indx<<endl;
            tree[indx].sum+=1;
            tree[indx].mx=max(tree[indx].mx,tree[indx].sum);
        }
    }
    else
    {
        insrt(indx*2+1,mid+1,ed,from,to,val);
        if( tree[indx].num!=tree[indx*2+1].num )
        {
            //cout<<" 44 "<<indx<<endl;
            tree[indx].sum=1;
            tree[indx].num=val;
            tree[indx].mx=max(tree[indx].mx,tree[indx].sum);

        }
        else
        {
            //cout<<" 50 "<<indx<<endl;
            tree[indx].sum+=1;
            tree[indx].mx=max(tree[indx].mx,tree[indx].sum);
        }
    }
    //cout<<indx<<"  "<<tree[indx].sum<<"  "<<tree[indx].mx<<"  "<<tree[indx].num<<endl;
}

int query( int indx,int st,int ed,int from,int to )
{
    if( st == from and ed == to )
    {
        cout<<"66 "<<indx<<endl;
        return tree[indx].mx;
    }
    int mid=(st+ed)/2;
    if( to <= mid )
        return query(indx*2,st,mid,from,to);
    else if( from> mid )
        return query(indx*2+1,mid+1,ed,from,to);
    else
    {
        int p=query(indx*2,st,mid,from,mid);
        int q=query(indx*2+1,mid+1,ed,mid+1,to);
        return max(p,q);
    }
}

int main()
{
    int n;
    while( cin>>n )
    {
        int val;
        for( int i=1; i<=n; i++ )
        {
            cin>>val;
            insrt(1,1,n,i,i,val);
        }
        for( int i=1; i<n*4; i++ )
            cout<<tree[i].mx<<" ";
        cout<<"hello "<<endl;
        int q,x,y;
        cin>>q;
        for( int i=0; i<q; i++ )
        {
            cin>>x>>y;
            cout<<query(1,1,n,x,y)<<endl;
        }
    }
    return 0;
}

