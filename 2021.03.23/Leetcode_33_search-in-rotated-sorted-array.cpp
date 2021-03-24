#include <iostream>
#include <string>
#include <cstdio>
#include <numeric>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;




class Solution2 {
    public:
        int search(vector<int> &nums, int target)
        {
            int n = nums.size();
            if(nums.empty()) return -1;
            if(n==1) return nums[0]==target?0:-1;
            int left = 0, right = n -1;
            while (left<=right)
            {
                int mid = (left+right)/2;
                if (nums[mid]==target) return mid;
                if(nums[0]<nums[mid]){
                    if(nums[0]<=target && target <nums[mid])
                    {
                        right = mid-1;
                    }else{
                        left = mid+1;

                    }
                }else{
                        if(nums[mid]<target  && target <=nums[n-1])
                        {
                            left = mid+1;
                        }
                        else{
                            right = mid-1;
                        } 
                    }
                }
            
            return -1;
        } 
};




// 二分法的变形
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ans = -1;
        int nlen = nums.size();
        int mark = nums[0];
        int lanch = nums[nlen-1];
        // two extremes
        if (target==mark){
            return 0;
        }
        if (target==nums[nlen-1]){
            return nlen-1;
        }

        if (target>mark){
            int left = 0, right = nlen-1; 
            while (left<=right){
                int mid = left + (right-left)/2;
                if (nums[mid]==target) return mid;
                
                if(nums[mid]>mark && nums[mid]>target)
                {
                    right = mid-1;
                }else if(nums[mid]<mark && nums[mid]<target){
                    right= mid-1;
                }else if(nums[mid]>mark && nums[mid]<target)
                {
                    left = mid+1;
                }
                }
                
            }

        if (target<lanch){
            int left = 0, right = nlen-1; 
            while (left<=right){
                int mid = left + (right-left)/2;
                if (nums[mid]==target) return mid;

                if(nums[mid]<lanch && nums[mid]<target)
                {   
                           left = mid+1; 
                }else if(nums[mid]<lanch && nums[mid]>target){
                    right= mid-1;
                }else if(nums[mid]>lanch && nums[mid]>target)
                {
                    left = mid+1;
                }
                }
                
            }

            return  -1;
    }
};



int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums{4,5,6,7,0,1,2};
    int target = 0;
    int loc = solution.search(nums,target);
    cout<<"The location is "<<loc<<endl;
    system("pause");
    return 0;
}
