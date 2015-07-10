#include <cstdio>
#include <string>
#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;
//void print_lcs(int b[100][100],char x[100][100],int m,int n);
int m,n;
char x[100],y[100];

int c[100][100],b[100][100];

void print_lcs(int i,int j)
{
    if(i == 0 || j == 0)
        return;
    if(b[i][j] == 1)
    {
        print_lcs(i-1,j-1);
        printf("%c",x[i-1]);
    }
    else if(b[i][j] == 2)
        print_lcs(i-1,j);
    else
        print_lcs(i,j-1);

}


int main()
{
    while(scanf("%s%s",x,y)==2)
    {
        m=strlen(x);
        n=strlen(y);

        for(int i=0; i<=m; i++)
            c[i][0]=0;
        for(int j=0; j<=n; j++)
            c[0][j]=0;

        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(x[i-1] == y[j-1])
                {
                    c[i][j]=c[i-1][j-1]+1;
                    //b[i][j]=1;
                }

                else
                {
                    c[i][j]=max(c[i][j-1],c[i-1][j]);

                }

                /*else
                {
                    c[i][j]=c[i][j-1];
                    b[i][j]=3;
                }*/

            }
        }
        printf("LCS Length %d\n",c[m][n]);

        //print_lcs(m,n);
        printf("\n");
    }


    return 0;
}

/*
abcbdab
bdcaba
*/

