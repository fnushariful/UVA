#include <bits/stdc++.h>

using namespace std;

int chk_ar[28];
int chk(string st)
{
    int ar[28];
    for( int i=0; i<st.size(); i++ )
        ar[st[i]-'a']+=1;
    for( int i=0; i<26; i++ )
        if( chk_ar[i] == ar[i] ) continue;
        else return false;
    return true;
}

int main()
{
    string st,str;
    while(cin>>st>>str)
    {
        int len=str.size(),cnt=0;
        memset(chk_ar,0,sizeof(chk_ar));
        for( int i=0; i<len; i++ ) chk_ar[str[i]-'a']+=1;
        for( int i=0; i<len; i++ ) cout<<chk_ar[i]<<" ";
        for( int i=0; i<st.size(); i++ )
        {
            string tmp=st.substr(i,len);
            cout<<tmp<<endl;
            if(chk(tmp) == 1 ) cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
