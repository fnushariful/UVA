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
#define VI vector<LLI>
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

vector<string>v,tmp,temp,stor;

void fun()
{
    v.PB("4"),v.PB("7");
    temp=v;
    stor=v;
    //for(int i=0; i<temp.size(); i++ ) cout<<temp[i]<<" ";
    string chk="";
    while( chk.size()!= 9 )
    {
        for( int i=0; i<2; i++ )
        {
            string str;
            for( int j=0; j<temp.size(); j++ )
            {
                str+=temp[j];
                str+=v[i];
                reverse(str.begin(),str.end());
                stor.PB(str);
                tmp.PB(str);
                str.clear();
            }
        }
        temp.clear();
        temp=tmp;
        chk=tmp[0];
        tmp.clear();
    }
    //sort(stor.begin(),stor.end());
}

int main()
{
    fun();
    LLI n;
    VI ma;
    LLI val;
    for( int i=0; i<stor.size(); i++ )
    {
        stringstream ss;
        ss<<stor[i];
        ss>>val;
        ma.PB(val);
    }
    sort(ma.begin(),ma.end());
    while(cin>>n)
    {
        for(int i=0; i<ma.size(); i++ )
        {
            val=ma[i];
            if( val == n )
            {
                cout<<i+1<<endl;
                break;
            }
        }
    }
    return 0;
}
