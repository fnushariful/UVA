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
pair<LLI,LLI> pr[10000000],ar[10000000];

bool comp( pair<LLI,LLI> i, pair<LLI,LLI> j )
{
    return i.yy<j.yy;
}
int main()
{
    LLI k=0;
    for( LLI i=2; i<=46345; i++ )
    {
        //cout<<fastExpo(-i,3)<<endl;
        for( LLI j=3; fastExpo(i,j)<=2147483648; j+=2 )
        {
            k++;
            pr[k].xx=j;
            pr[k].yy=fastExpo(-i,j);
            //cout<<pr[k].xx<<" "<<pr[k].yy<<endl;
        }
    }
    cout<<k<<endl;
    sort(pr,pr+46345,comp);
    k=1;
    for( int i=0; i<48037; i++ )
    {
        int m=pr[i].yy,mx=21;
        //cout<<m<<endl;
        for( ; m==pr[i].yy; i++ )  if( mx< pr[i].xx ) mx=pr[i].xx;
        //cout<<mx<<" "<<m<<endl;
        ar[k].xx=mx,ar[k].yy=m,k++;
    }
    while(cin>>n)
    {
//        for( int i=0; i<n; i++ )
//            cout<<pr[i].xx<<" "<<pr[i].yy<<endl;
        int st=0,ed=k,mid;
        //cout<<st<<" "<<ed<<endl;
        while(st<ed)
        {
            int mid=(st+ed)/2;
            cout<<mid<<" "<<ar[mid].yy<<endl;
            if( ar[mid].yy == n ) break;
            if( ar[mid].yy > n ) ed=mid;
            else if( ar[mid].yy < n )st=mid+1;
        }
        cout<<ar[mid].xx<<" "<<ar[mid].yy<<endl;
        for(int i=0; i<n; i++ ) cout<<ar[i].xx<<" "<<ar[i].yy<<endl;
    }
    return 0;
}

