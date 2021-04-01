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

// 递归的套路

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param str string字符串 
     * @param pattern string字符串 
     * @return bool布尔型
     */
    bool matchCore(string &str, string &pattern, int i, int j)
    {
        //递归边界设置
        if(i==str.size() && j==pattern.size()) return true;
        if(i!=str.size() && j==pattern.size()) return false;
        
        if (pattern[j+1]=='*')
        {
            if(str[i]==pattern[j] || (pattern[j]=='.' && i!=str.size()))
            {
                return matchCore(str, pattern, i+1, j) || matchCore(str, pattern, i+1, j+2) || matchCore(str,pattern, i, j+2);
            }
            else return matchCore(str, pattern, i, j+2);
        }
        
        if(str[i]==pattern[j] || (pattern[j]=='.' && i!=str.size()))
        {
            return matchCore(str, pattern, i+1, j+1);
        }
        return false;
    }
    bool match(string str, string pattern) {
        // write code here
        //递归
        return matchCore(str, pattern,0,0);
    }
};