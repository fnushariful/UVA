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
    int n,m,k;
    while(cin>>n)
    {
        vector<int>v;
        for( int i=0; i<n; i++ )
        {
            cin>>m;
            v.PB(m);
        }
        bool ok=0;
        for( int i=0; i<100000; i++ )
        {
            int cnt=0;
            for( int j=0; j<n; j++ )
            {
                if( v[j] != j ) break;
                else cnt++;
            }
            if( cnt == n )
            {
                ok=1;
                break;
            }
            //cout<<"ok"<<endl;
            for( int j=0; j<n; j++ )
            {
                if( j %2 == 0 && v[j] == n-1 ) v[j]=0;
                else if( j%2 ==1 && v[j] ==0 ) v[j]=n-1;
                else if( j%2 == 0 ) v[j]+=1;
                else if( j%2 == 1 ) v[j]-=1;
            }
//            for( int i=0; i<n; i++ ) cout<<v[i]<<" ";
//            cout<<endl;
        }
        if( ok ) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}

