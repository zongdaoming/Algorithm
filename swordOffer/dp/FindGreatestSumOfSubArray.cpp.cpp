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
    int FindGreatestSumOfSubArray(vector<int> array) {
        int sz = array.size();
        vector<int> dp(sz+1, 1);
        // dp[i]表示以i结尾的连续数组的最大和。所以最终的要求是dp[n-1]。
        //  状态转移方程：dp[i] = max(array[i], dp[i-1]+array[i])
        // 要保证array都被访问到

        dp[0] = 0; //表示没有元素
        int res = array[0];
        for(int i=0; i<sz; ++i)
        {
            dp[i] = max(array[i], dp[i-1]+array[i]);
            res = max(res, dp[i]);
        }
        return res;
    }
};

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int sz = array.size();
        vector<int> dp(sz+1, 1);
        dp[0] = 0; // 表示没有元素
        int ret = array[0];
        for (int i=1; i<=sz; ++i) {
            dp[i] = max(array[i-1], dp[i-1]+array[i-1]);
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};

// 方法二：空间复杂度O(1)解法
// 思想很简单，就是对下标为i的元素array[i]，先试探的加上array[i], 如果和为负数，显然，以i结尾的元素对整个结果不作贡献。
// 具体过程：

// 初始化：维护一个变量tmp = 0
// 如果tmp+array[i] < 0, 说明以i结尾的不作贡献，重新赋值tmp = 0
// 否则更新tmp = tmp + array[i]
// 最后判断tmp是否等于0， 如果等于0， 说明数组都是负数，选取一个最大值为答案。

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int ret = array[0];
        int tmp = 0;
        for (const int k : array) {
            if (tmp + k < 0) {
                tmp = 0;
            }
            else {
                tmp += k;
            }
            ret = max(ret, tmp);
        }
        if (tmp != 0)
            return ret;
        return *max_element(array.begin(), array.end());
    }
};




int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
