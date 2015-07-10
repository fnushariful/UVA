#include <bits/stdc++.h>

#define inf 1E20
#define pb push_back
#define vsort(v) sort(v.begin(),v.end())
#define loop(i,k,n) for(i=k;i<=n;i++)
#define rloop(i,n,k) for(i=n;i>=0;i--)
#define si(n) scanf("%d",&n);
#define sl(n) scanf("%I64d",&n);
#define sd(n) scanf("%lf",&n);
#define si2(m,n) scanf("%d %d",&m,&n);
#define si3(m,n,k) scanf("%d %d %d",&m,&n,&k);
#define wi(n) while(scanf("%d",&n))
#define wd(n) while(scanf("%lf",&n))
#define wib(n) while(scanf("%d",&n) && n)
#define wLb(n) while(scanf("%I64d",&n) && n)
#define wdb(n) while(scanf("%lf",&n) && n)
#define ws(n) while(getline(cin,n))
#define s(k) k.size()
#define pi acos(-1)
#define LB(v,k) lower_bound(v.begin(),v.end(),k);
#define MX 4*100000
using namespace std;
struct node
{
    int add,total;
};
int seg[MX+10];
void insert(int indx,int st,int ed,int ll,int ul,int val)
{
    if(st==ll && ed==ul)
    {
        seg[indx]=val;
        cout<<"34 "<<indx<<" "<<seg[indx]<<endl;
        return;
    }
    if(seg[indx]!=-1)
    {
        seg[indx*2]=seg[indx];
        seg[indx*2+1]=seg[indx];
        seg[indx]=-1;
        cout<<"41  "<<indx<<"  "<<seg[indx*2]<<"  "<<seg[indx*2+1]<<endl;
    }
    int mid=(st+ed)/2;
    if(ul<=mid) insert(indx*2,st,mid,ll,ul,val);
    else if(ll>mid) insert(indx*2+1,mid+1,ed,ll,ul,val);
    else
    {
        insert(indx*2,st,mid,ll,mid,val);
        insert(indx*2+1,mid+1,ed,mid+1,ul,val);
    }
}
int query(int indx,int st,int ed,int ll,int ul)
{
    if(seg[indx]!=-1)
    {
        return (ul-ll+1)*seg[indx];
    }
    int mid=(st+ed)/2;
    if(ul<=mid) return query(indx*2,st,mid,ll,ul);
    else if(ll>mid) return query(indx*2+1,mid+1,ed,ll,ul);
    else
        return (query(indx*2,st,mid,ll,mid)+query(indx*2+1,mid+1,ed,mid+1,ul));
}
int gcd(int a,int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
int main()
{
    int num,q,test,kase,i,j,k,l,m;
    int op;
    scanf("%d",&test);
    for(kase=1; kase<=test; kase++)
    {
        scanf("%d %d",&num,&q);
        printf("Case %d:\n",kase);
        for(i=1; i<=q; i++)
        {
            scanf("%d %d %d",&op,&j,&k);
            if(op==1)
            {
                scanf("%d",&l);
                insert(1,1,num,j+1,k+1,l);
            }
            else
            {
                int ans=query(1,1,num,j+1,k+1);
                m=(k-j+1);
                int get=gcd(ans,m);
                if(get==m) printf("%d\n",ans/get);
                else printf("%d/%d\n",(ans/get),(m/get));
            }
        }
        memset(seg,0,sizeof seg);
    }
    return 0;
}
