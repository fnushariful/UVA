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

#define MOD 1000000007
#define RADIANS(x)       (((1.0 * x * PI) / 180.0))
#define DEGREES(x)       (((x * 180.0) / (1.0 * PI)))


int main()
{
    int p,q,l,r,x,y;
    while(cin>>p>>q>>l>>r)
    {
        cout<<p<<" "<<q<<" "<<l<<" "<<r<<endl;
        int fs[500];
        int se[500];
        for( int i=0,j=0; i<p; i++,j+=2 ) cin>>fs[j]>>fs[j+1];
        //for( int i=0,j=0; i<p; i++,j+=2 ) cout<<fs[j]<<" "<<fs[j+1]<<endl;
        int cnt=0;
        for( int i=0; i<q; i++ )
        {
            cin>>x>>y;
            //for( int j=0,l=0; j<p; l+=2,j++ ) if( x == fs[l] or x == fs[l+1] or y == fs[l+1] or fs[l] == y ) cnt++;
            for( int j=l; j<=r; j++ )
            {
                int a=x+j,b=y+j;
                for(int k=0,m=0; k<p; k++,m+=2 )
                {
                    if( (a==fs[m] or a==fs[m+1]) or (b==fs[m] or b==fs[m+1]) ) cnt++;
                }
                cout<<"cnt "<<cnt<<endl;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
