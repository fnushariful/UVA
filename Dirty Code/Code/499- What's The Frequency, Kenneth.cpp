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
    char str[100];
    int ar[100];
    while(gets(str))
    {
        int low[100],up[100];
        fill(low,0);
        fill(up,0);
        for( int i=0; i<strlen(str); i++ )
        {
            if( isupper(str[i]))
                up[str[i]-'A']++;
            else if( islower(str[i]))
                low[str[i]-'a']++;
        }
        int up_mx=INT_MIN,lw_mx=INT_MIN;
        for( int i=0 ; i<28; i++ ) if( up_mx< up[i] ) up_mx=up[i];
        for( int i=0; i<28; i++ ) if( lw_mx<low[i] ) lw_mx=low[i];

        set<char>upp,lw;
        int mx=max(up_mx,lw_mx);
        for( int i=0; i<28; i++ )
        {
            if( mx == up[i] ) upp.insert(i+'A');
        }
        for( int i=0; i<28; i++ )
        {
            if( mx == low[i] ) lw.insert(i+'a');
        }
        set<char>::iterator it;
        for( it=upp.begin(); it!=upp.end(); ++it ) cout<<*it;
        for( it=lw.begin(); it!=lw.end(); ++it ) cout<<*it;
        cout<<" "<<mx<<endl;
    }
    return 0;
}

