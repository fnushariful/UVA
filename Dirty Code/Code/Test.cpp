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

#define MOD 1000000007
#define MX 1000009
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
    //freopen("output.txt","w",stdout);
    SYN;
    int T;
    scanf("%d\n",&T);
    //getchar();
    for(int t=1; t<=T; t++ )
    {
        gets(str1);
        //debug(str1);
        string str=str1,st,prt,stp;
        st=str;
        reverse(st.begin(),st.end());
        if( st == str ) cout<<str<<endl;
        else
        {
            st="";
            int mx=INT_MIN;
            for( int i=0; i<str.size(); i++ )
            {
                st+=str[i];
                stp=st;
                reverse(stp.begin(),stp.end());
                stringstream ss;
                ss<<stp;
                ss>>str2;
                //debug(str2);
                //cout<<kmp(str1,str2)<<endl;
                if( kmp(str1,str2)>0 )
                {
                    int len=strlen(str2);
                    //debug(len);
                    if( mx<len )
                    {
                        prt=str2;
                        //debug(prt);
                        mx=strlen(str2);
                        //debug(mx);
                    }
                }
            }
            cout<<prt<<endl;
        }
    }
    return 0;
}


