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
#define st string

#define MOD 1000000007
#define MX 1000000
#define RADIANS(x)       (((1.0 * x * PI) / 180.0))
#define DEGREES(x)       (((x * 180.0) / (1.0 * PI)))

#define sz 500
int pos[sz][sz],N;
int candi[sz];
queue<int>fer;
queue<int>com[sz];

void stableMarriage()
{
    fill(candi,-1);
    for(int i=1; i<=N; i++)
        fer.push(i);

    while (!fer.empty())
    {
        int man = fer.front();
        int wcom = com[man].front();
        com[man].pop();

        if (candi[wcom] == -1)
        {
            candi[wcom] = man;
            fer.pop();
        }
        else
        {
            int hcandi = candi[wcom];
            if (pos[wcom][man]<pos[wcom][hcandi])
            {
                candi[wcom] = man;
                fer.pop();
                fer.push(hcandi);
            }
        }
    }
}

int main()
{
    int tmp,T;
    scanf("%d",&T);
    for( int t=1; t<=T; t++ )
    {
        scanf("%d",&N);
        for(int r=1; r<=N; r++)
        {
            for(int c=1; c<=N; c++)
            {
                scanf("%d",&tmp);
                com[r].push(tmp);
            }
        }
        for(int r=N+1; r<=2*N; r++)
        {
            for(int c=1; c<=N; c++)
            {
                scanf("%d",&tmp);
                pos[r][tmp]=c;
            }
        }
        stableMarriage();
        printf("Case %d:",t++);
        for(int i=N+1; i<=N*2; i++)
        {
            printf(" (%d %d)",candi[i],i);
        }
        printf("\n");
        for( int i=0; i<=N; i++ )
            while(!com[i].empty())
                com[i].pop();

    }
    return 0;
}
