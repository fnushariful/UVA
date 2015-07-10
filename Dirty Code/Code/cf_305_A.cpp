#include <bits/stdc++.h>

using namespace std;
#define debug(x)         cerr<<__LINE__<<" "<<#x<<" "<<x<<endl;


int main()
{
    string str;
    int n;
    while(cin>>str)
    {
        //getchar();
        cin>>n;
        int len=str.size();
        if( len < n )
        {
            cout<<"NO"<<endl;
            return 0;
        }
        {
            int val=len/n;
            //debug(val);
            string tmp,ret,pr;
            int j=0,cnt=0,i=0;
            while( i<=len)
            {
                if( j< val )
                {
                    tmp+=str[i];
                    j++;
                }
                else
                {
                    string ret=tmp;
                    reverse(tmp.begin(),tmp.end());
                    if( tmp == ret  )
                    {
                        {
                            cnt++;
                            pr+=ret;
                            debug(pr);
                        }
                    }
                    //debug(tmp);
                    //debug(ret);
                    //debug(cnt);
                    j=0;
                    tmp="";
                    i--;
                }
                i++;
                //debug(i);
            }
            if( str == pr && cnt == n ) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}

