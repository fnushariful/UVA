/* Supto
   Dept. Of CSE
   University Of Dhaka
*/
//#include<bits/stdc++.h>
#include <cstdio>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <iostream>
#include <fstream>
#include <numeric>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <iterator>

#define pb push_back
#define ins insert
#define ff first
#define ss second
#define ll long long int
#define sss stringstream
#define oss ostringstream
#define iss istringstream
#define llu long long unsigned

#define _sq(a) (a)*(a)
#define gcd(a,b)    __gcd(a,b)
#define lcm(a,b) ((a)*((b)/gcd(a,b)))
#define mem(a) memset(a, 0, sizeof(a))
#define _set(a) memset(a,-1,sizeof(a))
#define popcount(n) __builtin_popcount(n)
#define popcountl(n) __builtin_popcountll(n)
#define ctz(x) __builtin_ctz(x) //number of trailing zeroes in a digit
#define ctzl(x) __builtin_ctzll(x)
#define clz(x) __builtin_clz(n)
#define clzl(x) __builtin_clzll(x) //number of leading zeroes in a digit
//If Long Long (mask & (1LL << k))
#define check(mask, k) (mask & (1 << k))
#define set1(mask, k) (mask | (1 << k))
#define set0(mask ,k) (mask & (~(1<<k)))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

using namespace std;
#define pi acos(-1.0)
#define inf 1000000000
#define EPS 1e-9
#define MAX 30005
#define MAXL 15
//const ll mod = 1000003;
//int dx[] = {0,0,1,-1};
//int dy[] = {1,-1,0,0};
//int dx[] = {-1,-1,-1,0,0,1,1,1};
//int dy[] = {-1,0,1,-1,1,-1,0,1};
struct data
{
    int s, f, p;
} ar[105];
bool cmp(data a, data b)
{
    if(a.s < b.s) return true;
    return false;
}
int v;
ll dp[105][105];

ll solve(int prv, int pos)
{
    if(pos == v+1 || prv == v+1) return 0;
    if(dp[prv][pos] != -1) return dp[prv][pos];
    ll ret = 0;
    for(int i = pos + 1; i <= v; i++)
    {
        if(ar[i].s > ar[prv].f) ret = max(ret, solve(pos, i) + ar[i].p);
        else if(ar[i].s > ar[pos].f) ret=max(ret, solve(prv, i) + ar[i].p);
    }
    return dp[prv][pos] = ret;
}
int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    //ios_base::sync_with_stdio(false);
    int n, i, p, s, d;
    while(scanf("%d %d", &n, &v))
    {
        if(!n && !v) break;
        for( i = 1; i <= v; i++ )
        {
            scanf("%d %d %d", &p, &s, &d);
            ar[i].s = s;
            ar[i].f = s + d - 1;
            ar[i].p = p;
        }
        sort(ar + 1, ar + v + 1, cmp);
        for(i = 1; i <= v; i++) printf("%d %d\n", ar[i].s, ar[i].f);
        _set(dp);

        printf("%lld\n", solve(0, 0));

//        for( int i=0; i<v; i++ )
//        {
//            for( int j=0; j<v; j++ )
//                cout<<dp[i][j]<<" ";
//            cout<<endl;
//        }
    }
    return 0;
}
