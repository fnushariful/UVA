#include <iostream>
#include <stdio.h>
#define MAX 5000005
#define MIN -2147483647

using namespace std;
typedef unsigned long long int ll;

typedef long long int LLI;
typedef unsigned long long int ULLI;

int phi[5000001];
ll table[5000001];
LLI phi_function( )
{
    phi[1] = 1;
    table[1]=0;
    for( int i=2; i<=5000001; ++i )
    {
        if(phi[i]==0)
        {
            phi[i]=i-1;
            for( int j=i+i; j<=5000001; j+=i )
            {
                if( phi[j]==0 )
                    phi[j] = j;
                phi[j]= phi[j]/i * (i-1);
            }
        }
    }
    int sum=0;
    for( int i=1; i<=15; i++ )
    {
        cout<<i<<" "<<phi[i]<<" "<<endl;
    }
    return sum;
}

int main()
{
    //phi_function();
    int T,Case=0,n;
    while(cin>>n )
    {
        int a,b;
        phi_function();
    }
    return 0;
}

