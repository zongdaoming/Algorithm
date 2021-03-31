#include <iostream>
#include <string>
#include <cstdio>
#include <numeric>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
    public:
    int rob(vector<int> &nums)
    {
        if(nums.empty())
        {
            return 0;
        }
        int size= nums.size();
        if(size==1)
        {
            return nums[0];
        }
        vector<int> dp(size,0);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<size;i++)
        {
            dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[size-1];
    }
};


// 滚动数组技巧

class Solution {
    public:
    int rob(vector<int> &nums)
    {
        if(nums.empty())
        {
            return 0;
        }
        int size= nums.size();
        if(size==1)
        {
            return nums[0];
        }
        vector<int> dp(size,0);
        int first = nums[0], second = max(nums[0],nums[1]);
        for(int i=2;i<size;i++)
        {
            int temp =second;
            // second denotes next
            second = max(first+nums[i], second);
            first = temp;
        }
        return second;
    }
};

