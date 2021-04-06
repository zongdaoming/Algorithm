# 题目抽象：求给定数组的topK小问题

----

### 方法一：直接排序，然后去前k小数据
```cpp
class Solution
{
    public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
    {
        vector<int> ret;
        if( k==0 || k>input.size() ) return ret;
        sort(input.begin(),input.end());
        return vector<int>({input.begin(),input.begin()+k});
    }
}
// 时间复杂度 O(nlogn)
// 空间复杂度 O(1)
```

## 方法二：快排思想
对数组`[l, r]`一次快排`partition`过程可得到，`[l, p)`, `p`, `[p+1, r)`三个区间,`[l,p)`为小于等于`p`的值 `[p+1,r)`为大于等于`p`的值。然后再判断p，利用二分法

>1. 如果`[l,p)`, `p`，也就是`p+1`个元素（因为下标从`0`开始），如果`p+1 == k`, 找到答案
>2. 如果`p+1 < k`, 说明答案在`[p+1, r)`区间内，
>3. 如果`p+1 > k` , 说明答案在`[l, p)`内

速排序算法有两个核心点，分别为`哨兵划分`和`递归` 。

`哨兵划分`操作： 以数组某个元素（一般选取首元素）为**基准数** ，将所有小于基准数的元素移动至其左边，大于基准数的元素移动至其右边.


### 复杂度分析：
时间复杂度`O(NlogN)`： 库函数、快排等排序算法的平均时间复杂度为`O(NlogN)`。
空间复杂度`O(N)`: 快速排序的递归深度最好（平均）为 `O(logN)` ，最差情况（即输入数组完全倒序）为`O(N)`。

```cpp
class Solution
{
    public:
    vector<int> getLeastNumbers(vector<int> &arr, int k)
    {
        
    }
    private:
    void quickSort(vector<int> &arr, int l, int r)
    {
        // 子数组长度为 1 时终止递归
        if(l>=r) return;
        // 哨兵划分操作,(以arr[l]作为基数)
        int i = l; j =r;
        while(i<j)
        {
            while(i<j  && arr[j]>=arr[l] ) j--;
            while(i<j  && arr[i]<=arr[l]) i++;
            swap(arr[i],arr[j]);
        }
        swap(arr[i],arr[l]);
        // 递归左(右)子数组执行哨兵划分
        quickSort(arr,l,i-1);
        quickSort(arr,i+1,r);
    }
};
```

### 基于快速排序的数组划分
题目只要求返回最小的 `k` 个数，对这 `k`个数的`顺序`并没有要求。因此，只需要将数组划分为 **最小的k个数** 和 其他数字两部分即可，而快速排序的哨兵划分可完成此目标。

本方法优化时间复杂度的本质是通过判断舍去了不必要的递归（哨兵划分）.


* 时间复杂度：平均时间复杂度为O(n),每次partition的大小为n+n/2+n/4+... = 2n,最坏时间复杂度为O(n^2), 因为每次partition都只减少一个元素

* 空间复杂度：O(1)

```cpp
class Solution
{
    public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (k >= arr.size()) return arr;
        return quickSort(arr, k, 0, arr.size() - 1);
    }
    private:
    vector<int> quickSort(vector<int> &arr, int k, int l, int r)
    {
        int i = l, j = r;
        while(i<j)
        {
            // from right->left find first smaller
            while(i<j  && arr[j] >= arr[l]) j--;
            // from left->right  find first bigger
            while(i<j  && arr[i] <= arr[l]) i++;
            swap(arr[i],arr[j]);
        }
        swap(arr[i], arr[l]);
        if(i>k) return quickSort(arr, k, l, i-1);
        if(i<k) return quickSort(arr, k, i+1, r);
        vector<int> res;
        res.assign(arr.begin(), arr.begin()+k);
        return res;
    }
};
```


## 方法四: 堆排序
建立一个容量为`k`的大根堆的优先队列。遍历一遍元素，如果队列大小`<k`, 就直接入队，否则，让当前元素与队顶元素相比，如果队顶元素大，则出队，将当前元素入队.
```cpp
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> ret;
        if (k==0 || k>input.size())
        {
            return ret;
        }
        // 堆的性质是每次可以找出最大或最小的元素。我们可以使用一个大小为 k 的最大堆（大顶堆），将数组中的元素依次入堆，当堆的大小超过 k 时，便将多出的元素从堆顶弹出。
        // 这样，由于每次从堆顶弹出的数都是堆中最大的，最小的 k 个元素一定会留在堆里。这样，把数组中的元素全部入堆之后，堆中剩下的 k 个元素就是最大的 k 个数了。
        priority_queue<int,vector<int>> pq;
        
        for(const int val: input){
            if (pq.size()<k){
                pq.push(val);
            }
            else{
                if(val<pq.top()){
                    pq.pop();
                    pq.push(val);
                }
            }
        }
        while(!pq.empty())
        {
            ret.push_back(pq.top());
            pq.pop();
        }
        return ret;
    }
};
```
### 算法的复杂度分析：
* 由于使用了一个大小为`k`的堆，空间复杂度为 `O(k)`；
* 入堆和出堆操作的时间复杂度均为`O(logk)`，每个元素都需要进行一次入堆操作，故算法的时间复杂度为`O(nlogk)`。
