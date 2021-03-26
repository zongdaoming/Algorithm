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


// 变量必须已经存在才能使用·引用·

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> comb;
        int count = 0;
        dfs( ans, comb, n, k, count, 1);
        return ans;
    }
    void dfs(vector<vector<int>>& ans, vector<int>& comb, int& n, int& k, int count, int pos)
    {
        // 递归边界条件：终止条件
        if(count==k){
            ans.push_back(comb);
            return;
        }

        for(int i=pos; i<=n; i++)
        {
            comb.push_back(i);
            ++count;
            dfs(ans,comb,n,k,count, i+1);
            // 递归重置：回溯
            comb.pop_back();
            --count;
        }
    }
};


// Wrong ANSWER
class Solution {
    public:
    vector<vector<int>> combine(int n, int k)
    {
       vector<int> nums;
       vector<vector<int>> ans;
       vector<int> path;
       vector<bool> visited(n,false);
       for(int i=1; i<=n; i++)
       {
           nums.push_back(i);
       }
       dfs(nums,ans,k,0,path,visited);
       return ans;
    }
    // 辅助函数
    void dfs(vector<int>&nums, vector<vector<int>>& ans, int k, int depth, vector<int>& path, vector<bool> &visited){
        // 递归边界：递归终止条件
        if(depth == k){
            ans.push_back(path);
            return;
        }
        // 循环体
        for(int i = 0; i<nums.size(); i++){
            
            if(visited[i])
            {
                continue;
            }
            visited[i] = true;
            path.push_back(nums[i]);
            dfs(nums,ans,k, depth+1, path, visited);
            // 回溯
            path.pop_back();
            visited[i]=false;
        }
    }
};

// 输入
// 4
// 2
// 输出
// [[1,2],[1,3],[1,4],[2,1],[2,3],[2,4],[3,1],[3,2],[3,4],[4,1],[4,2],[4,3]]
// 预期结果
// [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]



int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
