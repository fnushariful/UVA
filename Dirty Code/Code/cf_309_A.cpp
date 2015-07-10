#include <bits/stdc++.h>

using namespace std;

#define SYN ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long int LLI;
typedef unsigned long long int ULLI;

#define debug(x)         cerr<<__LINE__<<" "<<#x<<" "<<x<<endl;
#define IMAX ((unsigned)1<<31)-1
#define eps 1e-11
#define fill(a,v) memset(a,v,sizeof (a))
#define SZ(X) ((int)X.size())
#define VI vector<int>
#define VS vector<string>
#define PB push_back



int main()
{
    int n,m,k;
    string str,fst,snd;
    vector<string>v;
    while(cin>>n)
    {
        for( int i=0; i<n; i++ )
        {
            cin>>str;
            v.PB(str);
        }
        int mx=INT_MIN;
        for( int i=0; i<v.size(); i++ )
        {
            str=v[i];
            int cnt=0;
            for( int j=i+1; j<n; j++ )
                if( str == v[j] ) cnt++;
            mx=max(cnt,mx);
        }
        cout<<mx+1<<endl;
    }
    return 0;
}

