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


// dp[i]其实表示的是，以A[i]结尾的等差数列个数： 
// 考虑A=[3,4,5,6,7,8,9], 
// 当前已经计算出dp[2]=1, 
// dp[3]=2,需要求dp[4]。
// dp[4]=dp[3]+1 的原因是： 
// 以A[3]=6结尾的等差数列已经有了dp[3]=2个：
// [3,4,5,6]和[4,5,6]。
// 想要知道以A[4]=7结尾的等差数列个数，
// 那么需要在已经有的dp[3]个等差数列的尾部接上一个A[4]=7, 
// 还有一个新等差数列[5,6,7]，
// 每次都会产生这个长度为3的等差数列。 
// 所以才有了dp[i-1]+1。

class Solution {
    public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,0);
        if(n<3)
        {
            return 0;
        }
        for(int i=2;i<n;i++)
        {
            if(nums[i]-nums[i-1]==nums[i+1]-nums[i])
            {
                dp[i] = dp[i-1]+1;
            }
        }
        return  accumulate(dp.begin(), dp.end(),0);

    }

};




int main(int argc, char const *argv[])
{
    
    return 0;
}
