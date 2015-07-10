#include <bits/stdc++.h>

using namespace std;
#define N 500096

int parent[N];
int answer[N];
int find(int a)
{
    if(parent[a]==a)   return a;
    return parent[a]=find(parent[a]);
}
int Union(int a,int b)
{
    int u=find(a),v=find(b);
    if(u!=v)    parent[v]=u;
    if(u!=v)    answer[u]+=answer[v];
    return answer[v]=answer[u];
}
int main()
{
    int t;
    cin>>t;
    string a,b;
    int f;
    while(cin>>f)
    {
        map<string,int>m;
        int k = 0;
        for(int i = 1; i <= f*2; i++)
        {
            parent[i] = i;
            answer[i] = 1;
        }
        while(f--)
        {
            cin>>a>>b;
            if(m[a]==0) m[a]=++k;
            if(m[b]==0) m[b]=++k;
            cout<<Union(m[a],m[b])<<endl;
        }
    }
}

