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
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+2);
        dp[0] = 0;
        for(int i = 0; i<amount+1; i++)
        {
            for(int &c: coins)
            {
                if(i>=c)
                {
                    dp[i] = min(dp[i], dp[i-c]+1);
                }
            }
        }
        return dp[amount]==amount+2?-1:dp[amount];
    }
};