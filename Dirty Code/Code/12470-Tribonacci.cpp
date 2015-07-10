
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


long long mod;

class Matrix
{
public:

    int row, col;
    long long valu[5][5];


    void clear()
    {
        memset(valu,0,sizeof(valu));
        row=0;
        col=0;
    }



    void identify(int x)
    {
        clear();
        row=x;
        col=x;


        for(int i=0; i<row; i++)
            valu[i][i]=1;
    }



    Matrix operator * (Matrix b)
    {
        int i,j,k;
        Matrix c;

        c.clear();
        c.row=row;
        c.col=b.col;
        // Complexity d^3.
        // Matrix
        //        cout<<"ok"<<endl;
//        for( int i=0; i<row; i++ )
//        {
//            for( int j=0; j<col; j++ )
//                cout<<valu[i][j]<<" ";
//            cout<<endl;
//        }
        for(i=0; i<row; i++)
            for(j=0; j<b.col; j++)
                for(k=0; k<col; k++)
                {
                    c.valu[i][j] = c.valu[i][j] + (valu[i][k])*(b.valu[k][j]);
                    c.valu[i][j] %= mod;
                }
        return c;
    }



    Matrix operator ^ (long long p)
    {
        Matrix res, x;
        res.identify(row);

        x=*(this);

        while(p)
        {
            if(p & 1) res = res * x;
            x=x*x;
            p>>=1;
        }
        return res;

    }

};

Matrix a, b;

void setMatrixValues()

{
    a.row=3;
    b.row=3;
    a.col=1;
    b.col=3;

    b.valu[0][0]=1;
    b.valu[0][1]=1;
    b.valu[0][2]=1;

    b.valu[1][0]=1;
    b.valu[1][1]=0;
    b.valu[1][2]=0;

    b.valu[2][0]=0;
    b.valu[2][1]=1;
    b.valu[2][2]=0;

    a.valu[0][0]=2;
    a.valu[1][0]=1;
    a.valu[2][0]=0;
}



int main()

{

    Matrix x,y;
    //cout<<"ok"<<endl;
    setMatrixValues();

    mod=1000000009;
    long long val;
    while(scanf("%lld",&val) && val )
    {
        if( val == 1 ) printf("0\n");
        else if( val == 2 ) printf("1\n");
        else if( val == 3 ) printf("2\n");
        else
        {
            y = b^(val-3);
            x= y * a;
            printf("%lld\n",x.valu[0][0]);
        }
    }
    return 0;
}
