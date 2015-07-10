#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <queue>
#include <set>
#include <cmath>
using namespace std;
const double eps = 1e-8;
const double pi=acos(-1.0);
const int INF=0x7fffffff;
unsigned long long uINF = ~0LL;
#define MAXN 1007
typedef long long LL;
LL phi[1000009];
void phi_table()
{
    for(LL i=2; i<=1000009; i++) phi[i]=0;
    phi[1]=1;
    for(LL i=2; i<=1000009; i++) if(!phi[i])
            for(LL j=i; j<=1000009; j+=i)
            {
                if(!phi[j]) phi[j]=j;
                phi[j]=phi[j]/i*(i-1);
            }
}
LL pow_mod(LL a,LL p,LL n)
{
    if(p==0)return 1;
    LL ans=pow_mod(a,p/2,n);
    ans=ans*ans%n;
    if(p%2==1)ans=ans*a%n;
    return ans;
}
LL n,m,a[11];
//a^x≡a^(x%phi(c)+phi(c))(mod c)
LL dfs(LL d,LL mod)
{
    if(d==n-1)return a[n-1]%mod;
    LL temp=dfs(d+1,phi[mod]);
    LL ans=pow_mod(a[d],temp+phi[mod],mod);
    return ans;
}
int main()
{
    LL T=1;
    //freopen("0.in","r",stdin);
    phi_table();
    LL s;
    while(cin>>s>>m)
    {
        //if(s=="#")return false;
        n=3;
        a[0]=2,a[1]=2,a[2]=s;
        printf("%d\n",dfs(0,m));
    }

    return 0;
}
