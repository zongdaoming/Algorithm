#include <iostream>
#include <string>
#include <cstdio>
#include <numeric>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) 
    {
        if (nums.size() == 1)   return true;
        bool flag = nums[0] <= nums[1] ? true : false; // 标识是否还能修改,如果这次机会用掉了就没有机会继续修改了
        // 遍历时，每次需要看连续的三个元素: i=1;i<nums.size()-1
        for (int i = 1; i < nums.size() - 1; i++)
        {
            if (nums[i] > nums[i + 1])  // 出现递减
            {
                if (flag)   // 如果还有修改机会，进行修改
                {
                    if (nums[i + 1] >= nums[ i - 1])// 修改方案1
                        nums[i] = nums[i + 1];
                    else                            // 修改方案2
                        nums[i + 1] = nums[i];      
                    flag = false;                   // 用掉唯一的修改机会
                }   
                else        // 没有修改机会，直接结束
                    return false;
            }
        }
        return true;
    }
};
