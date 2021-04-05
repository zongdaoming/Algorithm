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
        int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.empty())
            return 0;
 
        int low = 0;
        int high = rotateArray.size() - 1;
        int mid = 0;
 
        while(low < high){
            // 子数组是非递减的数组，10111
            if (rotateArray[low] < rotateArray[high])
                return rotateArray[low];
            mid = low + (high - low) / 2;
            if(rotateArray[mid] > rotateArray[low])
                low = mid + 1;
            else if(rotateArray[mid] < rotateArray[high])
                high = mid;
            else low++;
        }
        return rotateArray[low];
    }
};
