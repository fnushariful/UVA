#include<bits/stdc++.h>

using namespace std;

int par[30009];
int parent(int p)
{
    if( par[p] == p ) return p;
    else par[p]=parent(par[p]);
}
int indx[30009];
int main()
{
    int node,edge,T;
    //freopen("output.txt","w",stdout);
    scanf("%d",&T);
    for( int t=1; t<=T; t++ )
    {
        scanf("%d%d",&node,&edge);
        for(int i=1; i<=node; i++ ) par[i]=i;
        int x,y;
        for( int i=0; i<edge; i++ )
        {
            scanf("%d%d",&x,&y);
            // if( x>y) swap(x,y);
            int p=parent(x);
            int q=parent(y);
            if( p!=q )
                par[q]=par[p];
        }
        for( int i=1; i<=node; i++ )
        {
            parent(i);
        }
        for(int i=1; i<=node; i++ )
        {
            indx[par[i]]++;
        }
        for( int i=1; i<=node; i++ ) cout<<par[i]<<" ";
        int mx=INT_MIN;
        for( int i=1; i<=node; i++ )
            mx=max(indx[i],mx);
        cout<<mx<<endl;
        memset(par,0,sizeof par);
        memset(indx,0,sizeof indx);
    }
}

/*
5 4
1 2
5 3
4 2
3 5
*/
