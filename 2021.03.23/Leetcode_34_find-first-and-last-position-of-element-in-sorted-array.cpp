#include <iostream>
#include <string>
#include <cstdio>
#include <numeric>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
    public:
    // 全部统一到左闭右闭区间

    // 寻找target的左边界
    int leftBound(vector<int> & nums, int target)
    {
        int left = 0, right = nums.size()-1;
        while(left<=right)
        {
            int mid = left + (right -left )/2;
            if(nums[mid]==target)
            {
                right = mid -1;
            }else if (nums[mid]<target)
            {
                left = mid +1;
            }else if (nums[mid]>target)
            {
                right = mid-1;
            }
        }
        // 当target 小于 nums 中所有值时，left = 0, right = -1;
        // 当target 大于nums中所有值时， left=nums.size(), right=nums.size()-1
        // 当target处于nums的最大值和最小值之间，但没有相等值，就需要第二个判断
        if (left>=nums.size() || nums[left]!=target)
        {
            return -1;
        }
        return left;
    }

    // 辅函数
    // 寻找target的右边界
    int rightBound(vector<int> &nums, int target)
    {

        int left = 0, right = nums.size()-1;
        while(left<=right)
        {
            int mid = left + (right-left)/2;
            if(nums[mid]==target)
            {
                left = mid+1;
            }else if (nums[mid]> target)
            {
                right = mid-1;
            }else if (nums[mid]<target)
            {
                left  = mid+1;
            }
        }
        if (right<0|| nums[right]!=target)
        {
            return -1;
        }
        return right;
    }

    vector<int> searchRange(vector<int>& nums, int target)
    {
        vector<int> ans{-1,-1};
        if (nums.empty()) return vector<int>{-1,-1};

        int left = leftBound(nums,target);
        int right = rightBound(nums, target);
        ans = {left, right};
        return ans;
    }
};



int main(int argc, char const *argv[])
{
   Solution solution;
   vector<int> nums={1,2,3,5,5,4,4,5,6}, ans;
   int target = 5;
   ans = solution.searchRange(nums,target);
   for(auto & elem: ans)
   {
      cout<<"The results is "<<elem<<endl;
   }
    getchar();
    return 0;
}
