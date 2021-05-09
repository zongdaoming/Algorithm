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
        int m = s.size();
        int n = p.size();

        auto matches = [&](int i, int j) {
            if (i == 0) {
                return false;
            }
            if (p[j - 1] == '.') {
                return true;
            }
            return s[i - 1] == p[j - 1];
        };

        vector<vector<int>> f(m + 1, vector<int>(n + 1));
        f[0][0] = true;
        for (int i = 0; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    f[i][j] |= f[i][j - 2];
                    if (matches(i, j - 1)) {
                        f[i][j] |= f[i - 1][j];
                    }
                }
                else {
                    if (matches(i, j)) {
                        f[i][j] |= f[i - 1][j - 1];
                    }
                }
            }
        }
        return f[m][n];
    }
};

class Solution {
public:
    bool matches(int i, int j, string &s, string &p){
        if (i == 0) {
            return false;
        }
        if (p[j - 1] == '.') {
            return true;
        }
        return s[i - 1] == p[j - 1];
    };
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        // auto matches = [&](int i, int j) {
        //     if (i == 0) {
        //         return false;
        //     }
        //     if (p[j - 1] == '.') {
        //         return true;
        //     }
        //     return s[i - 1] == p[j - 1];
        // };
        vector<vector<int>> f(m + 1, vector<int>(n + 1));
        f[0][0] = true;
        for (int i = 0; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    f[i][j] =(f[i][j] | f[i][j - 2]);
                    if (matches(i, j - 1,s,p)) {
                        f[i][j] = (f[i][j] | f[i - 1][j]);
                    }
                }
                else {
                    if (matches(i, j,s,p)) {
                        f[i][j] = (f[i][j] | f[i - 1][j - 1]);
                    }
                }
            }
        }
        return f[m][n];
    }
};