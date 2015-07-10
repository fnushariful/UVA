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

map<string,LLI> mp;

void fun()
{
    LLI in=1;
    for( int i=0; i<26; i++ )
    {
        char a=i+'a';
        string str;
        str+=a;
        if( mp.find(str) == mp.end() )
            mp[str]=in++;
    }
    string str;
    for( int i=0; i<26; i++ )
    {
        char a=i+'a';
        for( int j=i+1; j<26; j++ )
        {
            char b=j+'a';
            str+=a;
            str+=b;
            //cout<<str<<endl;
            if( mp.find(str) == mp.end() )
                mp[str]=in++;
            str="";
        }
    }
    str="";
    for( int i=0; i<26; i++ )
    {
        char a=i+'a';
        for( int j=i+1; j<26; j++ )
        {
            char b=j+'a';
            for( int k=j+1; k<26; k++ )
            {
                char c=k+'a';
                str+=a;
                str+=b;
                str+=c;
                if( mp.find(str) == mp.end() )
                    mp[str]=in++;
                str="";
            }
        }
    }
    str="";
    for( int i=0; i<26; i++ )
    {
        char a=i+'a';
        for( int j=i+1; j<26; j++ )
        {
            char b=j+'a';
            for(int k=j+1; k<26; k++ )
            {
                char c=k+'a';
                for( int l=k+1; l<26; l++ )
                {
                    char d=l+'a';
                    str+=a;
                    str+=b;
                    str+=c;
                    str+=d;
                    if( mp.find(str) == mp.end() )
                        mp[str]=in++;
                    str="";
                }
            }
        }
    }
    str="";
    for( int i=0; i<26; i++ )
    {
        char a=i+'a';
        for( int j=i+1; j<26; j++ )
        {
            char b=j+'a';
            for( int k=j+1; k<26; k++ )
            {
                char c=k+'a';
                for( int l=k+1; l<26; l++ )
                {
                    char d=l+'a';
                    for( int p=l+1; p<26; p++ )
                    {
                        char e=p+'a';
                        str+=a;
                        str+=b;
                        str+=c;
                        str+=d;
                        str+=e;
                        if( mp.find(str) == mp.end() )
                            mp[str]=in++;
                        str="";
                    }
                }
            }
        }
    }
//    for( map<string,LLI>:: iterator it=mp.begin(); it!=mp.end(); ++it )
//        cout<<it->xx<<" "<<it->yy<<endl;
}

int main()
{
    fun();
    string str;
    while(cin>>str)
    {
        if( mp.find(str) != mp.end() )
            cout<<mp[str]<<endl;
        else cout<<0<<endl;
    }
}

