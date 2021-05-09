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


// 其中 dp[i][j] 表示 以i 戒止的字符串是否可以被j截止的怎则表达式匹配
// 其中 dp[i][j] 表示以 i 截止的字符串是否可以被以 j 截止的 正则表达式匹配。
class Solution {
public:
bool isMatch(string s, string p) { 
    int m = s.size(), n = p.size(); 
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false)); 
    dp[0][0] = true; 
    for (int i = 1; i < n + 1; ++i) 
    { 
        if (p[i-1] == '*') { 
        dp[0][i] = dp[0][i-2];
        } 
    }
    for (int i = 1; i < m + 1; ++i) 
    { 
        for (int j = 1; j < n + 1; ++j) { 
        if (p[j-1] == '.') { 
            dp[i][j] = dp[i-1][j-1];
        } 
        else if (p[j-1] != '*') { 
            dp[i][j] = dp[i-1][j-1] && p[j-1] == s[i-1];
            } 
        else if (p[j-2] != s[i-1] && p[j-2] != '.') 
        { 
            dp[i][j] = dp[i][j-2];
        } 
        else 
        { 
            dp[i][j] = dp[i][j-1] || dp[i-1][j] || dp[i][j-2];     
        } 
        } 
    } 
    return dp[m][n]; 
}
};

