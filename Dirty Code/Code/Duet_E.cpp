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

#define MOD 1000000007
#define RADIANS(x)       (((1.0 * x * PI) / 180.0))
#define DEGREES(x)       (((x * 180.0) / (1.0 * PI)))

int main()
{
    int n;
    string st;
    while(cin>>n)
    {
        cin>>st;
        int len=st.size();
        len/=2;
        string chk=st.substr(len,len);
        string str=st.substr(0,len);
        int cnt,cnt1,cnt2,cnt3;
        cnt=cnt1=cnt2=cnt3=0;
        for( int i=0; i<len; i++ )
            if(  str[i]-'0' >= chk[i]-'0' )
                cnt++;
            else break;
        for( int i=0; i<len; i++ )
            if( str[i]-'0' <= chk[i]-'0' ) cnt1++;
            else break;
        for( int i=0,l=len-1; i<len; i++,l-- )
        {
            //cout<<str[i]<<" "<<chk[l]<<endl;
            if( str[i]-'0' >= chk[l]-'0' )
            {
                cnt2++;
                //cout<<str[i]<<" "<<chk[l]<<endl;
            }
            else break;
        }
        for( int i=0,l=len-1; i<len; i++,l-- )
            if( str[i]-'0' <= chk[l]-'0' ) cnt3++;
            else break;
        // cout<<cnt<<" "<<cnt1<<" "<<cnt2<<" "<<cnt3<<endl;
        if( cnt == len or cnt1 == len or cnt2 == len or cnt3 == len )
            cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
    return 0;
}
