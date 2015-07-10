#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    map<string,map<string, string>> mymap;

    mymap["a"]["aa"] = "7";
    mymap["a"]["bb"]="19";
    for( auto x: mymap["a"] ) cout<<x.first<<" "<<x.second<<endl;
    string str;
//    while(cin>>str)
//    {
//        cout<<str<<endl;
//    }
    while(getline(cin,str))
    {
        cout<<str<<endl;
    }

//    if (mymap.find(9) != mymap.end() && mymap[9].find(2) != mymap[9].end())
//    {
//        cout << "My map contains a value for [9][2]" << std::endl;
//    }
//    else
//    {
//        cout << "My map does not contain a value for [9][2]" << std::endl;
//    }
//
    return 0;
}
