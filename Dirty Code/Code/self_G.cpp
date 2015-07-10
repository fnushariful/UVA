#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        string str;
        int cnt=0;
        for( int i=0; i<n; i++ )
        {
            cin>>str;
            if( str[1] == '+' ) ++cnt;
            else --cnt;
        }
        cout<<cnt<<endl;
    }
       return 0;
}
