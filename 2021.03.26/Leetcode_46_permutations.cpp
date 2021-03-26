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

// 深度优先遍历树：状态变量
// 1.递归到第几层 depth
// 2.已经选了那些数 path
// 3.布尔数组used 初始化为false (以空间换时间的思想)
// 状态重置=回溯 使用一个状态变量进行回溯

// 状态变量：depth(到第几层), path(已经选择的数), visited(表示当前的数是否已经被选择)
class SolutionTraceBack {
    public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        int len = nums.size();
        vector<vector<int>> ans;
        if(nums.empty()) return ans;
        // vector 要先初始化
        // 以时间换空间，需要显式定义
        vector<bool> visited(len, false);
        // 栈：已经选择了那些数，可以知道哪些数已经别选择；
        vector<int> path;
        // 这里传递的0是状态变量，状态重置=回溯
        dfs(nums, 0, path, visited, ans);
        return ans;
    }
    void dfs(vector<int>& nums, int depth, vector<int>& path, vector<bool>& visited, vector<vector<int>>& ans)
    {
        // 递归边界: 递归终止的条件
        if(depth==nums.size())
        {
            ans.push_back(path);
        //    显式地返回
           return;
        }
        for(int i=0; i<nums.size(); i++)
        {
            if(visited[i])
            {
                continue;
            }
            // 在合适的时间保存状态即可
            path.push_back(nums[i]);
            visited[i]=true;    
            dfs(nums, depth+1, path, visited, ans);
            // 回溯=状态变量重置
            path.pop_back();
            visited[i] =false;
        }
    }
};


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        backtracking(nums,ans,0);
        return ans;
    }
    void backtracking(vector<int>& nums,vector<vector<int>>& ans, int level)
    {
    if(level == nums.size()-1)
    {
        ans.push_back(nums);
        return;
    }
    for(int i = level; i<nums.size(); i++)
    {
        swap(nums[i],nums[level]);//修改当前节点;
        backtracking(nums, ans, level+1); // 递归子节点;
        swap(nums[i],nums[level]); //回改当前节点
    }
    }
};


void print2dvec(vector<vector<int>>& nums)
{
    for(int i =0; i<nums.size(); i++)
    {
        for(int j = 0; j<nums[0].size(); j++)
        {
            cout<<" " <<nums[i][j]<<" "; 
        }
        cout<<endl;
    }
}


int main(int argc, char const *argv[])
{
    SolutionTraceBack solution;
    vector<int> nums ={1,2,3};
    vector<vector<int>> ans;
    ans = solution.permute(nums);

    print2dvec(ans);

    system("pause");
    return 0;
}
