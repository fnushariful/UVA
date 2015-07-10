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
int fstl[100],fstu[100],sndl[100],sndu[100];

int main()
{
    string str,st;
    while(cin>>str>>st)
    {
        for( int i=0; i<str.size(); i++ )
        {
            if( islower(str[i])) fstl[str[i]-'a']++;
            else if( isupper(str[i])) fstu[str[i]-'A']++;
        }
        for( int i=0; i<st.size(); i++ )
        {
            if( islower(st[i])) sndl[st[i]-'a']++;
            else if( isupper(st[i])) sndu[st[i]-'A']++;
        }
        int ya=0,wp=0;


        for( int i=0; i<26; i++ )
        {
            if( fstl[i]>= sndl[i] && sndl[i] != 0) ya+=fstl[i]-sndl[i],fstl[i]=fstl[i]-sndl[i],sndl[i]=0;
            else if( fstl[i]<=sndl[i] && fstl[i] != 0 ) ya+=sndl[i]-fstl[i],sndl[i]=sndl[i]-fstl[i],fstl[i]=0;
        }

        for( int i=0; i<26; i++ ) cout<<fstl[i]<<" ";
        cout<<endl;
        for( int i=0; i<26; i++ ) cout<<fstu[i]<<" ";
        cout<<endl;
        for( int i=0; i<26; i++ ) cout<<sndl[i]<<" ";
        cout<<endl;
        for( int i=0; i<26; i++ ) cout<<sndu[i]<<" ";
        cout<<endl;


        for( int i=0; i<26; i++ )
        {
            if( fstu[i]>= sndu[i] &&  sndu[i] != 0 ) ya+=fstu[i]-sndu[i],fstu[i]=fstu[i]-sndu[i],sndu[i]=0;
            else if( fstu[i]<=sndu[i] && fstu[i] != 0) ya+=sndu[i]-fstl[i],sndu[i]=sndu[i]-fstl[i],fstu[i]=0;
        }

        for( int i=0; i<26; i++ )
        {
            if( fstl[i]>= sndu[i] && sndu[i] != 0) wp+=fstl[i],fstl[i]=fstl[i]-sndu[i],sndu[i]=0;
            else if( fstl[i]<=sndu[i] && fstl[i] != 0 ) wp+=sndu[i]-fstl[i],sndu[i]=sndu[i]-fstl[i],fstl[i]=0;
        }

        for( int i=0; i<26; i++ )
        {
            if( fstu[i]>= sndl[i] && sndl[i] != 0) wp+=fstu[i]-sndl[i],fstu[i]=0;
            else if( fstu[i]<=sndl[i] && fstu[i] != 0 ) wp+=sndl[i]-fstu[i],sndl[i]=sndl[i]-fstu[i],fstu[i]=0;
        }
        cout<<ya<<" "<<wp<<endl;

    }
    return 0;
}

