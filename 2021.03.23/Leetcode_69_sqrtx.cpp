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
    int mySqrt(int x) {
        int low = 0, high = x, ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            // 这里mid 还没有处理完，因为下面有一个条件执行语句
            if ((long long)mid * mid <= x) {
                ans = mid; //key point
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};



int main(int argc, char const *argv[])
{
    
    return 0;
}
