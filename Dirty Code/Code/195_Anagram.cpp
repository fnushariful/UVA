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

bool cmp(char a,char b)
{
    int val=tolower(a)-tolower(b);
    return val?val<0:a<b;
}
int main()
{
    int T;
    char str[1000];
    scanf("%d",&T);
    getchar();
    for(int t=1; t<=T; t++)
    {
        scanf("%s",str);
        int len=strlen(str);
        int ar[1000];
        sort(str,str+len,cmp);
        do
        {
            cout<<str<<endl;
        }
        while(next_permutation(str,str+len,cmp));
    }
    return 0;
}
