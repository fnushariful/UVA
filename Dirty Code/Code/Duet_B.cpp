#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n,p;
    while(cin>>n)
    {
        int sum=0;
        vector<int>v;
        for( int i=0; i<n; i++ )
        {
            cin>>p;
            v.push_back(p);
            if( v[i] > 4 )
            {
                sum+=v[i]/4;
                v[i]=v[i]-((v[i]/4)*4);
                //cout<<v[i]<<endl;
            }
        }
        sort(v.begin(),v.end());
        for( int i=v.size()-1; i>=0; i-- )
        {
            int chk=v[i],p;
            if( chk <= 4 )
                for( int j=i-1; j>=0; j-- )
                {
                    if( (v[j]+chk)%4 == 0 or v[j]+chk < 4 )
                    {
                        p=chk+v[j];
                        v.erase(v.begin()+i);
                        v.erase(v.begin()+j);
                        v.push_back(p);
                        break;
                    }
                }
        }

//        for( int i=0; i<v.size(); i++ ) cout<<v[i]<<" ";
//        cout<<endl;
        for( int i=v.size()-1; i>=0; i-- )
        {
            int chk=v[i],p;
            if( chk <= 4 )
                for( int j=i-1; j>=0; j-- )
                {
                    if( (v[j]+chk)%4 == 0 or v[j]+chk < 4 )
                    {
                        p=chk+v[j];
                        v.erase(v.begin()+i);
                        v.erase(v.begin()+j);
                        v.push_back(p);
                        break;
                    }
                }
        }

//        for( int i=0; i<v.size(); i++ ) cout<<v[i]<<" ";
        for( int i=0; i<v.size(); i++ ) if( v[i]>=4 ) sum+=v[i]/4;
            else sum+=1;
        v.clear();
        cout<<sum<<endl;
    }
    return 0;
}
