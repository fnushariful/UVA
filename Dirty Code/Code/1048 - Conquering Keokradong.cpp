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

int ar[10009],n,k;
int binarysearch( int val)
{
    int part=0,sum=0;
    for( int i=0; i<n+1; i++ )
    {
        sum+=ar[i];
        if( sum > val )
        {
            sum=ar[i];
            part++;
        }
        //debug(sum);
    }
    //debug(part);
    return part<=k;
}

int main()
{
    int T;
    scanf("%d",&T);
    for( int t=1; t<=T; t++ )
    {
        int sum=0;
        scanf("%d%d",&n,&k);
        k++;
        int low=INT_MIN;
        for( int i=0; i<n+1; i++ )
        {
            scanf("%d",&ar[i]);
            int dif=abs(ar[i]-ar[i-1]);
            low=max(dif,low);
            sum+=ar[i];
        }
        int high=sum,dist;
        //debug(high);
        //debug(low);
        while(low<=high)
        {
            int mid=(low+high)/2;
            if( binarysearch(mid) )
            {
                dist=mid;
                //debug(dist);
                //debug(high);
                high=mid-1;
            }
            else low=mid+1;
            debug(low);
        }
        printf("Case %d: %d\n",t,dist);
        sum=0;
        int cnt=0;
        for(int i = 0 ; i < n+1 ; i++)
        {
            sum += ar[i] ;
            if (sum > dist)
            {
                printf("%d\n",sum-ar[i]);
                sum=ar[i];
                cnt++;
            }
            if(k-cnt+i>=n)
            {
                printf("%d\n",sum) ;
                for (int j=i+1; j<n+1 ; j++) printf ("%d\n" , ar[j]) ;
                break ;
            }
        }
        fill(ar,0);
    }
    return 0;
}
