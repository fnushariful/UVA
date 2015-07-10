#include<bits/stdc++.h>
using namespace std;

long arr[400009];

long root(long a)
{
    while(arr[a]>-1)
        a=arr[a];
    return a;
}

int main()
{
    long test,t,h,how,pos1,pos2,i,j,p,q;
    //freopen("output.txt","w",stdout);
    cin>>test;
    string a,b;
    for( t=1; t<=test; t++ )
    {
        cin>>how;
        for(i=0; i<=how*4; i++)
            arr[i]=-1;
        map<string,long> mp;
        int cnt=0;
        for(h=1; h<=how; h++)
        {
            cin>>a>>b;
            if( mp.find(a) == mp.end() )
            {
                mp[a]=cnt++;
            }
            if( mp.find(b) == mp.end() )
                mp[b]=cnt++;

            pos1=mp[a];
            pos2=mp[b];

            p=root(pos1);
            q=root(pos2);
            if(p!=q)
            {
                cout<<p<<" "<<q<<endl;
                arr[q]=p;
            }
            printf("%ld\n",arr[p]);
        }
        //memset(arr,-1,sizeof arr);
    }
    return 0;
}
