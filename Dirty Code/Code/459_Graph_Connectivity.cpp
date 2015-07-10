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
    getchar();
    getchar();
    while(T--)
    {
        char c;
        scanf("%c",&c);
        getchar();
        node=(c-'A')+1;
        for(int i=1; i<=node; i++ ) par[i]=i;
        int x,y;
        string str;
        while(getline(cin,str) && str.size())
        {
            //cout<<str<<endl;
            int x=(str[0]-'A')+1;
            int y=(str[1]-'A')+1;
            if( x > y ) swap(x,y);
            int p=parent(x);
            int q=parent(y);
            if( p!=q )
                par[q]=par[p];
        }
        for( int i=1; i<=node; i++ )
        {
            parent(i);
        }
        for( int i=1; i<=node; i++ ) cout<<par[i]<<" ";
        for(int i=1; i<=node; i++ )
        {
            indx[par[i]]++;
        }
        int mx=0;
        for( int i=1; i<=node; i++ )
            if( indx[i]>0) mx++;
        cout<<mx<<endl;
        if(T) cout<<endl;
        memset(par,0,sizeof par);
        memset(indx,0,sizeof indx);
    }
}


