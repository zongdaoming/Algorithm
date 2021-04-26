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

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(const string &str: strs){
            // auto [count0, count1] = countChar(str);
            auto ft = countChar(str);
            auto count0 = ft.first;
            auto count1 = ft.second;
            for(int i= m; i>=count0; --i)
            {
                for(int j = n; j>=count1; --j)
                {
                    dp[i][j] = max(dp[i][j], 1 + dp[i-count0][j-count1]);
                }
            }
        }
        return dp[m][n];
    }
    pair<int, int> countChar(const string & s)
    {
        int count0 = s.length();
        int count1 = 0;
        for(const char &c: s)
        {
            if(c=='1'){
                ++count1;
                --count0;
            }
        }
        return pair<int, int>(count0,count1);
        // return make_pair(count0, count1);
    }
};