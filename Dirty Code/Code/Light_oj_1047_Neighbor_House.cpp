#include <bits/stdc++.h>

#define debug(x)         cerr<<__LINE__<<" "<<#x<<" "<<x<<endl;

using namespace std;

#define inf 1<<28
int mat[100][100];
int dp[100][100];
int r,c=3;

void cl()
{
    for( int i=0; i<r; i++ )
        for( int j=0; j<c; j++ )
            dp[i][j]=inf;
}
int call(int i,int j,int sum)
{
    //cout<<"18 "<<i<<" "<<j<<endl;
    if(i>=0 && i<r and j>=0 and j<c) //if still inside the array
    {
//        if(dp[i][j]!=inf) {
//                debug(sum);
//                debug(dp[i][j]);
//                return min(dp[i][j],sum);
//        }
        int ret1=call(i+1,j-1,sum+mat[i][j]);
        int ret2=call(i+1,j-2,sum+mat[i][j]);
        //debug(ret1);
        int ret3=call(i+1,j+1,sum+mat[i][j]);
        //debug(ret2);
        int ret4=call(i+1,j+2,sum+mat[i][j]);
        //debug(ret3);
        int ret=min(ret1,min(ret2,min(ret3,ret4)));
        return dp[i][j]=min(ret,dp[i][j]);
    }
    else return sum;
}

int main()
{
//	READ("in");
    int T;
    scanf("%d",&T);
    for( int t=1; t<=T; t++ )
    {
        scanf("%d",&r);
        for( int i=0; i<r; i++ )
        {
            for(int j=0; j<c; j++ )
                scanf("%d",&mat[i][j]);
        }
        cl();
        int ret=inf;
        call(0,0,0);
        for( int i=0; i<c; i++ )
            ret=min(ret,dp[r-1][i]);
//        for( int i=0; i<r; i++ )
//        {
//            for(int j=0; j<c; j++ )
//                cout<<dp[i][j]<<" ";
//            cout<<endl;
//        }
//        cout<<ret<<endl;
        cl();
        call(0,1,0);
        for( int i=0; i<c; i++ )
            ret=min(ret,dp[r-1][i]);

//        for( int i=0; i<r; i++ )
//        {
//            for(int j=0; j<c; j++ )
//                cout<<dp[i][j]<<" ";
//            cout<<endl;
//        }
//        cout<<ret<<endl;
        cl();

        call(0,2,0);
        for( int i=0; i<c; i++ )
            ret=min(ret,dp[r-1][i]);
//        for( int i=0; i<r; i++ )
//        {
//            for(int j=0; j<c; j++ )
//                cout<<dp[i][j]<<" ";
//            cout<<endl;
//        }
        printf("Case %d: %d\n",t,ret);
        //cout<<ret<<endl;
    }
    return 0;
}

