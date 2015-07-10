#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("output.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for( int t=1; t<=T; t++ )
    {
        int n,ar[509][509],chk[509][509];
        scanf("%d",&n);
        int cnt=0,p,q;
        for( int i=0; i<n; i++ )
            for( int j=0; j<n; j++ )
            {
                cin>>ar[i][j];
                if( ar[i][j] == 0 )
                    p=i,q=j;
            }

        int k=0,m=0;
        for( int i=0; i<n; i++ )
        {
            for( int j=0; j<n; j++ )
                chk[i][j]=k++;
        }
        for( int i=0; i<n*n; i++ )
        {
            int fl=0;
            for( int i=0; i<n; i++ )
            {
                for( int j=0; j<n; j++)
                    if( chk[p][q] == ar[i][j] )
                    {
                        swap(ar[p][q],ar[i][j]);
                        p=i,q=j;
                        cnt++;
                        fl=1;
                        break;
                    }
                if( fl == 1 ) break;
            }
            int flag=0;
            if( ar[0][0]== 0)
            {
                m=0;
                for( int i=0; i<n; i++ )
                {
                    for( int j=0; j<n; j++ )
                        if( chk[i][j] != ar[i][j] )
                        {
                            swap(ar[0][0],ar[i][j]);
                            cnt++;
                            flag=1,p=i,q=j;
                            break;
                        }
                        else m++;
                    if( flag == 1 ) break;
                }
            }
            if( m == n*n ) break;
        }
        printf("Case %d: %d\n",t,cnt);
    }
    return 0;
}
