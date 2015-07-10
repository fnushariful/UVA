#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

//using namespace std;

int main()
{
    string str = "Just Some Text";

    std::transform(str.begin(), str.end(), str.begin(), std::ptr_fun(tolower));
    std::cout << str << std::endl;

    std::transform(str.begin(), str.end(), str.begin(), std::ptr_fun(toupper));
    std::cout << str << std::endl;
}
