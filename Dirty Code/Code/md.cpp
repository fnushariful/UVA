#include<stdio.h>
#include <math.h>
#define PI acos(-1)
int main()
{
    int i,T;
    scanf("%d",&T);
    for(i=1; i<=T; i++)
    {
        int r1,r2,h,p;
        double R,v;
        scanf("%d %d %d %d",&r1,&r2,&h,&p);
        R=(double)(r2+(r1-r2)*p/h);
        v=(PI*p*(R*R+r2*r2+R*r2)/3);
        printf("Case %d: %lf\n",i,v);
    }
    return 0;
}
