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


long long p,de,ln,con,from,to,i,temp;
string input;
long long store[1000];
string output;
string convert( string input,int from ,int to )
{
    output.clear();
    ln=input.size();
    store[0]=1;
    for(i=1; i<ln; i++)
    {
        store[i]=store[i-1]*from;
    }
    de=0;
    p=ln-1;
    for(i=0; i<ln; i++)
    {
        if(input[i]>'9')
            con=input[i]-'A'+10;
        else con=input[i]-'0';
        de+=con*store[p];
        p--;
    }
    if(de==0)
        output+='0';
    else
    {
        i=0;
        while(de>0)
        {
            temp=de%to;
            de/=to;
            if(temp>9)
                temp+=55;
            if( temp > 9 ) output+=temp;
            else output+=temp+'0';
        }
        reverse(output.begin(),output.end());
    }
    return output;
}

int main()
{
    LLI n,m;
    //freopen("output.txt","w",stdout);
    string str;
    while(cin>>n>>m>>str)
    {
        bool ok=0;
        for( int i=0; i<str.size(); i++ )
        {
            if( isalpha(str[i]))
            {
                int val=str[i]-'A';
                val+=10;
                if( val >= n )
                {
                    cout<<str<<" is an illegal base "<<n<<" number"<<endl;
                    ok=1;
                    break;
                }
            }
            else
            {
                int val=str[i]-'0';
                if( val >= n )
                {
                    cout<<str<<" is an illegal base "<<n<<" number"<<endl;
                    ok=1;
                    break;
                }
            }
        }
        if(!ok)
        {
            string st=convert(str,n,m);
            //cout<<st<<endl;
            cout<<str<<" base "<<n<<" = "<<st<<" base "<<m<<endl;
        }
    }
    return 0;
}

