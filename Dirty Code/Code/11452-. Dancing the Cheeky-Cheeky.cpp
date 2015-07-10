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

int failure_table[MX];

void failure_fun(string pat)
{
    int k=1,len=0,len_p=pat.size();
    while(k<len_p)
    {
        if( pat[k] == pat[len] ) failure_table[k++]=++len;
        else
        {
            if( len ) len=failure_table[len-1];
            else failure_table[k++]=0;
        }
    }
    //debug(len);
    //len+=1;
    int i=0;
    string str;
    while(i<8)
    {
        pat+=pat[len];
        str+=pat[len];
        len++;
        i++;
    }
    cout<<str<<"..."<<endl;
}


int main()
{
    freopen("output.txt","w",stdout);
    SYN;
    int n,m,k,T;
    string pat;
    scanf("%d",&T);
    for( int t=1; t<=T; t++ )
    {
        cin>>pat;
        //string str,st,fst,snd;
        failure_fun(pat);
    }
    return 0;
}

