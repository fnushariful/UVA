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
    LLI n,k,m,ar[1000];
    while(cin>>n>>m>>k)
    {
        for( int i=0; i<n; i++ ) cin>>ar[i];
        sort(ar,ar+n,greater<int>());
        LLI cnt=0;
        if( m<= k )
        {
            cout<<"0"<<endl;
            continue;
        }
        else if( m>k )
        {
            for( int i=0; i<n; i++ )
            {
                if( m <= k || m == 0 )
                {
                    if( m <= k ) m-=k;
                    break;
                }
                else if( m>k )
                {
                    if( k == 1 )
                    {
                        if( (m-ar[i]) <= 0 )
                        {
                            m-=ar[i];
                            cnt++;
                            break;
                        }
                        k-=1;
                        for( int j=i; j<n; j++ )
                        {
                            if( m <= 0 ) break;
                            else if( m == ar[j] )
                            {
                                m-=ar[j];
                                cnt++;
                                break;
                            }
                            else
                            {
                                ar[j]-=1,m-=ar[j],cnt++;
                                //cout<<"57 "<<ar[j]<<" "<<m<<" "<<cnt<<endl;
                            }
                        }
                    }
                    else if( m > k )
                    {
                        k-=1;
                        m-=ar[i],cnt++;
                        //cout<<"65 "<<ar[i]<<" "<<m<<" "<<cnt<<endl;
                    }
                }
            }
        }
        //cout<<m<<" "<<k<<" "<<cnt<<endl;
        if( m > 0 || cnt > n ) cout<<"-1"<<endl;
        else
            cout<<cnt<<endl;
    }
    return 0;
}

