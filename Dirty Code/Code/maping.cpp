#include <bits/stdc++.h>

using namespace std;

#define fill(a,v) memset(a,v,sizeof (a))
#define mx 500005
int tree[mx*4+1];
void insrt(int indx,int st,int ed,int from,int to )
{
    if( st == from  and ed == to )
    {
        tree[indx]+=1;
        return ;
    }
    int mid=(st+ed)/2;
    if( to <= mid )
        insrt(indx*2,st,mid,from,to);
    else if( from > mid )
        insrt(indx*2+1,mid+1,ed,from,to);
    else
    {
        //cout<<"28  "<<st<<"  "<<mid<<endl;
        insrt(indx*2,st,mid,from,mid);
        insrt(indx*2+1,mid+1,ed,mid+1,to);
    }
}

int query(int indx,int st,int ed,int from,int to,int carry=0)
{
    if( st == from and ed == to )
    {
        return tree[indx]+carry;
    }
    int mid=(st+ed)/2;
    if( to <= mid)
        return query(indx*2,st,mid,from,to,carry+tree[indx]);
    else if( from > mid )
        return query(indx*2+1,mid+1,ed,from,to,carry+tree[indx]);
    else
    {
        int p1=query(indx*2,st,mid,from,mid,carry+tree[indx]);
        int p2=query(indx*2+1,mid+1,ed,mid,to,carry+tree[indx]);
        return p1+p2;
    }
}

int main()
{
    long long n,T,q;
    vector<long long>v,point,qpoint;
    scanf("%lld",&T);
    for( int t=1; t<=T; t++ )
    {
        scanf("%lld%lld",&n,&q);
        long long x,y;
        for( long long i=0; i<n; i++ )
        {
            scanf("%lld%lld",&x,&y);
            v.push_back(x);
            v.push_back(y);
            point.push_back(x);
            point.push_back(y);
        }
        for( long long i=0; i<q; i++ )
        {
            scanf("%lld",&x);
            qpoint.push_back(x);
            v.push_back(qpoint[i]);
        }
        sort(v.begin(),v.end());
        map<long,long>ar;
        long long k=1,len=v.size();
        for( int i=0; i<len; i++)
        {
            if( ar[v[i]] == 0)
                ar[v[i]]=k++;
        }
        len=point.size();
        for( int i=0; i<len; i+=2 )
        {
            x=ar[point[i]],y=ar[point[i+1]];
            insrt(1,1,k+10,x,y);
        }
        printf("Case %d:\n",t);
        len=qpoint.size();
        for( int i=0; i<len; i++ )
        {
            long long val=ar[qpoint[i]];
            long long m=query(1,1,k+10,val,val,0);
            printf("%lld\n",m);
        }
        fill(tree,0);
        point.clear();
        v.clear();
        qpoint.clear();
        ar.clear();
    }
}
