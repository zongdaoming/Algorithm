#include <iostream>
#include <string>
#include <cstdio>
#include <numeric>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;
// if 和 else if的区别要注意，前者和后者对程序的影响性差异非常巨大
// if (xxx) {xx} else if (){xxx}
// if (xxx) {xx} else {xxx}
// if (xxx) else {xxx}
class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size()==1) return nums[0];
        int left = 0, right = nums.size() - 1;
        while (left<=right)
        {

            // 单调递增时直接返回
            if(nums[left]<=nums[right])
            {
                return nums[left];
            }
            int mid = left + (right-left)/2;
            // mid 和 left 之间单调递增,说明必然不在这里
            if(nums[mid]>=nums[left])
            {
                left= mid+1;
            } else if(nums[mid]<nums[left])
            {
                right = mid;
            }
        }
        return -1;
    }
};