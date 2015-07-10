#include <bits/stdc++.h>

using namespace std;

typedef struct st
{
    int total,lsum,rsum,mxsum;
};

st tree[1000];

int main()
{
    int n,a,b,c,d;
    cin>>n;
    for( int i=0; i<n; i++ )
    {
        cin>>a>>b>>c>>d;
        tree[i].total=a,tree[i].lsum=b,tree[i].rsum=c,tree[i].mxsum=d;
    }
    for( int i=0;i<n; i++ )
        cout<<tree[i].total<<" "<<tree[i].lsum<<" "<<tree[i].rsum<<" "<<tree[i].mxsum<<endl;
    return 0;
}

