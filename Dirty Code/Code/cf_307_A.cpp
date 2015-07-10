#include <bits/stdc++.h>

using namespace std;

#define SYN ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long int LLI;
typedef unsigned long long int ULLI;



int main()
{
    int n,m,k;
    string str[100],st,fst,snd;
    while(cin>>n>>m)
    {
        string st;
        for( int i=0; i<n; i++ )
        {
            cin>>st;
            str[i]+=st;
            //cout<<st<<endl;
        }
        int ret=0;

        for( int i=0; i<n; i++ )
        {
            for( int j=0; j<m; j++ )
            {
                st="";
                st+=str[i][j];
                st+=str[i][j+1];
                st+=str[i+1][j];
                st+=str[i+1][j+1];
                sort(st.begin(),st.end());
                //debug(st);
                if( st == "acef") ret++;
            }
            //debug(ret);
        }
        cout<<ret<<endl;
    }
    return 0;
}

