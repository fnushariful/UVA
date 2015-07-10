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
    string str,st,fst,snd;
    cin>>n;
    {
        pair<int,int> ar[10];
        int sum=0;
        for( int i=0; i<3; i++ )
        {
            cin>>ar[i].xx>>ar[i].yy;
            sum+=ar[i].xx;
        }
        sum-=ar[2].xx;
        vector<int>v;
        for( int i=2; i>=0; i-- )
        {
            if( (n-sum) > ar[i].yy )
            {
                v.PB(ar[i].yy);
                n-=ar[i].yy;
            }
            else if( ar[i].xx <= (n-sum) )
            {
                if( n-sum<=ar[i].yy )
                {
                    v.PB(n-sum);
                    n-=ar[i].xx;
                }
                else
                {
                    v.PB(n-ar[i].yy);
                    n-=ar[i].yy;
                }
            }
            sum-=ar[i-1].xx;
        }
        //        cout<<"ok"<<endl;
        for( int i=v.size()-1; i>=0; i-- ) cout<<v[i]<<" ";
    }
    return 0;
}

