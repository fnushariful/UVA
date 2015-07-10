#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<pair<int,int> > ar;
    //use
    ar.push_back( {1,2});
    ar.push_back( {4,5});
    //instead of
    ar.push_back(make_pair(1,2));
    ar.push_back(make_pair(3,4));
    //though both compiled successfully
    for(const auto& x : ar)
        cout<<x.first<<' '<<x.second<<'\n';

    auto n=1000;
    n=100000LL;
    cout<<n<<endl;
    return 0;
}
