#include <bits/stdc++.h>

#define debug(x)         cerr<<__LINE__<<" "<<#x<<" "<<x<<endl;
#define IMAX ((unsigned)1<<31)-1
#define eps 1e-11
#define fill(a,v) memset(a,v,sizeof (a))
#define SZ(X) ((int)X.size())
#define VI vector<int>
#define VS vector<string>
#define PB push_back
#define MSI map<string,int>
#define MSLI map<string,LLI>
#define MCI map<char,int>
#define PI acos(-1.0)
#define mk make_pair
#define pLLI pair<LLI,LLI>
#define xx first
#define yy second

#define MOD 1000000007
#define RADIANS(x)       (((1.0 * x * PI) / 180.0))
#define DEGREES(x)       (((x * 180.0) / (1.0 * PI)))

using namespace std;

#define PB push_back

vector <string> token( string str,string deli )
{
    char * cstr, *p,*deli_c;
    deli_c = new char [deli.size()+1];
    cstr = new char [str.size()+1];
    strcpy(deli_c,deli.c_str());
    strcpy (cstr, str.c_str());
    VS vec;
    p=strtok(cstr,deli_c);
    while(p!=NULL)
    {
        vec.push_back( string(p));
        p=strtok(NULL,deli_c);
    }
    delete[] cstr;
    return vec;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n,t=0;
    VS vr,win[19],name;
    string str;
    set<string> se;
    map<string,int> mp;
    map<string,string>pr;
    map<string,string>:: iterator in;
    map<string,int>:: iterator it;
    set<string>:: iterator is;
    while(cin>>n)
    {
        t++;
        //cout<<n<<endl;
        getchar();
        if( n == 0 ) return 0;
        for( int i=0; i<n; i++)
        {
            getline(cin,str);
            vr=token(str," ");
            win[i].PB(str);
            for( int i=1; i<vr.size(); i++ )
            {
                if( mp[vr[i]] == 0 ) mp[vr[i]]=1;
                else if( mp[vr[i]] != 0 ) mp[vr[i]]+=1;
            }
        }
        str.clear();
        string st;
        vr.clear();
        double ans,mx=-213;
        for( int i=0; i<n; i++ )
        {
            for( int j=0; j<win[i].size(); j++) str+=win[i][j];
            vr=token(str," ");
            ans=0;
            for( int j=1; j<vr.size(); j++ )
            {
                ans+=vr[j].size()/mp[vr[j]];
            }
            if( mx <= ans )
            {
                if( pr.find(vr[0]) == pr.end() )
                {
                    pr[vr[0]]=vr[0];
                    name.PB(vr[0]);
                }
                for( int i=0; i<pr.size(); i++ )
                    if
                mx=ans;
            }
            vr.clear();
            str.clear();
        }
        cout<<"Round "<<t<<endl;
        for( int i=0; i<name.size(); i++ ) cout<<name[i]<<" ";
        cout<<endl;
        se.clear();
        for( int i=0; i<n; i++ )
            win[i].clear();
        mp.clear();
        vr.clear();
        name.clear();
    }
    return 0;
}
