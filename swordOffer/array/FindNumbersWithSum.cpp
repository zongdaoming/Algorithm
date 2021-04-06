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


// 因为数组是有序的，所以可以用双指针，指向数组的首尾，具体步骤如下：
// 1.初始化：指针i指向数组首， 指针j指向数组尾部
// 2. 如果arr[i] + arr[j] == sum , 说明是可能解
// 3. 否则如果arr[i] + arr[j] > sum, 说明和太大，所以--j
// 4. 否则如果arr[i] + arr[j] < sum, 说明和太小，所以++i
// 代码


class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        if(array.empty()) return vector<int> ();
        int tmp = INT32_MAX;
        pair<int,int> ret;
        int i = 0, j = array.size()-1;
        while(i<j)
        {
            if(array[i] + array[j] == sum){
                if(array[i]*array[j]<tmp){
                    tmp =  array[i]*array[j];
                    ret = {i,j};
                }
                ++ i, --j;
            }
            else if(array[i]+array[j]<sum){
                ++i;
            }
            else{
                --j;
            }
        }
        if(ret.first ==ret.second) return vector<int>();
        return vector<int>({array[ret.first],array[ret.second]});
    }
};