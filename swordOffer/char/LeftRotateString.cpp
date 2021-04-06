#include <iostream>
#include <string>
#include <cstdio>
#include <numeric>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
#include <algorithm>
using namespace std;

class Solution
{
    public:
    string LeftRotateString(string str, int n){
        if (n>str.size()) return str;
        string ret = "";
        for (int i = n; i<str.size();i++)
        {
            ret+=str[i];
        }
        for(int i=0; i<n; ++i)
        {
            ret+= str[i];
        }
        return ret;
    }
};