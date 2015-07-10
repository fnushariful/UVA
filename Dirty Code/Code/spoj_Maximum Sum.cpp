#include <bits/stdc++.h>

using namespace std;

#define SYN ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long int LLI;
typedef unsigned long long int ULLI;

#define debug(x)         cerr<<__LINE__<<" "<<#x<<" "<<x<<endl;
#define IMAX ((unsigned)1<<31)-1
#define eps 1e-11
#define fill(a,v) memset(a,v,sizeof (a))
#define SZ(X) ((int)X.size())
#define VI vector<LLI>
#define VS vector<string>
#define PB push_back
#define MSI map<string,int>
#define MLLI map<LLI,LLI>
#define MCI map<char,int>
#define PI acos(-1.0)
#define mk make_pair
#define pLLI pair<LLI,LLI>
#define xx first
#define yy second

#define MOD 1000000007
#define MX 1000000
#define RADIANS(x)       (((1.0 * x * PI) / 180.0))
#define DEGREES(x)       (((x * 180.0) / (1.0 * PI)))

struct tree
{
    LLI mx,ps;
};

tree seg[4*MX];

void insrt(LLI index,LLI st,LLI ed,LLI num,LLI pos)
{
    if(st==ed)
    {
        seg[index].mx=num;
        seg[index].ps=pos;
        return ;
    }

    LLI mid=(st+ed)/2;

    if(pos<=mid) insrt(2*index,st,mid,num,pos);
    else insrt((2*index)+1,mid+1,ed,num,pos);
    //LLI pr[4];
    //pr[0]=seg[index*2].mx,pr[1]=seg[index*2].mi,pr[2]=seg[(index*2)+1].mx,pr[3]=seg[(index*2)+1].mi;
    //sort(pr,pr+4);
    //seg[index].mx=pr[3];
//    for( int i=3; i>=0; i-- ) if( seg[index].mx>pr[i])
//        {
//            seg[index].mi=pr[i];
//            break;
//        }
    int n=2*index;
    if( seg[n].mx > seg[n+1].mx )
    {
        seg[index].mx=seg[n].mx;
        seg[index].ps=seg[n].ps;
    }
    else
    {
        seg[index].mx=seg[n+1].mx;
        seg[index].ps=seg[n+1].ps;
    }
}


tree query(LLI index,LLI st,LLI ed,LLI from,LLI to)
{
    if(st==from && to==ed) return seg[index];

    LLI mid=(st+ed)/2;
    if(to<=mid) return query(index*2,st,mid,from,to);
    else if(from>mid) return query((index*2)+1,mid+1,ed,from,to);
    else
    {
        tree x=query(index*2,st,mid,from,mid);
        tree y=query((index*2)+1,mid+1,ed,mid+1,to);
        if( x.mx > y.mx ) return x;
        else return y;
        //        LLI pr[4];
//        pr[0]=x.mx,pr[1]=x.mi,pr[2]=y.mx,pr[3]=y.mi;
//        sort(pr,pr+4);
//        x.mx=pr[3];
//        for( int i=3; i>=0; i-- ) if( x.mx>pr[i])
//            {
//                x.mi=pr[i];
//                break;
//            }
        //return x;
    }
}

int main()
{
    SYN;
    LLI n,m,k;
    string st;
    cin>>n;
    {
        for( int i=0; i<=n; i++ ) seg[i].mx=INT_MIN;
        for( int i=1; i<=n; i++ )
        {
            cin>>m;
            insrt(1,1,n,m,i);
        }
        LLI q,x,y;
        cin>>q;
        for( int i=0; i<q; i++ )
        {
            cin>>st;
            if( st == "Q" )
            {
                cin>>x>>y;
                tree p=query(1,1,n,x,y);
                insrt(1,1,n,0,p.ps);
                tree k=query(1,1,n,x,y);
                cout<<p.mx+k.mx<<endl;
                insrt(1,1,n,k.mx,k.ps);
                insrt(1,1,n,p.mx,p.ps);
            }
            else if( st == "U" )
            {
                cin>>x>>y;
                insrt(1,1,n,y,x);
            }
        }
    }
    return 0;
}

