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
#define MX 1000000
#define RADIANS(x)       (((1.0 * x * PI) / 180.0))
#define DEGREES(x)       (((x * 180.0) / (1.0 * PI)))



pair<string,string> token(string str)
{
    pair<string,string>pr;
    string st;
    st+='"';
    int i=1;
    for(i=1; i<str.size(); i++ )
    {
        if( str[i] == '"' ) break;
        else st+=str[i];
    }
    pr.xx=st+'"';
    st="";
    for( i=i+5; i<str.size(); i++ )
    {
        st+=str[i];
    }
    pr.yy=st;
    return pr;
}

bool chk(pair<string,string> a,pair<string,string> b )
{
    if( a.yy == b.yy )
    {
        transform(a.xx.begin(),a.xx.end(),a.xx.begin(),::tolower);
        transform(b.xx.begin(),b.xx.end(),b.xx.begin(),::tolower);

        return a.xx<b.xx;
    }
    return a.yy<b.yy;
}

bool chp(pair<string,int>a, pair<string,int> b )
{
    return a.yy<<b.yy;
}

int main()
{
    //freopen("output.txt","w",stdout);
    string str;
    pair<string,string> pr[1000],pt;
    int i=0;
    while(getline(cin,str))
    {
        if( str == "END" ) break;
        pair<string,string> pt=token(str);
        pr[i].xx=pt.xx;
        pr[i].yy=pt.yy;
        i++;
        //cout<<pt.xx<<" "<<pt.yy<<endl;
    }
    sort(pr,pr+i,chk);
    map<string,int> pos;
    map<int,bool> mp;
    for( int t=0; t<i; t++ )
    {
        if( pos.find(pr[t].xx) == pos.end() )
            pos[pr[t].xx]=t;
        mp[t]=0;
    }
    //for( auto& x:pos) cout<<x.xx<<" "<<x.yy<<endl;
    string st;
    vector<pair<int,string> >v;
    while(getline(cin,str))
    {
        if( str == "END" ) break;
        if( str == "SHELVE" )
        {
            sort(v.begin(),v.end());
            //for(int t=0; t<v.size(); t++ ) cout<<v[t].xx<<" "<<v[t].yy<<endl;
            for( int t=0; t<v.size(); t++ )
            {
                int after=v[t].xx-1;
                bool ok=0;
                while(after >= 0 )
                {
                    if( mp[after] == false )
                    {
                        ok=1;
                        break;
                    }
                    after--;
                }
                if( ok )
                    cout<<"Put "<<v[t].yy<<" after "<<pr[after].xx<<endl;
                else
                {
                    cout<<"Put "<<v[t].yy<<" first"<<endl;
                }
                mp[v[t].xx]=0;
            }
            cout<<"END"<<endl;
            v.clear();
        }
        if( str[0] == 'R' )
        {
            st="";
            for( int t=7; t<str.size(); t++ ) st+=str[t];
            //debug(st);
            int val=pos[st];
            //cout<<st<<endl;
            v.push_back( {val,st});
        }
        else if( str[0] == 'B' )
        {
            st="";
            for( int t=7; t<str.size(); t++ ) st+=str[t];
            //cout<<st<<endl;
            int val=pos[st];
            mp[val]=1;
        }
    }
    return 0;
}

