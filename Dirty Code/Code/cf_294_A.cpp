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

#define MOD
#define MX 1000007
#define RADIANS(x)       (((1.0 * x * PI) / 180.0))
#define DEGREES(x)       (((x * 180.0) / (1.0 * PI)))

LLI n;
map<LLI,LLI>ar,fst,snd;
LLI stor[MX];
int main()
{
    while(cin>>n)
    {
        LLI val,pos,mx=INT_MIN;
        for( int i=0; i<n; i++) cin>>val,ar[val]++,stor[i]=val;
        for( int i=0; i<n-1; i++ ) cin>>val,fst[val]++;
        for( int i=0; i<n-2; i++ ) cin>>val,snd[val]++;
        //sort(ar,ar+);
        //for( int i=0; i<=ar.size(); i++ ) cout<<ar[stor[i]]<<" ";
        for( int  i=0; i<n; i++ ) if( ar[stor[i]] > fst[stor[i]] )
            {
                pos=stor[i];
                cout<<stor[i]<<endl;
                break;
            }
        for(int i=0; i<n; i++ ) if( (ar[stor[i]] > snd[stor[i]]) && pos!=stor[i] )
            {
                cout<<stor[i]<<endl;
                break;
            }
    }
    return 0;
}
