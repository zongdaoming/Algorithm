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
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        // 快慢指针
        if( n == 0 ) return 0;
        int i = 0, j = 1;
        while(j < n)
        {
            if(nums[i] != nums[j])
            {
                // amounts to ... 
                nums[++i] = nums[j];               
                // i++;
                // nums[i] = nums[j];
            }
            j++;
        }
        for(int i=0; i<nums.size(); i++)
        {
            cout<<" array "<<nums[i]<<endl;
        }
        return i+1;
    }
};




