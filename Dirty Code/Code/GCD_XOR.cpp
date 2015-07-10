#include<bits/stdc++.h>

using namespace std;

#define maxn 30000010
int cnt[maxn]= {0};
int gcd(int a,int b)
{
    int t;
    while(b)
    {
        t=b;
        b=a%b;
        a=t;
    }
    return a;
}
void init()
{
    for(int i=1; i<maxn; ++i)
    {
        for(int j=i+i; j<maxn; j+=i)
        {
            if((j^(j-i))==i)++cnt[j];
        }
        cnt[i]+=cnt[i-1];
    }
}

int main()
{
    init();
    int T,n;
    scanf("%d",&T);
    for(int t=1; t<=T; ++t)
    {
        scanf("%d",&n);
        printf("Case %d: %d\n",t,cnt[n]);
    }
    return 0;
}
