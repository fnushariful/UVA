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
    int T,n,ar[100][100];
    while(scanf("%d",&n))
    {
        if( n == 0 ) break;
        for( int i=0; i<n; i++ )
        {
            for( int j=0; j<n; j++ )
                scanf("%d",&ar[i][j]);
        }
        int sum=0,stor[100],str[100],l=0,k=0;
        for( int i=0; i<n; i++ )
        {
            for( int j=0; j<n; j++ )
            {
                sum+=ar[i][j];
            }
            if( sum%2 == 1 )
                stor[k++]=i;
            sum=0;
        }
        for( int i=0; i<n; i++ )
        {
            for( int j=0; j<n; j++ )
            {
                sum+=ar[j][i];
            }
            if( sum%2 == 1 )
                str[l++]=i;
            sum=0;
        }
        if( l == k && k == 1 )
            printf("Change bit (%d,%d)\n",stor[0]+1,str[0]+1);
        else if( l == 0 && k == 0 ) printf("OK\n");
        else printf("Corrupt\n");
    }
    return 0;
}

