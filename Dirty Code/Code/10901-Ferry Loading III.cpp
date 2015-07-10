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


int main()
{
    SYN;
    int n,t,m,T;
    cin>>T;
    for( int test=1; test<=T; test++ )
    {
        if( test != 1 ) cout<<endl;
        cin>>n>>t>>m;
        queue<pair<int,int> >car[2];
        string str;
        int val;
        for( int i=0; i<m; i++ )
        {
            cin>>val>>str;
            if( str == "left" ) car[0].push( {i,val});
            else car[1].push( {i,val});
        }
        int time=0;
        int indx=0;
        vector<int>prt(m);
        while( !( car[0].empty() && car[1].empty() ) )
        {
            val=INT_MAX;
            if( !car[0].empty() ) val=car[0].front().second;
            if( !car[1].empty() ) val=min(val,car[1].front().second);
            time=max(time,val);
            //debug(time);
            int cnt=0;
            while( !car[indx].empty() && cnt<n && car[indx].front().second<=time )
            {
                cnt++;
                prt[car[indx].front().first]=time+t;
                car[indx].pop();
            }
            time=time+t;
            //debug(time);
            indx^=1;
            //debug(indx);
        }
        for( int i=0; i<m; i++ ) cout<<prt[i]<<endl;
    }
    return 0;
}

