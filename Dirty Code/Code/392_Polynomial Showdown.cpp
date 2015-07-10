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
    //freopen("output.txt","w",stdout);
    int ar[1000];
    while(scanf("%d%d%d%d%d%d%d%d%d",&ar[0],&ar[1],&ar[2],&ar[3],&ar[4],&ar[5],&ar[6],&ar[7],&ar[8]) == 9)
    {
        string str="",st;
        int p=8,val;
        for( int i=0; i<9; i++ )
        {
            if( ar[i] < 0 ) val=ar[i]*(-1);
            else val=ar[i];
            //cout<<ar[i]<<" "<<endl;
            stringstream ss;
            ss<<val;
            ss>>st;
            ss.clear();
            if( ar[i] == 0 )
            {
                p--;
                continue;
            }
            else if( p == 1  || p == 0 )
            {
                if( p == 1 )
                {
                    //debug(str);
                    for( int i=7; i<8; i++ )
                    {
                        if( ar[i] < 0 ) val=ar[i]*(-1);
                        else val=ar[i];
                        //cout<<ar[i]<<" "<<endl;
                        stringstream ss;
                        ss<<val;
                        ss>>st;
                        ss.clear();

                        if( ar[i] == 1 && str.size()!= 0 ) str+=" + ",str+="x";
                        else if( ar[i] == 1 && str.size() == 0) str+="x";
                        else if( ar[i] == -1 && str.size() == 0 ) str+="-",str+="x";
                        else if( ar[i] == -1 && str.size() != 0 ) str+=" - ",str+="x";
                        else if( ar[i]<0 && str.size() == 0 ) str+="-",str+=st,str+="x";
                        else if( ar[i]<0 && str.size()!=0 ) str+=" - ",str+=st,str+="x";
                        else if( ar[i]> 1 && str.size()!= 0 ) str+=" + ",str+=st,str+="x";
                        else if( ar[i]>1 && str.size() == 0 ) str+=st,str+="x";
                        //debug(str);
                    }
                    i++;
                    {
                        if( ar[i] < 0 ) val=ar[i]*(-1);
                        else val=ar[i];
                        stringstream ss;
                        ss<<val;
                        ss>>st;
                        ss.clear();
                        if( ar[i] <0 && str.size() == 0 ) str+="-",str+=st;
                        else if( ar[i]<0 && str.size() != 0 ) str+=" - ",str+=st;
                        else if( ar[i]>0 && str.size() == 0 ) str+=st;
                        else if( ar[i]>0 && str.size() != 0 ) str+=" + ",str+=st;
                        break;
                    }
                }
                else if( p == 0 )
                {
                    if( ar[i] < 0 ) val=ar[i]*(-1);
                    else val=ar[i];
                    stringstream ss;
                    ss<<val;
                    ss>>st;
                    ss.clear();
                    if( ar[i] <0 && str.size() == 0 ) str+="-",str+=st;
                    else if( ar[i]<0 && str.size() != 0 ) str+=" - ",str+=st;
                    else if( ar[i]>0 && str.size() == 0 ) str+=st;
                    else if( ar[i]>0 && str.size() != 0 ) str+=" + ",str+=st;
                    break;
                }
            }
            else if( ar[i] == 1 && str.size()!= 0 ) str+=" +",str+=" x^",str+=(p+'0');
            else if( ar[i] == 1 && str.size() == 0) str+="x^",str+=(p+'0');
            else if( ar[i] == -1 && str.size() == 0 ) str+="-",str+="x^",str+=(p+'0');
            else if( ar[i] == -1 && str.size() != 0 ) str+=" - ",str+="x^",str+=(p+'0');
            else if( ar[i]<0 && str.size()!=0 ) str+=" - ",str+=st,str+=("x^"),str+=(p+'0');
            else if( ar[i]<0 && str.size() == 0 ) str+="-",str+=st,str+=("x^"),str+=(p+'0');
            else if( ar[i]> 1 && str.size()!= 0 ) str+=" + ",str+=st,str+=("x^"),str+=(p+'0');
            else if( ar[i]>1 && str.size() == 0 ) str+=st,str+=("x^"),str+=(p+'0');//+(p+'0');
            p--;
        }
        if( str.size() == 0 ) cout<<0<<endl;
        else
            cout<<str<<endl;
    }
    return 0;
}

