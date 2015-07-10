#include <bits/stdc++.h>

using namespace std;

struct Sort
{
    string str;
    Sort()
    {

    }
    Sort(string a)
    {
        str=a;
    }
public:
    bool operator< (const Sort &_A) const
    {
        if( _A < str ) return true;
        else return false;
    }
};


int main()
{
    vector<Sort> months;
    months.push_back("abc");//,"abc","ayb"};
}
for( int i=0; i<months.size(); i++ ) cout<<months[i].str<<endl;

//string str="A";
//EnumMap::iterator it;
//    months["1"] = "January";
//    months["7"] = "July";
//    months["2"] = "February";
//    months["3"] = "March";
//    months["4"] = "April";
//    months["5"] = "May";
//    months["6"] = "June";
//    months["8"] = "August";
//    months["9"] = "September";
//    months["10"] = "October";
//    months["11"] = "November";
//    months["12"] = "December";
//
}
