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

bool pos[10009];
int main()
{
    int n,k,ar[10009],arp[10009],chk[10009],amp[10009];
    while(cin>>n>>k)
    {
        for( int i=0; i<n; i++ ) cin>>ar[i],arp[ar[i]]=i,amp[i]=ar[i];
        sort(ar,ar+n);
        int sum=0,cnt=0,i=0;
        for( int j=0; j<n; j++ )
        {
            if( sum+ar[j] > k ) break;
            else cnt++,chk[i++]=ar[j],sum+=ar[j];
        }
        cout<<cnt<<endl;
        for( int i=0; i<cnt; i++ )
        {
            if( arp[chk[i]] != -1 )
            {
                cout<<arp[chk[i]]+1<<" ";
                arp[chk[i]]=-1;
            }
            else if( arp[chk[i]] == -1 )
            {
                cout<<"R"<<endl;
                for(int j=0; j<n; j++ ) if( amp[j] == chk[i] && arp[chk[i]]!= -1 ) cout<<j+1<<" ";
            }
            cout<<arp[chk[i]]<<endl;
        }
        cout<<endl;
    }
    return 0;
}

