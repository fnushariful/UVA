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
int ar[100009];

int main()
{
    string str;
    int n;
    while(cin>>n)
    {
        for( int i=0; i<n; i++ )
        {
            cin>>ar[i];
        }
        int cnt=0;
        for( int i=0; i<n; i++ )
        {
            if( ar[i]-ar[i+1]<=0 ) cnt++;
        }
        if( cnt == n-1 )
        {
            cout<<0<<endl;
            return 0;
        }
        int pos=-1;
        cnt=0;
        for( int i=0; i<n-1; i++ )
        {
            if( ar[i]-ar[i+1]>0 )
            {
                pos=i;
                break;
            }

            if( ar[i]-ar[i+1]<0 ) cnt++;
        }
        if( pos!=-1)
        {
            for( int i=pos+1; i<n-1; i++ )
            {
                if( ar[i]-ar[i+1]<0 ) cnt++;
            }
        }
        bool ok=0;
        if( cnt == n-1 )
        {
            cout<<0<<endl;
            ok=1;
        }
        else
        {
            vector<int>v;
            for( int i=pos+1; i<n; i++ )
            {
                //cout<<ar[i]<<" ";
                v.PB(ar[i]);
            }
            //cout<<"OK"<<endl;
            for( int i=0; i<=pos; i++ )
            {
                //cout<<ar[i]<<" ";
                v.PB(ar[i]);
            }
            for( int i=0; i<n-1 i++ )
            {
                //cout<<v[i]<<" "<<v[i+1]<<endl;
                if( v[i]-v[i+1]>0 )
                {
                    cout<<-1<<endl;
                    return 0;
                }
            }
            ok=1;
            cout<<n-pos-1<<endl;
        }
        if( !ok)
            cout<<-1<<endl;
    }
    return 0;
}
