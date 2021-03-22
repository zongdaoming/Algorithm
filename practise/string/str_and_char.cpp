#include <iostream>
#include <string>
#include <cstdio>
#include <numeric>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main()
{
    unordered_map<char, int> ori;
    string str = "ABCDEFGHIJKLMN";
    // for (int i=0; i<str.size(); i++)
    // {
    //     cout<<str[i]<<endl;
    // }
    // cout << "[cout] str is: " << str << endl;
    for(const auto & c: str)
    {
        ori[c]++;
    }
    // Define a iterator
    unordered_map<char,int>::iterator it;
    for(it=ori.begin();it!=ori.end();++it)
    {
        cout<<" Key is "<<it->first<<" Value is "<<it->second<<endl;
    }


    /***
    // string 转换为 char*
    // const char* pszOutput = str.c_str();
    // printf("[printf] str is: %s\n", pszOutput);
    // cout<<str.substr(0,2)<<endl;
    ***/


    system("pause");        
    return 0;
}