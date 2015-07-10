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
#define MX 1000
#define RADIANS(x)       (((1.0 * x * PI) / 180.0))
#define DEGREES(x)       (((x * 180.0) / (1.0 * PI)))

int pi[MX+10];
char str1[MX+10],str2[MX+10];

void pi_table(char p[])
{
    int pl=strlen(p);
    pi[0]=-1;
    int indx=-1;
    for(int i=1; i<pl; i++)
    {
        while(indx>-1 && p[indx+1]!=p[i]) indx=pi[indx];
        if(p[indx+1]==p[i]) indx++;
        pi[i]=indx;
    }
}

int kmp(char t[],char p[])
{
    int tl=strlen(t);
    int pl=strlen(p);
    int cnt=0;
    pi_table(p);
    int indx=-1;
    for( int i=0; i<tl; i++)
    {
        while(indx>-1 && p[indx+1]!=t[i])
        {
            indx=pi[indx];
        }
        if(p[indx+1]==t[i]) indx++;
        if(indx==pl-1) cnt++;

    }
    return cnt;
}
int main()
{
    while(gets(str1))
    {
        gets(str2);
        cout<<str1<<" "<<str2<<endl;
        cout<<kmp(str1,str2)<<endl;;
    }
    return 0;
}

