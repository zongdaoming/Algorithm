#include <iostream>
#include <string>
#include <cstdio>
#include <numeric>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
#include <algorithm>
using namespace std;



class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        
        if (numbers.empty()) return false;
        sort(numbers.begin(), numbers.end());
        int i = 0, sz = numbers.size();
        
        for (int j=0; j < sz; ++j) {
            
            if ( numbers[j] == 0 ) {
                ++i;       // i 记录最小值的下标
                continue;
            }
            
            if ( j+1 < sz && numbers[j] == numbers[j+1] ) return false;
        
        }  
        return numbers.back() - numbers[i] < 5;
    }
};