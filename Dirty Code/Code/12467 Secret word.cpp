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
#define MX 1000009
#define RADIANS(x)       (((1.0 * x * PI) / 180.0))
#define DEGREES(x)       (((x * 180.0) / (1.0 * PI)))

int failure[MX];

void failure_fun(string pat)
{
    int k=1,len=0,len_p=pat.size();
    failure[0]=0;
    while(k<len_p)
    {
        if( pat[k] == pat[len] ) failure[k++]=++len;
        else
        {
            if( len ) len=failure[len-1];
            else failure[k++]=0;
        }
    }
    // cout<<"ok"<<endl;
}

int kmp(string text,string pat)
{
    int i=0,j=0,len=0,len_p=text.size(),mx=INT_MIN;
    while(i<len_p)
    {
        if( text[i] == pat[j] )
        {
            i++;
            j++;
            if( j>mx )
            {
                mx=j;
                //debug(mx);
            }
        }
        else
        {
            if( j ) j=failure[j-1];
            else i++;
        }
    }
    return mx;
}

int main()
{
    //freopen("output.txt","w",stdout);
    SYN;
    int T;
    string str,txt,pat;
    cin>>T;
    for( int t=1; t<=T; t++ )
    {
        cin>>str;
        pat=str;
        reverse(str.begin(),str.end());
        txt=str;
        failure_fun(pat);
        //for( int i=0; i<pat.size(); i++ ) cout<<failure[i]<<" ";
        //cout<<endl;
        int ret=kmp(txt,pat);
        //debug(ret);
        for( int i=ret-1; i>=0; i--)
            cout<<pat[i];
        cout<<endl;
    }
}
