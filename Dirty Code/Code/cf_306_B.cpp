#include <bits/stdc++.h>

using namespace std;

#define SYN ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long int LLI;
typedef unsigned long long int ULLI;

int main()
{
    LLI res,ar[1000],div,len,n,l,r,x;
    while(cin>>n>>l>>r>>x)
    {
        LLI ret=0;
        for( int i=0; i<n; i++ ) cin>>ar[i];
        len=fastExpo(2,n)-1;
        for( int i=1; i<=len; i++ )
        {
            int product=0,cnt=0;
            LLI mx=INT_MIN,mi=INT_MAX;
            for( int j=0; j<n; j++ )
            {
                if( i & (1<<j) )
                {
                    mx=max(mx,ar[j]);
                    mi=min(mi,ar[j]);
                    product+=ar[j];
                    cnt++;
                }
            }
            //cout<<product<<" "<<mx<<" "<<mi<<" "<<cnt<<endl;
            if( cnt >= 2)
            {
                //cout<<product<<" "<<mx<<" "<<mi<<" "<<cnt<<endl;
                if( product>=l && product<=r )
                {
                    if( abs(mx-mi) >= x ) ret++;
                    //debug(ret);
                }
            }
        }
        cout<<ret<<endl;
    }
    return 0;
}
