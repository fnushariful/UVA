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
#define MSLI map<string,LLI>
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
    while(scanf("%s",str))
    {
        int len=strlen(str);
        int ar[100];
        for( int i=0; i<len; i++ ) ar[i]=i;
        VS v;
        string st;
        sort(ar,ar+len);
        do
        {
            for( int i=0; i<len; i++ ) st+=str[ar[i]];
            v.PB(st);
            st.clear();
        }
        while(next_permutation(ar,ar+len));
        for( int i=0; i<v.size()/len; i++ )
        {
            for( int j=i; j<v.size(); j+=7 )
                cout<<v[j]<<endl;
        }
        v.clear();
        printf("\n");
    }
    return 0;
}
