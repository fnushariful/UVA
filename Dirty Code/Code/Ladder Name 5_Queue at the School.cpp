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

vector<int>qq;
string str;
void fun()
{
    int i=0;
    while(i!= qq.size() )
    {
        int pp=qq[i];
        if( pp != str.size()-1 )
        {
            int j=pp;
            if( str[j+1] == 'G' )
                swap(str[pp],str[j+1]);
        }
        i++;
    }
}

int main()
{
    int t,p;
    while(cin>>p>>t)
    {
        cin>>str;
        int len=str.size();
        for( int i=0; i<len; i++ )
            if( str[i] == 'B' ) qq.PB(i);

        for(int i=0; i<t; i++ )
        {
            fun();
            qq.clear();
            for( int i=0; i<len; i++ )
                if( str[i] == 'B' ) qq.PB(i);
            //cout<<str<<endl;
        }
        cout<<str<<endl;
        qq.clear();
    }
    return 0;
}

