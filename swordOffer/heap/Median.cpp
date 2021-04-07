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

// 所以，GetMedian()操作算法过程为：
// 初始化一个大顶堆，存中位数左边的数据，一个小顶堆，存中位数右边的数据
// 动态维护两个数据结构的大小，即最多只相差一个

// 中位数是指：有序数组中中间的那个数。则顶据中位数可以把数组分为如下三段:
// [0 ... median - 1], [median], [median ... arr.size() - 1]，即[中位数的左边，中位数，中位数的右边]

// 那么，如果我有个数据结构保留[0...median-1]的数据，并且可以O(1)时间取出最大值，即arr[0...median-1]中的最大值
// 相对应的，如果我有个数据结构可以保留[median + 1 ... arr.size() - 1] 的数据， 并且可以O(1)时间取出最小值，即
// arr[median + 1 ... arr.size() - 1] 中的最小值。
// 然后，我们把[median]即中位数，随便放到哪个都可以。

// 假设[0 ... median - 1]的长度为l_len, [median + 1 ... arr.sise() - 1]的长度为 r_len.
// 1.如果l_len == r_len + 1, 说明，中位数是左边数据结构的最大值
// 2.如果l_len + 1 == r_len, 说明，中位数是右边数据结构的最小值
// 3.如果l_len == r_len, 说明，中位数是左边数据结构的最大值与右边数据结构的最小值的平均值。

// 说了这么多，一个数据结构可以O(1)返回最小值的，其实就是小顶堆，O(1)返回最大值的，其实就是大顶堆。并且每次插入到堆中的时间复杂度为O(logn)

// 所以，GetMedian()操作算法过程为：

// 初始化一个大顶堆，存中位数左边的数据，一个小顶堆，存中位数右边的数据
// 动态维护两个数据结构的大小，即最多只相差一个


class Solution{
    public:
    #define SCD static_cast<double>
    priority_queue<int> min_q; //大顶堆
    // priority_queue<int, vector<int>, less<int>> min_q;
    priority_queue<int, vector<int>, greater<int>> max_q; //小顶堆

    void Insert(int num)
    {
        min_q.push(num); //试图加入大顶堆
        // 平衡一个两个堆
        max_q.push(min_q.top());
        min_q.pop();

       if (min_q.size() < max_q.size())
        { 
            min_q.push(max_q.top());
            max_q.pop();
        }
    }
    double GetMedian()
    {
        return min_q.size() > max_q.size()? SCD(min_q.top()): SCD(min_q.top() + max_q.top()) / 2;
    }
};

