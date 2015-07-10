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

vector <string> token( string str,string deli )
{
    //cout<<str<<endl;
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
    string st;
    VS v,pr;
    int n;
    while(cin>>n)
    {
        getchar();
        for( int i=0; i<n; i++ )
        {
            getline(cin,st);
            if( st[0] =='p' )
            {
                if( pr.size() == 0 ) cout<<"/"<<endl;
                else
                {
                    cout<<"/";
                    for( int j=0; j<pr.size(); j++ ) cout<<pr[j]<<"/";
                    cout<<endl;
                }
            }
            else if( st[0] == 'c' )
            {
                string str;
                for( int j=3; j<st.size(); j++ ) str+=st[j];
                //cout<<str[0]<<endl;
                if( str[0] =='/' ) pr.clear();
                VS tmp=token(str," /");
                //for( int j=0; j<tmp.size(); j++ ) cout<<tmp[j]<<" ";
                for( int j=0; j<tmp.size(); j++ )
                {
                    if( tmp[j] == ".." ) pr.pop_back();
                    else
                    {
                        str=tmp[j];
                        pr.PB(str);
                    }
                }
            }
        }
        pr.clear();
    }
    return 0;
}
