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
#define MSI map<string,int>
#define MLLI map<LLI,LLI>
#define MCI map<char,int>
#define PI acos(-1.0)
#define mk make_pair
#define pLLI pair<LLI,LLI>
#define xx first
#define yy second
#define st string

#define MOD 1000000007
#define MX 1000000
#define RADIANS(x)       (((1.0 * x * PI) / 180.0))
#define DEGREES(x)       (((x * 180.0) / (1.0 * PI)))


int main()
{
    int T;
    cin>>T;
    for( int t=1; t<=T; t++ )
    {
        int R,C,M,N;
        cin>>R>>C>>M>>N;
        string str;
        int stor[26];
        memset(stor,0,sizeof stor);
        for( int i=0; i<R; i++ )
        {
            cin>>str;
            for( int j=0; j<str.size(); j++ )
            {
                stor[str[j]-'A']++;
            }
        }
        int mx=INT_MIN,mi=INT_MAX;
        for( int i=0; i<26; i++ )
        {
            mx=max(mx,stor[i]);
        }
        int sum=0;
        for( int i=0; i<26; i++ )
        {
            if( stor[i]>0 )
            {
                if( stor[i] == mx ) sum+=(M*stor[i]);
                else sum+=(N*stor[i]);
            }
        }
        cout<<"Case "<<t<<": "<<sum<<endl;
    }
    return 0;
}

