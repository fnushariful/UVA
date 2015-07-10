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
#define VI vector<LLI>
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

#define MOD 1000000007
#define MX 1000000
#define RADIANS(x)       (((1.0 * x * PI) / 180.0))
#define DEGREES(x)       (((x * 180.0) / (1.0 * PI)))

template<typename T> void prLLIarray(T a[],LLI n)
{
    for(LLI i=0; i<n-1; i++) cout<<a[i]<<" ";
    cout<<a[n-1]<<endl;
}
int main()
{
    int A,B,C,D;
    while(cin>>A>>B>>C>>D)
    {
        double ret,prt;
        if (A*B ==B* D)
        {
            cout<<"Impossible."<<endl;
            return 0;
        }

        ret= A*A + B*B -C*C - D*D;
        ret /= 2*(A*B - C*D);
        prt = sqrtl(A * A + B * B - 2 * A * B * ret) * 1000;

        printf("Distance is %.0lf km.\n",prt);
    }
    return 0;
}

