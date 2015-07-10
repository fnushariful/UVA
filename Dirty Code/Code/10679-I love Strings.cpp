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

int failure_table[1000009];

int main()
{
    SYN;
    int n,m,k,T;
    string str,st,fst,snd,pat,txt;
    scanf("%d",&T);
    for( int t=1; t<=T; t++ )
    {
        cin>>txt>>n;
        for( int i=0; i<n; i++ )
        {
            cin>>pat;
            int k=0,len=pat.size(),val=0,cnt=0,j=0;
            while( j<len )
            {
                if( pat[k] == txt[j] ) k++;
                j++;
            }
            //debug(k);
            //debug(j);
            if( k == len ) cout<<"y"<<endl;
            else cout<<"n"<<endl;
        }
    }
    return 0;
}

/*

abcdabd
abcabcdababcdabcdabde

*/

