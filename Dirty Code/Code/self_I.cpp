#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    while(cin>>str)
    {
        bool ok=false;
        for( int i=0; i<str.size(); i++ )
            if( str[i] == 'H' or str[i] == 'Q' || str[i] == '9' || str[i] == '+' )
            {
                cout<<"YES"<<endl;
                ok=true;
                return 0;
            }
        if(!ok ) cout<<"NO"<<endl;
    }
    return 0;
}
