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

int m,val;
template<class T> string toString(T n)
{
    ostringstream ost;
    ost << n;
    ost.flush();
    return ost.str();
}

int toInt(string s)
{
    int r = 0;
    istringstream sin(s);
    sin >> r;
    return r;
}

string add(string str)
{
    string str,tmp="",tmp1;
    int len=str.size();
    for( int i=0; i<len; i++)
    {
        if( tmp1[i] == '9' ) tmp+='0';
        else
            tmp+=(str[i]-'0')+'1';
    }
    return tmp;
}

int shift(int n)
{
    string tmp="",str,tmp1;
    str=toString(n);
    int l=str.size();
    if( l != m ) for( int i=0; i<(m-l); i++ ) tmp1+='0';
    tmp1+=str;
    tmp+=tmp1[tmp1.size()-1];
    int len=tmp1.size()-1;
    for( int i=0; i<len; i++ )
        tmp+=tmp1[i];
    return toInt(tmp);
}

int main()
{
    while(cin>>m)
    {
        cin>>val;
        int tmp=val;
        int mi=INT_MAX;
        if( m == 1 )
        {
            cout<<0<<endl;
            continue;
        }
        else
        {
            string str;
            str=toString(val);
            int cnt=0;
            for( int i=0; i<str.size(); i++ )
                if( str[i] == str[0] ) cnt++;
            if( cnt == m )
            {
                for( int i=0; i<m; i++ ) cout<<0;
                continue;
            }
        }
        int i=0;
        while(i< 1000 )
        {
            if( mi > val ) mi=val;
            //debug(val);
            int p=add(val);
            int q=shift(val);
            //debug(p);
            //debug(q);
            if( p > q ) val=q;
            else val=p;
            i++;
        }
        string ans=toString(mi);
        int len=ans.size();
        if( len != m ) for( int i=0; i<(m-len); i++ ) cout<<0;
        cout<<mi<<endl;
    }
    return 0;
}
