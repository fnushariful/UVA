#include <bits/stdc++.h>

using namespace std;

#define fill(x,d) memset(x,d,sizeof x)
#define LLI long long
#define mx 1000009
vector<int>v,point,qpoint;
struct str
{
    LLI ret,pos;
};

typedef struct str mk;
mk tree[mx*4+10];
LLI pr[1000000];
void insrt( LLI indx,LLI st,LLI ed,LLI from,LLI to)
{
    if( st == ed )
    {
        //cout<<"21 "<<indx<<" "<<pr[st]<<" "<<pr[ed]<<" "<<pr[from]<<" "<<pr[to]<<"  "<<tree[indx].ret<<"  "<<min(abs(v[st]-v[from]),abs(v[ed]-v[to]))<<endl;
        tree[indx].ret=max(tree[indx].ret,min(abs(pr[st]-pr[from]),abs(pr[ed]-pr[to])));
        //cout<<"22 "<<tree[indx].ret<<endl;
        tree[indx].pos=pr[st];
        return;
    }
    LLI mid=(st+ed)/2;
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

LLI query( LLI indx,LLI st,LLI ed,LLI from )
{
    if( st == ed )
    {
        //cout<<indx<<endl;
        return tree[indx].ret;
    }
    LLI mid=(st+ed)/2;
    if( from <= mid )
        return query(indx*2,st,mid,from);
    else if( from > mid ) return query(indx*2+1,mid+1,ed,from);
}

int main()
{
    LLI T,x,y,n,k,q;
    map<LLI,LLI>ar;
    scanf("%lld",&T);
    for( LLI t=1; t<=T; t++ )
    {
        scanf("%lld%lld",&n,&q);
        LLI x,y,mxi;
        mxi=-21;
        for( LLI i=0; i<n; i++ )
        {
            scanf("%lld%lld",&x,&y);
            v.push_back(x);
            v.push_back(y);
            mxi=max(mxi,max(x,y));
            //cout<<mxi<<endl;
            point.push_back(x);
            point.push_back(y);
        }
        for( LLI i=0; i<q; i++ )
        {
            scanf("%lld",&x);
            qpoint.push_back(x);
            v.push_back(qpoint[i]);
        }
        sort(v.begin(),v.end());
        LLI k=1,len=v.size();
        for( LLI i=0; i<len; i++ )
        {
            if( ar.find(v[i]) == ar.end())
            {
                ar[v[i]]=k++;
                pr[k-1]=v[i];
            }
        }
       // for( int i=0; i<k; i++ ) cout<<pr[i]<<" ";//<<v[i]<<endl;
        //for( int i=0; i<pr.size(); i++ ) cout<<pr[i]<<" ";//<<v[i]<<endl;
        //cout<<ar[mxi]<<endl;

        len=point.size();
        for( LLI i=0; i<len; i+=2 )
        {
            x=ar[point[i]],y=ar[point[i+1]];
            //cout<<"92 "<<x<<" "<<y<<endl;
            insrt(1,1,ar[mxi],x,y);
        }
        printf("Case %lld:\n",t);
        len=qpoint.size();
        for( LLI i=0; i<len; i++ )
        {
            LLI val=ar[qpoint[i]];
            //cout<<"100 "<<val<<endl;
            LLI m=query(1,1,ar[mxi],val);
            printf("%lld\n",m);
        }
        fill(tree,0);
        point.clear();
        v.clear();
        qpoint.clear();
        ar.clear();
        fill(pr,0);
    }
    return 0;
}

/*

3
3 10
6 10
1 8
3 7
1 2 3 4 5 6 7 8 12 14

*/
