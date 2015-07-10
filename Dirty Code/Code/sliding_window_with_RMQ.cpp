#include <bits/stdc++.h>

using namespace std;
#define MAXN 10009
#define MAXLOGN 10
int M[MAXN][MAXLOGN],B[1000];


void maxSlidingWindow(int A[], int n, int w, int B[])
{
    deque<int> Q;
    for (int i = 0; i < w; i++)
    {
        while (!Q.empty() && A[i] >= A[Q.back()])
            Q.pop_back();
        Q.push_back(i);
    }
    for (int i = w; i < n; i++)
    {
        B[i-w] = A[Q.front()];
        while (!Q.empty() && A[i] >= A[Q.back()])
            Q.pop_back();
        while (!Q.empty() && Q.front() <= i-w)
            Q.pop_front();
        Q.push_back(i);
    }
    B[n-w] = A[Q.front()];
}


void Compute_ST( int A[MAXN], int N)
{
    int i, j;
    for (i = 0; i < N; i++)
        M[i][0] = i;
    for(j = 1; 1 << j <= N; j++)
        for (i = 0; i + (1 << j) - 1 < N; i++)
            if (A[M[i][j - 1]] < A[M[i + (1 << (j - 1))][j - 1]])
                M[i][j] = M[i][j - 1];
            else
                M[i][j] = M[i + (1 << (j - 1))][j - 1];
}

int RMQ(int A[],int s,int e)
{
    int k=e-s;
    k=31-__builtin_clz(k+1); // k = log(e-s+1)
    if(A[M[s][k]]<=A[M[e-(1<<k)+1][k]])
        return A[M[s][k]];
    return A[M[e-(1<<k)+1][k]];
}

int main()
{
    int A[8] = {1,3,-1,-3,5,3,6,7};
    Compute_ST(A,10);
    int s,e,n=5;
    //while(scanf("%d %d",&s,&e))
    {
        for( int i=0; i<=n; i++ )
        {
            s=i;
            e=2+i;
            printf("%d ",RMQ(A,s,e));
        }
        maxSlidingWindow(A,n,3,B);
        for( int i=0; i<n; i++ ) cout<<B[i]<<" ";
    }
    return 0;
}
