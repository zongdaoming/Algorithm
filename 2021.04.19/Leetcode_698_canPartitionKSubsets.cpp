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
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        // 计算和，得到每组的预计和
        // int maxNum = INT_MIN;
        // int minNum = INT_MAX;
        int n = nums.size();
        // int total = 0;
        // for (int i = 0; i < n; ++i)
        // {
        //     total += nums[i];
        //     maxNum = max(maxNum, nums[i]);
        //     minNum = min(minNum, nums[i]);
        // }
        int total  = accumulate(nums.begin(), nums.end(), 0);
        int minNum = *min_element(nums.begin(),nums.end());
        int maxNum = *max_element(nums.begin(),nums.end());
        // 预先判断来优化
        int target = total / k;
        if ((total % k != 0) || (target < maxNum))
        {
            return false;
        }
        // 额外判断最大值最小值之和已经大于target也认为又问题
        if (minNum != target && maxNum != target && (minNum+maxNum) > target)
        {
            return false;
        }
        // bool* used = new bool[n];
        // memset(used, 0, sizeof(bool) * n);
        vector<bool> used(n, false);
        return dfs(nums, target, target, k, 0, used);
    }

    // target 目标值
    // rest 剩余的数字
    // group 当前组的编号，是 1-k 共k组
    // start 开始遍历nums的序号， 0~n-1
    // used 数组标记
    bool dfs(vector<int>& nums, int target, int rest, int group, int start, vector<bool>& used)
    {
        // 如果移到最后一个组则表示成功了
        if (group == 0)
        {
            return true;
        }
        // 遍历数字取那些没被用过的数字
        int n = nums.size();
        for (int i = start; i < n; ++i)
        {
            if (!used[i])
            {
                used[i] = true;
                // 考虑两种情况
                // - 当前数字考虑后依然小于目标，则在当前组内递归(减少目标值，起始位置+1)
                // - 当前数字考虑后依然等于目标，则继续遍历下一组(重置目标和起始位置)
                if ((nums[i] < rest && dfs(nums, target, rest-nums[i], group, i+1, used))
                        || (nums[i] == rest && dfs(nums, target, target, group-1, 0, used)))
                {
                    return true;
                }
                // 如果不是第二个元素，则继续向下面遍历，所以需要回溯
                // 遍历完回溯设置回去
                used[i] = false;
            }
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution solu;
    vector<int> nums = {4, 3, 2, 3, 5, 2, 1};
    int k = 4;
    solu.canPartitionKSubsets(nums, k);
    system("pause");
    return 0;
}
