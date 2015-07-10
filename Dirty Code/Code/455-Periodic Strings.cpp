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


int main()
{
    //freopen("output.txt","w",stdout);
    SYN;
    int n,m,k;
    string str,st,fst,snd,pat,txt;
    int T;
    scanf("%d",&T);
    getline(cin,str);
    //getline(cin,str);
    for( int t=1; t<=T; t++ )
    {
        if( t!= 1 ) printf("\n");
        getline(cin,pat);
        failure_fun(pat);
        //debug(pat);
        int len=pat.size();
        int k=len-failure_table[len-1];
        n=failure_table[len-1];
        //debug(n);
        //debug(k);
        if( n+k == len )
        {
            if( k )
                n=len/k;
            else
            {
                printf("%d\n",len);
                fill(failure_table,0);
                continue;
            }
            //debug(n);
            //debug(len);
            if( n*k == len )
                printf("%d\n",k);
            else printf("%d\n",len);
        }
        else
        {
            printf("%d\n",len);
        }
        fill(failure_table,0);
        getline(cin,pat);
    }
    return 0;
}

/*

abcdabd
abcabcdababcdabcdabde

*/


