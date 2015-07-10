#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    string st;
    scanf("%d",&T);
    for( int t=1; t<=T; t++ )
    {
        cin>>st;
        string rev;
        rev=st;
        reverse(st.begin(),st.end());
        if( st == rev )
        {
            printf("Case %d: Alice\n",t);
            continue;
        }
        if( st.size()%2 == 0 ) printf("Case %d: Bob\n",t);
        else if( st.size()%2 == 1 ) printf("Case %d: Alice\n",t);
    }
    return 0;
}
