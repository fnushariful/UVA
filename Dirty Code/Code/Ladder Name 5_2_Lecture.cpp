
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
    int n,m;
    while(cin>>n>>m)
    {
        string str1,str2,str;
        map<string,string>mp;
        for( int i=0; i<m; i++ )
        {
            cin>>str1>>str2;
            if( str1.size()<str2.size() )
                mp[str1]=str1,mp[str2]=str1;
            else if( str1.size()>str2.size() )
                mp[str1]=str2,mp[str2]=str2;
            else if( str1.size() == str2.size() ) mp[str1]=mp[str2]=str1;
        }
        getchar();
        getline(cin,str);
        //cout<<str<<endl;
        vector<string> v;
        v=token(str," ");
        //for( map<string,string>::iterator it=mp.begin(); it!=mp.end(); ++it ) cout<<it->xx<<" "<<it->yy<<endl;
        for(int i=0; i<v.size(); i++)
        {
            //cout<<v[i]<<endl;
            cout<<mp[v[i]]<<" ";
        }
    }
    return 0;
}
