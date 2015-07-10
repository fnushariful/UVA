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

#define MOD 1000000007
#define MX 1000000
#define RADIANS(x)       (((1.0 * x * PI) / 180.0))
#define DEGREES(x)       (((x * 180.0) / (1.0 * PI)))

int main()
{
    string fst,snd;
    while(cin>>fst>>snd)
    {
        int len=fst.size();
        int len1=snd.size();
        if( len == len1 )
        {
            sort(fst.begin(),fst.end());
            sort(snd.begin(),snd.end());
            if( fst == snd ) cout<<"array"<<endl;
            else cout<<"need tree"<<endl;
        }
        else
        {
            int cnt=0;
            for( int i=0,j=0; i<len; i++ )
            {
                if( fst[i] == snd[j] )
                {
                    cnt++;
                    j++;
                }
            }
            if( cnt == len1 )
            {
                cout<<"automaton"<<endl;
                return 0;
            }
            cnt=0;
            sort(fst.begin(),fst.end());
            sort(snd.begin(),snd.end());
            for( int i=0,j=0; i<len; i++)
            {
                if( fst[i] == snd[j] ) cnt++,j++;
            }
            if( len1 == cnt ) cout<<"both"<<endl;
            else cout<<"need tree"<<endl;
        }
    }
    return 0;
}
