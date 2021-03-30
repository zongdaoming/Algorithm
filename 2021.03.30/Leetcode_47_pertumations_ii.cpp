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
    // vector<int> vis;
    vector<bool> visited;

    void dfs(vector<int> &nums, vector<vector<int>> &ans, int idx, vector<int> &perm)
    {
        if(idx==nums.size())
        {
            ans.emplace_back(perm);
            return;
        }
        for(int i = 0; i<(int)nums.size(); ++i)
        {
            // 递归边界
             if (visited[i] || (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]))
            {
                continue;
            }
            perm.emplace_back(nums[i]);
            visited[i]=true;
            dfs(nums,ans,idx+1,perm);
            visited[i] = false;
            perm.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> perm;
        // visited.resize(nums.size());
        visited.resize(nums.size(),false);
        sort(nums.begin(), nums.end());
        dfs(nums, ans, 0, perm);
        return ans;
    }
};


// 正常不剪枝的回溯: 对于每一层回溯搜索, 会判断其它未被使用的所有元素(会有重复的元素), 都被填充到该位置一次;
// 剪枝的意思是: 保证相邻的重复元素在每一层的回溯搜索中, 只被回溯搜索填充一个, 其余的不再会填充, 且遵循靠左的第一个未被填充的元素被填充,
// 若没有这个剪枝的过程, 那么这些重复的相邻元素, 会被回溯搜索填充cnt(相邻重复元素)次;
// eg: 对于重复的四个元素 [0, 0, 0, 0], (0 表示未填充) 第一层回溯填充第一个0, 第二层回溯第一个0因已被used, 即continue, 第二个0不会被continue, 执行回溯
// [0, 0, 0, 0] -> [1, 0, 0, 0] -> [1, 1, 0, 0] -> [1, 1, 1, 0] -> [1, 1, 1, 1] (1 表示填充)

class Solution {
    public:
        void dfs(vector<int> &nums, vector<int> &res, vector<vector<int>> &ans, vector<bool> &visited, int pos)
        {
            // 递归边界
            if(pos==nums.size())
            {
                ans.emplace_back(res);
                return;

            }

            for(int i=0; i<nums.size(); i++)
            {
                // visited[i-1]表示在每一次的回溯搜索中只填充靠左的第一个未被填充的元素
                // 剪枝的意思是: 保证相邻的重复元素在每一层的回溯搜索中, 只被回溯搜索填充一个, 其余的不再会填充, 且遵循靠左的第一个未被填充的元素被填充,
                if (visited[i] || (i>0 && nums[i]==nums[i-1] && !visited[i-1]))
                {
                    continue;
                }
                res.emplace_back(nums[i]);
                visited[i]=true;
                // 递归的dfs
                dfs(nums, res, ans, visited, i+1);
                // 回溯=状态重置
                visited[i]=false;
                res.pop_back();
            }
        }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> res;
        vector<bool> visited(nums.size(),false);
        // before dfs, performing sorted
        sort(nums.begin(),nums.end());
        dfs(nums, res, ans, visited, 0);
        return ans;
    }
};