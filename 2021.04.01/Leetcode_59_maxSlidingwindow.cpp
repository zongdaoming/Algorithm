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

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> res;
        int n = nums.size();
        deque<int> d;
        k--; // 只是方便后面用
        for (int i = 0; i < n; i++)
        {

            // 添加元素，并保持队列是单调递减的
            while (!d.empty() && nums[d.back()] < nums[i])
            {
                // 删除掉队尾巴的元素
                d.pop_back();
            }

            d.push_back(i);

            // 删除不在窗口内的元素，无论它多大都没用了
            if (!d.empty() && d.front()+k < i)
            {
                d.pop_front();
            }

            // 队列首部对应的元素为本窗口最大值，因为咱们一直保持队列是单调递减的嘛
            if (i >= k)
            {
                res.push_back(nums[d.front()]);
            }
        }
        return res;
    }
};



class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        if(nums.size()==0) return ans;
        int length = nums.size();
        // 维护一个单调队列,存的是数组的index,从尾部开始插入
        deque<int> dq;

        for(int i = 0; i<length; i++)
        {
            while(!dq.empty() && nums[dq.back()]<nums[i])
            {
                // 删除掉队尾巴的元素
                dq.pop_back();
            }
            dq.push_back(i);
            
             // 删除不在窗口内的元素，无论它多大都没用了
            if(!dq.empty() && dq.front()+k<i)
            {
                dq.pop_front();
            }
            
            // 队列首部对应的元素为本窗口最大值，因为咱们一直保持队列是单调递减的嘛
            if(i>=(k-1))
            {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k =3;
    Solution solution;
    solution.maxSlidingWindow(nums,k);
    return 0;
}

// 维持一个双端队列的时间复杂度
// 时间复杂度 O(n) ： 其中 n 为数组 nums 长度；线性遍历 nums 占用 O(n) ；每个元素最多仅入队和出队一次，因此单调队列 deque占用 O(2n) 。
// 空间复杂度 O(k) ： 双端队列 deque中最多同时存储 k 个元素（即窗口大小）


// 暴力求解的时间复杂度
// 设数组 nums 的长度为 nn ，则共有 (n-k+1) 个窗口；
// 获取每个窗口最大值需线性遍历，时间复杂度为 O(k) 。
