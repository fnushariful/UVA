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
#define MSLI map<string,LLI>
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


string add(string str)
{
    string tmp="";
    int len=str.size();
    for( int i=0; i<len; i++)
    {
        if( str[i] == '9' ) tmp+='0';
        else  tmp+=(str[i]-'0')+'1';
    }
    return tmp;
}

string shift(string str)
{
    int len=str.size();
    string tmp;
    tmp+=str[len-1];
    for( int i=0; i<len-1; i++ )
    {
        tmp+=str[i];
    }
    return tmp;
}

main()
{
    int n;
    string str,res;
    while(cin>>n>>str)
    {
        res=str;
        int i=0;
        int len=str.size(),cnt=0;
        for( int i=0; i<len; i++ )
        {
            if( str[0] == str[i] ) cnt++;
        }
        if( cnt == len )
        {
            for( int i=0; i<len; i++ ) cout<<0;
            cout<<endl;
            continue;
        }
        while( i<10000 )
        {
            string ad=add(str);
            string sh=shift(str);
            //debug(ad);
            //debug(sh);
            str=min(ad,sh);
            res=min(str,res);
            //debug(str);
            i++;
        }
        cout<<res<<endl;
    }
}
