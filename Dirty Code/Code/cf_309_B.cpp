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
#define VI vector<int>
#define VS vector<string>
#define PB push_back
#define MSI map<string,int>
#define MLLI map<LLI,LLI>



int cnt[30];
int main()
{
    int dif=0;
    string st;
    cin>>st;
    for(int i=0; i<st.length(); i++)
    {
        if(cnt[st[i]-'a']==0)
            dif++;
        cnt[st[i]-'a']++;
    }
    int tdif=26-dif;

    int sum=(st.length()+1)*tdif;
    sum+=(dif-1)*(st.length()+1);
    sum+=1;
    cout<<sum<<endl;

    return 0;
}

