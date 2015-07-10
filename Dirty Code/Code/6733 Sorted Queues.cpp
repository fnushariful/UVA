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
    int n;
    int T;
    cin>>T;
    for( int t=1; t<=T; t++ )
    {
        int fst[10009],snd[10009];
        fst[0]=snd[0]=0;
        cin>>n;
        for( int i=1; i<=n; i++ ) cin>>fst[i];
        for( int i=1; i<=n; i++ ) cin>>snd[i];
        int cnt=0;
        fst[n+1]=INT_MAX;
        snd[n+1]=INT_MAX;

        for( int i=1; i<=n-1; i++ ) if( fst[i]-fst[i+1] < 0 ) cnt++;
        //cout<<cnt<<endl;
        for( int i=1; i<=n-1; i++ ) if( snd[i]-snd[i+1]< 0 ) cnt++;
        //cout<<cnt<<endl;
        if( cnt == (2*n)-2 )
        {
            cout<<0<<endl;
            continue;
        }
        //cout<<cnt<<endl;

        cnt=0;
        bool ok=0;
        for( int i=1; i<=n; i++ )
        {
            if( fst[i]-fst[i+1]>= 0 )
            {
                int j=1;
                while(j<=n)
                {
//                    debug(i);
//                    debug(j);
//                    debug(fst[i-1]);
//                    debug(snd[j]);
//                    debug(fst[i+1]);
//                    debug(fst[i]);
//                    debug(snd[j-1]);
//                    debug(snd[j+1]);
                    //bool ret=(fst[i-1]>snd[j]);// && snd[j] <fst[i+1]);//&& (snd[j-1]>fst[i] && fst[i]<snd[j+1]));
                    //cout<<ret<<endl;
                    if( (fst[i-1]<snd[j] && snd[j] <fst[i+1]) && (snd[j-1]<fst[i] && fst[i]<snd[j+1]) )
                    {
//                        debug(j);
//                        debug(i);
                        swap(fst[i],snd[j]),cnt++;
                        ok=1;
                        break;
                    }
                    else j++;
                }
            }
            if( !ok )
            {
                int j=1;
                if( fst[i]-fst[i+1]>= 0 )
                {
                    while(j<n)
                    {
//                        debug(i);
//                        debug(j);
//                        debug(fst[i-1]);
//                        debug(snd[j]);
//                        debug(fst[i+1]);
//                        debug(fst[i]);
//                        debug(snd[j-1]);
//                        debug(snd[j+1]);
                        //bool ret=(fst[i-1]>snd[j]);// && snd[j] <fst[i+1]);//&& (snd[j-1]>fst[i] && fst[i]<snd[j+1]));
                        //cout<<ret<<endl;
                        if( (fst[i]<snd[j] && snd[j] <fst[i+2]) && (snd[j-1]<fst[i+1] && fst[i+1]<snd[j+1]) )
                        {
                            ok=1;
//                            debug(j);
//                            debug(i);
                            swap(fst[i+1],snd[j]),cnt++;
                            break;
                        }
                        else j++;
                    }
                }
            }
        }
        if(ok ) cout<<cnt<<endl;
        else cout<<-1<<endl;
//        for( int i=1; i<=n; i++ ) cout<<fst[i]<<" ";
//        cout<<endl;
//        for( int i=1; i<=n; i++ ) cout<<snd[i]<<" ";
    }
    return 0;
}


