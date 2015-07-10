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
#define st string
#define MSI map<string,int>
#define MSLI map<string,LLI>
#define MCI map<char,int>
#define PI acos(-1.0)
#define mk make_pair
#define pLLI pair<LLI,LLI>
#define pss pair<st,st>
#define xx first
#define yy second

#define MOD 1000000007
#define MX 1000000
#define RADIANS(x)       (((1.0 * x * PI) / 180.0))
#define DEGREES(x)       (((x * 180.0) / (1.0 * PI)))

int main()
{
    map<string,string> mp;
    mp["brasil"]="Feliz Natal!";
    mp["alemanha"]="Frohliche Weihnachten!";
    mp.insert(pss("austria","Frohe Weihnacht!"));
    mp.insert(pss("coreia","Chuk Sung Tan!"));
    //mp.insert(pss(""));
    mp.insert(pss("espanha","Feliz Navidad!"));
    mp.insert(pss("grecia","Kala Christougena!"));
    mp.insert(pss("estados-unidos","Merry Christmas!"));
    mp.insert(pss("inglaterra","Merry Christmas!"));
    mp.insert(pss("australia","Merry Christmas!"));
    mp.insert(pss("portugal","Feliz Natal!"));
    mp.insert(pss("suecia","God Jul!"));
    mp.insert(pss("turquia","Mutlu Noeller"));
    mp.insert(pss("argentina","Feliz Navidad!"));
    mp.insert(pss("chile","Feliz Navidad!"));
    mp.insert(pss("mexico","Feliz Navidad!"));
    mp.insert(pss("antardida","Merry Christmas!"));
    mp.insert(pss("canada","Merry Christmas!"));
    mp.insert(pss("irlanda","Nollaig Shona Dhuit!"));
    mp.insert(pss("belgica","Zalig Kerstfeest!"));
    mp.insert(pss("italia","Buon Natale!"));
    mp.insert(pss("libia","Buon Natale!"));
    mp.insert(pss("siria","Milad Mubarak!"));
    mp.insert(pss("marrocos","Milad Mubarak!"));
    mp.insert(pss("japao","Merii Kurisumasu!"));
    map<string,string> :: iterator it;
    string str;
    while(cin>>str)
    {
        bool ok=false;
        for( it=mp.begin(); it!=mp.end(); it++ )
        {
            if( (*it).first == str )
            {
                cout<<(*it).second<<endl;
                ok=true;
                break;
            }
        }
        if( !ok ) cout<<"--- NOT FOUND ---"<<endl;
    }
    return 0;
}
