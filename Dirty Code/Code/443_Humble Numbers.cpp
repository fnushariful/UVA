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

LLI humble[5]= {2,3,5,7,11};
LLI stor[MX];

bool Humble()
{
    stor[1]=1,stor[2]=2;
    int n,indx=3;
    for( int i=3; i<=10000; i++ )
    {
        //debug(i);
        int k=0;
        n=i;
        while( k<4 )
        {
            while( n%humble[k] == 0 )
            {
                n/=humble[k];
            }
            k++;
            if( n == 1 ) break;
        }
        if( n == 1 ) stor[indx++]=i;
    }
    cout<<stor[indx-1]<<endl;
}

int main()
{
    Humble();
    int n;
    while(scanf("%d",&n)==1)
    {
        printf("%lld\n",stor[n]);
    }
    return 0;
}
