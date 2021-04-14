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
            while(i<j  && arr[j]>=arr[l]) j--;
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



# 归并排序

题目描述：给定一个数组`arr`， 数组元素各不相同，求`arr[i] > arr[j]` 且 `i < j`的个数。

首先还是提出两个问题，带着问题来看题解，我觉得效率更好。

1. Q1：为什么归并排序需要额外的空间？
2. Q2：为什么此题的最优解法可以借助归并排序的思想？

直观来看，使用暴力统计法即可，即遍历数组的所有数字对并统计逆序对数量。此方法时间复杂度为`O(N^2)` ，观察题目给定的数组长度范围`0≤N≤50000` ，可知此复杂度是不能接受的。

「归并排序」与「逆序对」是息息相关的。归并排序体现了 “分而治之” 的算法思想，具体为：

1. 分： 不断将数组从中点位置划分开（即二分法），将整个数组的排序问题转化为子数组的排序问题；
2. 治： 划分到子数组长度为 1 时，开始向上合并，不断将 较短排序数组 合并为 较长排序数组，直至合并至原数组时完成排序；

算法流程:

`merge_sort()` 归并排序与逆序对统计：

1. 终止条件： 当 `l≥r` 时，代表子数组长度为 `1` ，此时终止划分；

2. 递归划分： 计算数组中点`m`，递归划分左子数组 `merge_sort(l, m)` 和右子数组 `merge_sort(m + 1, r)` ；

3. 合并与逆序对统计：

* 暂存数组 `nums` 闭区间`[i,r]`内的元素至辅助数组 `tmp` ；

* 循环合并： 设置双指针 i , j 分别指向左 / 右子数组的首元素；

   * 当 `i = m + 1` 时： 代表左子数组已合并完，因此添加右子数组当前元素 `tmp[j]` ，并执行`j=j+1` ；

   * 否则，当 `j=r+1` 时： 代表右子数组已合并完，因此添加左子数组当前元素`tmp[i]`，并执行 `i=i+1`；

   * 否则，当 `tmp[i]≤tmp[j]` 时： 添加左子数组当前元素 `tmp[i]` ，并执行 `i=i+1`；

   * 否则（即`tmp[i]>tmp[j]`）时： 添加右子数组当前元素 `tmp[j]`，并执行 `j=j+1` ；此时构成 `m−i+1` 个「逆序对」，统计添加至`res`；

4. 返回值： 返回直至目前的逆序对总数 `res` ；

```cpp
class Solution {
    public:
    int reversePairs(vector<int> &nums)
    {
        vector<int> tmp(nums.size());
        return mergeSort(0,nums.size()-1, nums, tmp);
    }
    private:
    int mergeSort(int l, int r, vector<int> &nums, vector<int> &tmp)
    {
        // 终止条件
        if(l >= r) return 0;
        // 递归划分
        int m = l + (r-l)/2;
        int res = mergeSort(l, m, nums, tmp) + mergeSort(m+1, r, nums, tmp);
        // 合并阶段
        int i = l, j = m+1;

        for(int k = l; k<= r; k++)
        {
            tmp[k] = nums[k];
        }
        // 典型的双指针滑动
        for(int k = l; k<=r; k++)
        {
            // 表示左子数组已经合并完了
            if(i==(m+1))
            {
                nums[k] = tmp[j++];
            }
            // 表示右子数组已经合并完了
            else if (j == (r+1) || tmp[i] <= tmp[j])
            {
                nums[k] = tmp[i++];
            }
            else
            {
                nums[k] = tmp[j++];
                res += m-i+1; //统计逆序对
            }
        
        }
        return res;
    }
};
```


## 双指针方法

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
      int i = m-1, j = n-1;
      int tail = m+n-1;
      int temp; //设立一个临时变量
      while(i>=0||j>=0)
      {
        if(i==-1){
            // cur= nums2[j];
            // j--;
            temp = nums2[j--];
        }else if(j==-1){
            // cur = nums1[i];
            // i--;
            temp = nums1[i--];
        }else if(nums1[i]>nums2[j]){
            temp=nums1[i--];
        }else{
            temp = nums2[j--];
        }
        nums1[tail--] = temp;
      }
}
};
```

## 数组中的逆序对
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组,求出这个数组中的逆序对的总数`P`。并将P对`1000000007`取模的结果输出。 即输出`P%1000000007`

```cpp
class Solution {
public:
    long long int mod = 1000000007;
    int InversePairs(vector<int> data) {
        int length = data.size();
        vector<int> tmp(length);
        long int res = mergeSort(0,length-1,data,tmp);
        return res%mod;
    }
private:
    long int mergeSort(int l, int r, vector<int> &nums, vector<int> &tmp)
    {
        // 终止条件
        if(l >= r) return 0;
        // 递归划分
        int m = l + (r-l)/2;
        long int res = mergeSort(l, m, nums, tmp) + mergeSort(m+1, r, nums, tmp);
        // 合并阶段
        int i = l, j = m+1;

        for(int k = l; k<= r; k++)
        {
            tmp[k] = nums[k];
        }
        // 典型的双指针滑动
        for(int k = l; k<=r; k++)
        {
            // 表示左子数组已经合并完了
            if(i==(m+1))
            {
                nums[k] = tmp[j++];
            }
            // 表示右子数组已经合并完了
            else if (j == (r+1) || tmp[i] <= tmp[j])
            {
                nums[k] = tmp[i++];
            }
            else
            {
                nums[k] = tmp[j++];
                res += m-i+1; //统计逆序对
            }
        
        }
        return res;
    }
};
```