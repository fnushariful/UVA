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
#define RADIANS(x)       (((1.0 * x * PI) / 180.0))
#define DEGREES(x)       (((x * 180.0) / (1.0 * PI)))


using namespace std;

int main()
{
    int n,k,m,ar[1000],num,ac[1000],arr[1000],flag[1000],save[1000];
    while(cin>>m>>k)
    {
        for( int i=0; i<k; i++ ) cin>>ar[i],flag[ar[i]]=1;;
        cin>>n;
        string str;
        for( int i=0; i<n; i++ )
        {
            cin>>str>>num;
            int cnt=0;
            for( int t=0; t<num; t++ )
            {
                cin>>ac[t];
                if( ac[t] == 0 ) cnt++;
            }
            for( int l=0; l<num; l++ ) if( flag[ac[l]] == 1 ) cnt++;
            save[i]=cnt;
        }
       for( int i=0; i<n; i++ ) cout<<save[i]<<" ";
    }
    return 0;
}
