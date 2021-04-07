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


// 双端队列的方法
// 首先容器中放的元素应该是单调递减的。
// 然后还有删除容器头部元素和最后一个元素的操作。
// 因此，这样的数据结构就是双端队列。c++中就是deque

class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> ret;
        if (num.size() == 0 || size < 1 || num.size() < size) return ret;
        int n = num.size();
        deque<int> dq;
        for (int i = 0; i < n; ++i) {
            while (!dq.empty() && num[dq.back()] < num[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            // 判断队列的头部的下标是否过期
            if (dq.front() + size <= i) {
                dq.pop_front();
        }
        // 判断是否形成了窗口
            if (i + 1 >= size) {
                ret.push_back(num[dq.front()]);
            }
        }
           return ret;
    }
};

// volient solutions
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> ret;
        if (num.size() == 0 || size < 1 || num.size() < size) return ret;
        int n = num.size();
 
        for (int i = 0; i + size - 1 < n; ++i) {
            int j = i + size - 1;
            int max_val = num[j];
            for (int k = i; k < j; ++k) {
                max_val = max(max_val, num[k]);
            }
            ret.push_back(max_val);
        }
        return ret;
    }
};
// 时间复杂度：O(nk), 其中n为数组大小，k为窗口大小
// 空间复杂度 0（1）存结果必须要开的数组不算入额外空间


class Solution
{
    typedef pair<int,int> Pair;
    public :
    vector<int> maxInWindows(const vector<int> &num, unsigned int size)
    {
        vector<int> result;
        int n = num.size();
        priority_queue<Pair> Q;
        if (num.size() < size || size < 1)
        {
            return result;
        }
        for(int i = 0; i<size-1; i++){
            Q.push({num[i],i});
        }
        for(int i=size-1; i<n; i++)
        {
            Q.push({num[i],i});
            Pair p = Q.top();
            while(p.second+size-1<i)
            {
                Q.pop();
                p = Q.top();
            }
            result.push_back(p.first);
        }
        return result;
    }
};