#include <bits/stdc++.h>

#define LLI long long
#define xx first
#define yy second
using namespace std;

LLI fastExpo( LLI b, LLI p )
{
    LLI res=1,x=b;
    while(p)
    {
        if(p&1) res*=x;
        x*=x;
        p=p>>1;
    }
    return res;
}
LLI n,nm;
pair<LLI,LLI> pr[100000],ar[100000],ne[100000];

bool comp( pair<LLI,LLI> i, pair<LLI,LLI> j )
{
    return i.yy<j.yy;
}
int main()
{
    LLI k=0;
    for( LLI i=2; i<=46345; i++ )
    {
        for( LLI j=2; fastExpo(i,j)<=2147483648; j++ )
        {
            k++;
            pr[k].xx=j;
            pr[k].yy=fastExpo(i,j);
        }
    }
    //cout<<k<<endl;
    sort(pr,pr+46345,comp);
    k=1;
    for( int i=0; i<48037; i++ )
    {
        int m=pr[i].yy,mx=-21;
        for( ; m==pr[i].yy; i++ )  if( mx< pr[i].xx ) mx=pr[i].xx;
        ar[k].xx=mx,ar[k].yy=m,k++;
    }
    while(cin>>n)
    {
        int st=1,ed=k,mid;
        cout<<st<<" "<<ed<<endl;
        while(st<ed)
        {
            mid=(st+ed)/2;
            cout<<mid<<" "<<ar[mid].yy<<endl;
            if( ar[mid].yy == n ) break;
            if( ar[mid].yy > n ) ed=mid;
            else if( ar[mid].yy < n )st=mid+1;
        }
        cout<<ar[mid].xx<<" "<<ar[mid].yy<<endl;
    }
    return 0;
}

