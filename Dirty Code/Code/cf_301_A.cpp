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

int main()
{
    int n;
    string str1,str2;
    while(cin>>n>>str1>>str2)
    {
        int sum=0;
        for( int i=0; i<str1.size(); i++ )
        {
            int p=str1[i]-'0';
            int q=str2[i]-'0';
            int x=abs(p-q);
            int y=abs(p-0)+abs(0-q);
            int z=abs(p-9)+1+abs(0-q);
            int a=abs(p-0)+1+abs(9-q);
            sum+=min(x,min(y,min(z,a)));
            //cout<<x<<" "<<y<<" "<<z<<endl;
        }
        cout<<sum<<endl;
    }
    return 0;
}

