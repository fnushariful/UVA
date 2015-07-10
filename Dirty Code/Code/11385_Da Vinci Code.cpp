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

pair<int,char>prt[1009];
map<int,string>::iterator it;
int main()
{
    LLI fibo[100];
    fibo[1]=1,fibo[2]=2;
    map<LLI,LLI>mp;
    mp.insert(mk(fibo[1],1));
    mp.insert(mk(fibo[2],2));
    for( int i=3; i<50; i++ )
    {
        fibo[i]=fibo[i-1]+fibo[i-2];
        mp.insert(mk(fibo[i],i));
    }
    int n,T;
    LLI num[1000];
    scanf("%d",&T);
    for( int t=1; t<=T; t++ )
    {
        cin>>n;
        string str;
        LLI mx=INT_MIN;
        for( int i=0; i<n; i++ ) cin>>num[i],mx=max(mx,num[i]);
        getchar();
        getline(cin,str);
        string st;
        for(int i=0; i<str.size(); i++ ) if( str[i]>='A' && str[i]<='Z' ) st+=str[i];
        for( int i=0; i<n; i++ )
        {
            prt[i].xx=num[i];
            prt[i].yy=st[i];
        }
        char ch[1000];
        fill(ch,' ');
        for( int i=0; i<n; i++ )
        {
            ch[mp[prt[i].xx]]=prt[i].yy;
        }
        ch[mp[mx]+1]='\0';
        for( int i=1; i<strlen(ch); i++ ) cout<<ch[i];
        cout<<endl;
    }
    return 0;
}

