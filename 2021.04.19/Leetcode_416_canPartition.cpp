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

class Solution{
    public:
    bool canPartition(vector<int> &nums){
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2) return false;
        int target = sum/2, n = nums.size();
        vector<vector<bool>> dp(n+1, vector<bool>(target+1, false));
        // initialize dp vector
        for(int i = 0; i<=n; ++i){
            dp[i][0]  = true;
        }
        for(int i = 1; i<=n; ++i)
        {
            for(int j = nums[i-1]; j<=target; ++j)
            {
                if(j>=nums[i-1]){
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
                }else
                {
                    dp[i][j] = dp[i-1][j];
                }
            } 
        }
        return dp[n][target];
    }
};

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return false;
        }
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int maxNum = *max_element(nums.begin(), nums.end());
        if (sum & 1) {
            return false;
        }
        int target = sum / 2;
        if (maxNum > target) {
            return false;
        }

        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }
        dp[0][nums[0]] = true;
        for (int i = 1; i < n; i++) {
            int num = nums[i];
            for (int j = 1; j <= target; j++) {
                if (j >= num) {
                    dp[i][j] = dp[i - 1][j] | dp[i - 1][j - num];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n - 1][target];
    }
};
