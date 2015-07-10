#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k,ar[1000];
    while(cin>>n>>k)
    {
        for(int i=0; i<n; i++ ) cin>>ar[i];
        int cnt=0;
        for( int i=0; i<n; i++ )
        {
            if( (ar[i] > ar[k-1] || ar[i] == ar[k-1]) && ar[i] > 0) cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
