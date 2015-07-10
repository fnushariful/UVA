#include <bits/stdc++.h>


using namespace std;

int main()
{
    int n,k,ar[100009];
    while(cin>>n>>k)
    {
        int cnt=0;
        for( int i=0; i<n; i++ ) cin>>ar[i];
        for( int i=0; i<n; i++ ) if( ar[i] >= ar[k-1] and ar[i]!= 0) cnt++;
        cout<<cnt<<endl;
    }
    return 0;
}
