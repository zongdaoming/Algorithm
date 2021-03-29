#include <iostream>
#include <string>
#include <cstdio>
#include <numeric>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;


// 考虑缩小搜索的空间 【】【】
// 然后考虑两种最好的情况，剩下的都是复杂的情况 注意的是 if else 和 if else if 的使用

class Solution {
public:
    bool search(vector<int>& nums, int target){
        int left = 0, right = nums.size()-1;
        while (left<=right)
        {
            while (left<right && nums[left]==nums[left+1]) left++;
            while (left<right && nums[right]==nums[right-1]) right--;
            int mid = left + (right-left)/2;
            if (nums[mid]==target) return true;
            // /mid 落在同一数组的情况，同时落在数组1 或 数组2
            if (nums[mid]>=nums[left])
            {
                 //target 落在 left 和 mid 之间，则移动我们的right，完全有序的一个区间内查找
                if(nums[mid]>target && target>=nums[left])
                {
                    right = mid - 1;
                  // target 落在right和 mid 之间，有可能在数组1， 也有可能在数组2
                }else if (nums[mid]<target || target<nums[left])
                {
                    left = mid+1;
                }

            }else if (nums[mid]<nums[left])
            {
                if(nums[mid]< target && target <= nums[right])
                {
                    left = mid+1;
                }else if (target <nums[mid] || target>nums[right]){
                    right = mid-1;
                }
            }
        }
        return false;
    }
};

class Solution {
    public: 
    bool search (vector<int> &nums, int target)
    {
        int left = 0, right = nums.size()-1;
        while (left<=right)
        {
            int mid  = left + ((right-left)>>1);
            if (nums[mid]==target)
            {
                return true;
            }
            if (nums[mid]==nums[left])
            {
                // 当 nums[mid] == nums[left] 时，让 left++，并退出本次循环，其余部分完全相同
                left ++;
                continue;
            }
            if (nums[mid]>nums[left])
            {
                if (nums[mid]>target && target>=nums[left])
                {
                    right = mid -1;
                }else if (nums[mid]<target || target<nums[left])
                {
                    left = mid + 1;
                }
            }else if (nums[mid]<nums[left])
            {
                if (nums[mid]<target && target<=nums[right])
                {
                    left = mid+1;
                }else if (nums[mid]>target || nums[right]<target)
                {
                    right = mid -1;
                }
            }
        }
        return false;
    }
};


