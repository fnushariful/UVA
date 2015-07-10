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
#define pLLI pair<string,LLI>
#define xx first
#define yy second
#define st string

#define MOD 1000000007
#define MX 1000000
#define RADIANS(x)       (((1.0 * x * PI) / 180.0))
#define DEGREES(x)       (((x * 180.0) / (1.0 * PI)))

ULLI p,de,ln,con,from,to,i,temp;
string input;
ULLI store[1000];
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
            output+=(temp+'0');
        }
        reverse(output.begin(),output.end());
    }
    return output;
}

int main()
{
    LLI b,v;
    pLLI pr[209];
    pair<string,string>prt[209];
    VS ve;
    while(cin>>b>>v)
    {
        pLLI pr[209];
        pair<string,string>prt[209];
        VS ve;
        string str;
        int val,sum=0;
        for( int i=0; i<v; i++ ) cin>>pr[i].xx>>pr[i].yy,sum+=pr[i].yy,prt[i].xx=pr[i].xx;
        for( int i=0; i<sum; i++ )
        {
            cin>>str;
            ve.PB(str);
        }
        str.clear();
        sum=0;
        for( int i=0; i<v; i++ )
        {
            val=pr[i].yy;
            for( int j=sum,k=0; k<val; j++,k++ ) str+=ve[j];
            //cout<<str<<endl;
            prt[i].yy=convert(str,2,10);
            //cout<<prt[i].yy<<endl;
            sum+=pr[i].yy;
            str.clear();
        }
        LLI q;
        cin>>q;
        bool ok=0;
        for( int i=0; i<q; i++ )
        {
            cin>>str;
            for( int j=0; j<v; j++ )
                if( prt[j].xx == str )
                {
                    cout<<prt[j].xx<<"="<<prt[j].yy<<endl;
                    ok=1;
                    break;
                }
            if( !ok )
                cout<<str<<"="<<endl;
                ok=0;
        }
    }
    return 0;
}

