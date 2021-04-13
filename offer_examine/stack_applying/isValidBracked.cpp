#include <iostream>
#include <string>
#include <cstdio>
#include <numeric>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

// 给出一个仅包含字符'(',')','{','}','['和']',的字符串，判断给出的字符串是否是合法的括号序列
// 括号必须以正确的顺序关闭，"()"和"()[]{}"都是合法的括号序列，但"(]"和"([)]"不合法。

class Solution {
public:
    /**
     * 
     * @param s string字符串 
     * @return bool布尔型
     */
    bool isValid(string s) {
        stack<char> st; //开一个栈
        int n = s.size();
        for(int i = 0; i<n; i++)
        {
            if(s[i] == '(')
            {
                st.push(')');
            }
            else if(s[i] == '{')
            {
                st.push('}');
            }
            else if(s[i] == '[')
            {
                st.push(']');
            }
            else if(st.empty())
            {
                return false;
            }
            else if(st.top()!=s[i])
            {
                return false;
            }
            else{
                st.pop();
            }
        }
        return st.empty(); // 用来判断这种情况'['
    }
};