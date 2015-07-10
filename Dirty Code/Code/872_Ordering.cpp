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

vector<char>result;
char arr[100];
vector<int>mat[100];
int k,taken[100]= {0};


bool chk( int p)
{
    for( int j=0; j<mat[p].size(); j++ )
    {
        char v=mat[p][j]+'A';
        //debug(v);
        bool ok=0;
        for( int k=0; k<result.size(); k++ )
        {
            if( result[k] == v ) ok=1;
        }
        if(!ok) return 0;
    }
    return 1;
}
int flag;
void call()
{
    if( result.size() == k )
    {
        flag=0;
        //cout<<flag<<endl;
        printf("%c",result[0]);
        for( int i=1; i<k; i++ )
            printf(" %c",result[i]);
        printf("\n");
        return;
    }
    for( int i=0; i<k; i++ )
    {
        // cout<<i<<endl;
        int p=arr[i]-'A';
        p=chk(p);
        //if(  )
        if( taken[i] == 0  && p)
        {

            taken[i]=1;
            result.PB(arr[i]);
            call();
            taken[i]=0;
            result.pop_back();
        }
    }
    //cout<<endl;
}

int main()
{
    //freopen("output.txt","w",stdout);
    string str;
    int t=0,T;
    scanf("%d",&T);
    getchar();
    getchar();
    for( int t=1; t<=T; t++ )
    {
        if( t>1 ) getchar();
        getline(cin,str);
        k=0;
        for( int i=0; i<str.size(); i++ ) if(isalpha(str[i]))
                arr[k++]=str[i];
        sort(arr,arr+k);
        getline(cin,str);
        for( int i=0; i<str.size(); i++ ) if( isalpha(str[i]) )
            {
                mat[str[i+2]-'A'].PB(str[i]-'A');
                i+=2;
            }
        //cout<<flag<<endl;
        call();
        if( flag ) cout<<"NO"<<endl;
        flag=1;
        if( T!=1 && t!=T) cout<<endl;
        for( int i=0; i<30; i++ )
            mat[i].clear();
        fill(taken,0);
        result.clear();
        fill(arr,'\0');
    }
    return 0;
}

/*
4

A B F G
A<B B<F

A B C
A<B B<C C<A

A B F G
A<B B<F

A B C
A<B B<C C<A
*/
