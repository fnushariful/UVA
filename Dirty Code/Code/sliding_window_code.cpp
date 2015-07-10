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

char str[10000];
int last[1000];
int sliding_window( int s)
{
    for( int i=0; i<100; i++ ) last[i]=-1;
    int j=-1,res=0,sum=0,letter=0;
    char ch;
    for( int i=0; i<strlen(str); i++ )
    {
        ch=str[i];
        if( last[ch-'a']<=j )
        {
            letter++;
            last[ch-'a']=i;
        }
        else last[ch-'a']=i;

        if( letter == s+1 )
        {
            letter--;
            j++;
            while(last[str[j]-'a'] != j )
            {
                j++;
            }
        }
        res=max(res,i-j);
        // cout<<i<<" "<<j<<" "<<ch<<" "<<last[ch-'a']<<endl;
    }
    return res;
}


int main()
{
    int s,n;
    while(scanf("%d",&s))
    {
        getchar();
        gets(str);
        //getchar();
        //cout<<str<<endl;
        //printf("%s\n",str);
        int res=sliding_window(s);
        cout<<res<<endl;
    }
    return 0;
}
