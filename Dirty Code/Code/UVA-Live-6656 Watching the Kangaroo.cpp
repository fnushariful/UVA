#include <bits/stdc++.h>

using namespace std;

#define fill(x,d) memset(x,d,sizeof x)
//#define int long long
#define mx 1000

struct str
{
    int ret,pos;
};

typedef struct str mk;
mk tree[mx*4+10];

vector<long>L,R,points, all, n, q;
void compress()
{
    long a, b;
    for(long i=0; i<n; i++)
    {
        cin>>a>>b;
        L.pb(a);
        R.pb(b);
        all.pb(a);
        all.pb(b);
    }
    for(long i=0; i<q; i++)
    {
        cin>>a;
        points.pb(a);
        all.pb(a);
    }
    sort(all.begin(), all.end());
    map<long, long> m;
    long inx = 1;

    for(long i=0; i<all.size(); i++)
    {
        if(m.find(all[i])==m.end())
            m[all[i]]=inx++;
    }
}

void insrt( int indx,int st,int ed,int from,int to)
{
    if( st == ed )
    {
        cout<<"21 "<<indx<<" "<<st<<" "<<ed<<" "<<from<<" "<<to<<"  "<<tree[indx].ret<<"  "<<min(abs(st-from),abs(ed-to))<<endl;
        tree[indx].ret=max(tree[indx].ret,min(abs(st-from),abs(ed-to)));
        cout<<"22 "<<tree[indx].ret<<endl;
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
    int T,x,y,k;
    vector<int>v,point,qpoint;
    map<int,int>ar;
    scanf("%d",&T);
    for( int t=1; t<=T; t++ )
    {
        scanf("%d%d",&n,&q);
        /*int x,y,mxi;
        mxi=-21;
        for( int i=0; i<n; i++ )
        {
            scanf("%d%d",&x,&y);
            v.push_back(x);
            v.push_back(y);
            mxi=max(mxi,max(x,y));
            cout<<mxi<<endl;
            point.push_back(x);
            point.push_back(y);
        }
        for( int i=0; i<q; i++ )
        {
            scanf("%d",&x);
            qpoint.push_back(x);
            v.push_back(qpoint[i]);
        }*/
        compress();
        sort(v.begin(),v.end());
        int k=1,len=v.size();
        for( int i=0; i<len; i++)
        {
            if( ar[v[i]] == 0)
                ar[v[i]]=k++;
        }
        cout<<ar[mxi]<<endl;

        len=point.size();
        for( int i=0; i<len; i+=2 )
        {
            x=ar[point[i]],y=ar[point[i+1]];
            cout<<"92 "<<x<<" "<<y<<endl;
            insrt(1,1,ar[mxi],x,y);
        }
        printf("Case %d:\n",t);
        len=qpoint.size();
        for( int i=0; i<len; i++ )
        {
            int val=ar[qpoint[i]];
            cout<<"100 "<<val<<endl;
            int m=query(1,1,ar[mxi],val);
            printf("%d\n",m);
        }
        fill(tree,0);
        point.clear();
        v.clear();
        qpoint.clear();
        ar.clear();
    }
    return 0;
}
