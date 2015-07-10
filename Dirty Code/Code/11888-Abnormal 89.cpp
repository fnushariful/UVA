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

int failure_table[1000009];

void failure_fun(string pattern)
{
    int k=1,len_p,len=0;
    len_p=pattern.size();
    while(k<len_p)
    {
        if( pattern[k] == pattern[len] ) failure_table[k++]=++len;
        else
        {
            if (len) len=failure_table[len-1];
            else failure_table[k++]=0;
        }
    }
}

bool KMP( string text,string pattern )
{
    int i=0,j=0,len=pattern.size(),len_p=text.size();
    while(j<len_p)
    {
        if( text[j] == pattern[i] )
        {
            i++;
            j++;
            if( i == len )
            {
                int ret=j-len;
                //cout<<"Pattern found at "<<ret<<endl;
                return 1;
                i=failure_table[i-1];
            }
        }
        else
        {
            if(i) i=failure_table[i-1];
            else j++;
        }
    }
    return false;
}

int main()
{
    int n,m,k;
    string str,st,fst,snd,pat,txt;
    while(cin>>pat)
    {
        failure_fun(pat);
        txt+=pat+pat;
        str=pat;
        reverse(str.begin(),str.end());
        bool ok=KMP(txt,str);
        if( ok )
            cout<<"alindrome"<<endl;
        else if( str == pat )
            cout<<"palindrome"<<endl;
        else cout<<"simple"<<endl;
    }
    return 0;
}

/*

abcdabd
abcabcdababcdabcdabde

*/
