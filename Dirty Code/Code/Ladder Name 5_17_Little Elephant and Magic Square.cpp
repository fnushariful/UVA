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

int n,m,ar[4][4];
int chk()
{
    int ek=ar[0][0]+ar[0][1]+ar[0][2];
    int dui=ar[1][0]+ar[1][1]+ar[1][2];
    int tin=ar[2][0]+ar[2][1]+ar[2][2];
    int fst=ar[0][0]+ar[1][0]+ar[2][0];
    int snd=ar[0][1]+ar[1][1]+ar[2][1];
    int thd=ar[0][2]+ar[1][2]+ar[2][2];
    int dia=ar[0][0]+ar[1][1]+ar[2][2];
    int sid=ar[0][2]+ar[1][1]+ar[2][0];
    //debug(ek);
    //debug(dia);
    if( ek == dui && ek== tin && ek == fst && ek == snd && ek == thd && ek==dia && ek==sid ) return 1;
    return 0;
}

int main()
{
    pair<int,int> str[100];
    int mx=INT_MIN,mi=INT_MAX,mid;
    for( int i=0; i<3; i++ )
    {
        int sum=0;
        for( int j=0; j<3; j++ )
            cin>>ar[i][j],sum+=ar[i][j];
        str[i].xx=sum;
        str[i].yy=i;
    }
    sort(str,str+3);
    for(int i=0; i<100005; i++)
    {
        int val=i;
        if( str[2].yy == 2 ) ar[2][2]=val;
        else if( str[2].yy == 1 ) ar[1][1]=val;
        else if( str[2].yy == 0 ) ar[0][0]=val;
        val=(str[2].xx-str[1].xx)+i;
        if( str[1].yy == 2 ) ar[2][2]=val;
        else if( str[1].yy == 1 ) ar[1][1]=val;
        else if( str[1].yy == 0 ) ar[0][0]=val;
        val=(str[2].xx-str[0].xx)+i;
        if( str[0].yy == 2 ) ar[2][2]=val;
        else if( str[0].yy == 1 ) ar[1][1]=val;
        else if( str[0].yy == 0 ) ar[0][0]=val;

        if( chk() )
        {
            //cout<<"ok"<<endl;
            break;
        }
    }
    for( int i=0; i<3; i++ )
    {
        for( int j=0; j<3; j++ )
        {
            cout<<ar[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

