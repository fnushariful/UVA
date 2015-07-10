#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,T;
    scanf("%d",&T);
    for( int t=1; t<=T; t++ )
    {
        double ax,ay,bx,by,cx,cy,dx,dy,x,y;
        scanf("%lf%lf%lf%lf%lf%lf",&ax,&ay,&bx,&by,&cx,&cy);
        x=(ax+cx)/2;
        y=(ay+cy)/2;
        dx=(2*x-bx);
        dy=(2*y-by);
        double lf=((ax*by)+(bx*cy)+(cx*dy)+(dx*ay));
        double rt=((bx*ay)+(cx*by)+(dx*cy)+(ax*dy));
        double area=0.5*(lf-rt);
        if( area < 0 ) area*=(-1);
        printf("Case %d: %0.lf %0.lf %0.lf\n",t,dx,dy,area);
    }
    return 0;
}
