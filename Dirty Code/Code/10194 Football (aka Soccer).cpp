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

struct my
{
    string team;
    int pnt,win,gs,ga,gamp,tie,los,dif;
} table[100000];

bool cmp(my x,my y)
{
    if( x.pnt == y.pnt )
    {
        if( x.win == y.win )
        {
            if( x.dif == y.dif )
            {
                if( x.gs == y.gs )
                {
                    if( x.gamp == y.gamp )
                    {
                        transform(x.team.begin(),x.team.end(),x.team.begin(),::tolower );
                        transform(y.team.begin(),y.team.end(),y.team.begin(), ::tolower);
                        return x.team<y.team;
                    }
                    return x.gamp<y.gamp;
                }
                return x.gs>y.gs;
            }
            return x.dif>y.dif;
        }
        return x.win>y.win;
    }
    return x.pnt>y.pnt;
}

int main()
{
    //freopen("output.txt","w",stdout);
    int T;
    scanf("%d",&T);
    getchar();
    for( int t=1; t<=T; t++ )
    {
        if( t!=1 ) cout<<"\n";
        string name;
        getline(cin,name);
        int teamnum;
        scanf("%d",&teamnum);
        getchar();
        vector<string>teamname;
        map<string,int>mp;
        int k=0;
        for( int i=0; i<teamnum; i++ )
        {
            string tmp;
            getline(cin,tmp);
            if( mp.find(tmp) == mp.end() )
            {
                mp[tmp]=k;
                k++;
                table[mp[tmp]].team=tmp;
            }
            teamname.PB(tmp);
        }
        int G;
        scanf("%d",&G);
        getchar();
        //fill(table,0);
        for( int k=0; k<G; k++ )
        {
            string str;
            getline(cin,str);
            string tmp,tmp1;
            int i=0;
            while(str[i]!= '#' )
            {
                tmp+=str[i];
                i++;
            }
            //cout<<tmp<<endl;
            i+=1;
            int num=0;
            while(str[i]!='@')
            {
                num=num*10+(str[i]-'0');
                i++;
            }
            table[mp[tmp]].gs+=num;
            i+=1;
            //cout<<num<<endl;
            int num1=0;
            while(str[i]!='#')
            {
                num1=num1*10+(str[i]-'0');
                i++;
            }
            //cout<<num<<endl;
            i+=1;
            while(i<str.size()) tmp1+=str[i],i++;
            table[mp[tmp1]].gs+=num1;

            //cout<<tmp<<" "<<table[mp[tmp]].gs<<" "<<tmp1<<" "<<table[mp[tmp1]].gs<<endl;
            if( num1 > num )
            {
                table[mp[tmp1]].pnt+=3;
                table[mp[tmp1]].win+=1;
                table[mp[tmp]].los+=1;
                table[mp[tmp]].ga+=num1;
                table[mp[tmp1]].ga+=num;
                table[mp[tmp]].gamp+=1;
                table[mp[tmp1]].gamp+=1;
            }
            else if( num1 < num )
            {
                table[mp[tmp]].pnt+=3;
                table[mp[tmp]].win+=1;
                table[mp[tmp1]].los+=1;
                table[mp[tmp]].ga+=num1;
                table[mp[tmp1]].ga+=num;
                table[mp[tmp]].gamp+=1;
                table[mp[tmp1]].gamp+=1;
            }
            else if( num == num1 )
            {
                table[mp[tmp1]].pnt+=1;
                table[mp[tmp]].pnt+=1;
                table[mp[tmp]].tie+=1;
                table[mp[tmp1]].tie+=1;
                table[mp[tmp]].ga+=num1;
                table[mp[tmp1]].ga+=num;
                table[mp[tmp]].gamp+=1;
                table[mp[tmp1]].gamp+=1;
            }
        }
        //getchar();
        for( int i=0; i<k; i++ )
        {
            table[i].dif=table[i].gs-table[i].ga;
        }
        sort(table,table+k,cmp);
        cout<<name<<endl;
        for( int i=0; i<k; i++ )
            cout<<i+1<<") "<<table[i].team<<" "<<table[i].pnt<<"p, "<<table[i].gamp<<"g ("<<table[i].win<<"-"<<table[i].tie<<"-"<<table[i].los<<"), "<<table[i].dif<<"gd ("<<table[i].gs<<"-"<<table[i].ga<<")"<<endl;
        for( int i=0; i<k; i++ )
        {
            table[i].team="";
            table[i].pnt=table[i].gamp=table[i].win=table[i].tie=table[i].los=table[i].dif=table[i].gs=table[i].ga=0;
        }
    }
    return 0;
}

