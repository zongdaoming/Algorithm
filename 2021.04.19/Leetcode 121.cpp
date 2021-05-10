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
    int maxProfit(vector<int>& prices) {
        // exception
        // 我们可以遍历一遍数组，在每一个位置 i 时，记录 i 位置之前所有价格中的最低价格
        int n = prices.size();
        if(n==1){
            return 0;
        }
        vector<int> dp(n);
        dp[0] = prices[0];
        int profits = INT_MIN;
        // dp[1] = min(dp[0],prices[0]);
        for(int i = 1; i<n; i++)
        {
            dp[i]  = min(dp[i-1], prices[i]);
            profits = max(profits, prices[i]-dp[i]);
        }
        return profits;
    }
};

