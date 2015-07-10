#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        int p;
        vector<int> v;
        for( int i=0; i<n; i++ ) {
                cin>>p;
                v.push_back(p);
        }
        for( int i=0; i<n; i++ ) cout<<v[i]<<" ";
    }
    return 0;
}
