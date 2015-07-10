#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    while(cin>>n>>k)
    {
        int x,y,lt,rt;
        double sum=0;
        cin>>lt>>rt;
        for(int i=1; i<n; i++ )
        {
            cin>>x>>y;
            double val=(x-lt)*(x-lt)+(y-rt)*(y-rt);
            val=sqrt(val);
            sum+=val;
            //cout<<sum<<endl;
            lt=x,rt=y;
        }
        sum*=k;
        printf("%0.10lf\n",sum/50);
    }
    return 0;
}
