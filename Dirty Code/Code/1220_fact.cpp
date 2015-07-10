#include <bits/stdc++.h>

#define LLI long long
using namespace std;

#define mx 2147483690
LLI pr[100000];
bool ar[100000];
void prime()
{
    LLI sqrtn=(LLI)sqrt(mx);
    for( int i=3; i<sqrt(sqrtn); i+=2 )
    {
        if( ar[i] == 0 )
            for( int j=i*i; j<sqrtn; j+=2*i )
                ar[j]=1;
    }
    pr[0]=2;
    LLI k=1;
    for(int i=3; i<sqrtn; i+=2 )
        if( ar[i] == 0 )
            pr[k++]=i;
    //cout<<pr[k-1]<<endl;
}

LLI fact(LLI n )
{
    bool fl=0;
    LLI m,cnt=0;
    for( int i=0; pr[i]*pr[i]<=n; i++ )
    {
        if( n%pr[i] == 0 )
        {
            if( fl == 0 )
            {
                m=pr[i];
                fl=1;
                cout<<m<<endl;
            }
            while(n%pr[i] == 0 )
            {
                n/=pr[i];
                cnt++;
            }
            if( pr[i] != m ) return 1;
            cout<<cnt<<" "<<m<<endl;
        }
    }
    return cnt;
}
int main()
{
    prime();
    int n;
    while( cin>>n)
    {
        //for( int i=0; i<n; i++ ) cout<<pr[i]<<" ";
        if( n < 0 )
            cout<<fact(n*(-1))<<endl;
        else
            cout<<fact(n)<<endl;
    }

    return 0;
}
