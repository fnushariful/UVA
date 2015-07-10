#include<bits/stdc++.h>

using namespace std;

map<string,int> mp;

int main()
{
    int n;
    while(cin>>n)
    {
        string str;
        int k=0;
        for( int i=0; i<n; i++ )
        {
            cin>>str;
            if( mp.find(str) == mp.end() )
                mp[str]=k++;
        }
        for( map<string,int> :: iterator it=mp.begin(); it!=mp.end(); ++it )
            cout<<it->first<<" "<<it->second<<endl;
    }
    return 0;
}
