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

bool cmp(pair<string,int>x,pair<string,int>y)
{
    if( x.yy == y.yy ) return x.xx<y.xx;
    return x.yy>y.yy;
}
int main()
{
    string str,temp;
    int T;
    while(cin>>T)
    {
        int cnt[1000];
        fill(cnt,0);
        int k=0;
        while(getchar()!='\n');
        pair<string,int>pr[100];
        for( int t=1; t<=T; t++ )
        {
            getline(cin,temp,'\n');
            transform(temp.begin(), temp.end(), temp.begin(),::toupper);
            str+=temp;
        }
        for( int i=0; i<str.size(); i++ )
        {
            cnt[str[i]-'A']++;
        }
        for( int i=0; i<28; i++ )
        {
            if( cnt[i]!=0 )
                pr[k].xx=i+'A',pr[k].yy=cnt[i],k++;
        }
        sort(pr,pr+k,cmp);
        for( int i=0; i<k; i++) cout<<pr[i].xx<<" "<<pr[i].yy<<endl;
    }
    return 0;
}

