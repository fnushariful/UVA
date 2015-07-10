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

LLI n,m,ar[100000];

LLI container(LLI x)
{
    LLI sum=0,c=1;
    for( LLI i=0; i<n; i++ )
    {
        if((sum+ar[i])<=x)
        {
            sum+=ar[i];
        }
        else
        {
            if(ar[i]>x)
                return false;
            sum=ar[i];
            c++;
        }
        if(c>m)
            return false;
    }
    return true;
}

LLI binarysearch(LLI low, LLI high )
{
    LLI mid;
    while( low<high )
    {
        mid=(low+high)/2;
        if( container(mid) )
        {
            high=mid;
            if(container((low+high)/2) )
                mid=(low+high)/2;
            else mid=mid;
        }
        else
        {
            low=mid+1;
            if( container((low+high)/2))
                mid=(low+high)/2;
            else mid=mid;
        }
    }
    return mid;
}

struct book
{
    LLI fst,snd,total;
};
book pr[1000];

int main()
{
    while(cin>>n>>m)
    {
        LLI sum=0,mx=INT_MIN;
        for( int i=0; i<n; i++ ) cin>>ar[i],sum+=ar[i],mx=max(mx,ar[i]);
        sum=binarysearch(mx,sum);
        //printf("%lld\n",sum);
        LLI val=0,k=0,cnt=m;

        for( int i=0; i<n; i++ )
        {
            if( val == 0 ) pr[k].fst=i;
            if( val+ar[i] <= sum )
            {
                val+=ar[i];
                if( i == n-1 ) pr[k].snd=i+1,pr[k].total=val;
            }
            else
            {
                //cout<<i<<" "<<n<<endl;
                pr[k].snd=i,pr[k].total=val,val=0,k++,cnt--;
                //cout<<cnt<<" "<<(n-i)<<endl;
//                if( cnt == n-i && cnt != 1 && cnt != 0 )
//                {
//                    cout<<111<<" "<<cnt<<" "<<i<<endl;
//                    for( int j=i+1; j<=n; j++ )
//                    {
//                        pr[k].fst=pr[k].snd=j,pr[k].total=ar[j],k++;
//                    }
//                    break;
//                }
                i--;
            }
        }
        for( int i=0; i<k; i++ )
        {
//            for( int j=pr[i].fst; j<pr[i].snd; j++ )
//                cout<<ar[j]<<" ";
            cout<<pr[i].fst<<" "<<pr[i].snd<<" "<<pr[i].total<<endl;
            //cout<<"/";
        }
        cout<<endl;
    }
    return 0;
}

/*

9 3
100 200 300 400 500 600 700 800 900

*/
