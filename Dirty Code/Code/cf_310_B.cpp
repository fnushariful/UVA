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
    while(cin>>n)
    {
        cin>>str;
        //for( int j=0; j<n; j++ )
        {
            bool ok=0;
            int len=str.size();
            int cnt=0;
            for( int i=0; i<len; i++ ) if( str[i] == '1' ) cnt++;
            if( cnt == str.size() )
            {
                cout<<str.size()<<endl;
                return 0;
            }
            cnt=0;
            for( int i=0; i<len;  i++ ) if( str[i] == '0') cnt++;
            if( cnt == str.size())
            {

                cout<<str.size()<<endl;
                return 0;
            }

            for( int i=0; i<len; i++ )
            {
                if( str[i] == '1' && str[i+1] == '0' )
                {
                    ok=1;
                    str.erase(str.begin()+i);
                    //i--;
                    str.erase(str.begin()+(i));
                    //debug(str);
                }
                else if( str[i] == '0' && str[i+1] == '1' )
                {
                    str.erase(str.begin()+i);
                    //i--;
                    str.erase(str.begin()+(i));
                    ok=1;
                    //debug(str);
                }
                if( ok == 1 )
                {
                    i=0;
                    i--;
                    ok=0;
                    len=str.size();
                    //debug(str);
                }
                //cout<<str<<endl;
            }
        }
        cout<<str.size()<<endl;
    }
    return 0;
}

