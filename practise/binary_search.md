# 一文带你搞定二分搜索及多个变种
![](./images/binary_search.jpg)


# 完全有序
## 二分查找
二分查找也称折半查找（`Binary Search`），是一种在有序数组中查找某一特定元素的`搜索算法`。我们可以从定义可知，运用二分搜索的前提是`数组必须是有序的`，这里需要注意的是，我们的输入不一定是数组，也可以是数组中某一区间的起始位置和终止位置。

```cpp
int[ ]  nums = {1,3,4,5,6,8,12,14,16}; target = 8; 
```

（1）我们需要定义两个指针分别指向数组的头部及尾部，这是我们在整个数组中查询的情况，当我们在数组某一区间进行查询时，可以输入数组，起始位置，终止位置进行查询。
![](images/binary_1.png)
（2）找出mid，该索引为 `mid =（left + right）/ 2`，但是这样写有可能溢出，所以我们需要改进一下写成

`mid = left +（right - left）/ 2` 或者 `left + ((right - left ) >> 1)` 两者作用是一样的，都是为了找到两指针的中间索引，使用位运算的速度更快。那么此时的 `mid = 0 + (8-0) / 2 = 4`
![](images/binary_2.png)

（3）此时我们的 mid = 4，nums[mid] = 6 < target,那么我们需要移动我们的 left 指针，让`left = mid + 1`，下次则可以在新的 left 和 right 区间内搜索目标值，下图为移动前和移动后
![](images/binary_3.png)

（4）我们需要在 left 和 right 之间计算 mid 值，`mid = 5 + （8 - 5）/ 2 = 6` 然后将 nums[mid] 与 target 继续比较，进而决定下次移动left 指针还是 right 指针，见下图
![](images/binary_4.png)

（5）我们发现 nums[mid] > target，则需要移动我们的 right 指针， 则 `right = mid - 1`；则移动过后我们的 left 和 right 会重合，这里是我们的一个重点大家需要注意一下，后面会对此做详细叙述。
![](images/binary_5.png)

（6）我们需要在 left 和 right 之间继续计算 mid 值，则 `mid = 5 +（5 - 5）/ 2 = 5` ，见下图，此时我们将 `nums[mid]` 和 `target` 比较，则发现两值相等，返回 `mid` 即可 ，如果不相等则跳出循环，返回 `-1`。
![](images/binary_6.png)
二分查找的执行过程如下

1.从已经排好序的数组或区间中，取出中间位置的元素，将其与我们的目标值进行比较，判断是否相等，如果相等则返回。

2.如果 nums[mid] 和 target 不相等，则对 nums[mid] 和 target 值进行比较大小，通过比较结果决定是从 mid的左半部分还是右半部分继续搜索。如果 `target > nums[mid]` 则右半区间继续进行搜索，即 `left = mid + 1`; 若`target < nums[mid]` 则在左半区间继续进行搜索，即 `right = mid -1`；(**从标准的二分思想进行想象**)。

动图解析
![](images/binary_7.gif)

下面我们来看一下二分查找的代码，可以认真思考一下 if 语句的条件，每个都没有简写
```cpp
public static int binarySearch(vector<int> nums, int target,int left, int right)

{ 
    // 这里需要注意,循环条件
    while(left<right)
    {
        // 这里需要注意,计算mid
        int mid = left + ((right-left)>>1);    
        if(nums[mid]==target)
        {
            return mid;
        }else if (nums[mid]<target)
        {
            // 这里需要注意,移动左指针
            left = mid + 1;
        }else if (nums[mid]>target)
        {
            // 这里需要注意，移动右指针
            right = mid -1;
        }
    }
    // 没有找到该元素，返回-1；
    return -1;
}
```


二分查找的思路及代码已经理解了，那么我们来看一下实现时容易出错的地方

1.**计算 mid 时 ，不能使用 （left + right ）/ 2,否则有可能会导致溢出**


2.while (left < = right) { } 注意括号内为 `left <= right` ,而不是 `left < right` ，我们继续回顾刚才的例子，如果我们设置条件为 `left < right` 则当我们执行到最后一步时，则我们的 `left` 和 `right` 重叠时，则会跳出循环，返回 `-1`，区间内不存在该元素，但是不是这样的，我们的 `left` 和 `right` 此时指向的就是我们的目标元素。


3.`left = mid + 1`,`right = mid - 1` 而不是 `left = mid` 和 `right = mid`。我们思考一下这种情况,见下图，当我们的target 元素为 16 时，然后我们此时 left = 7 ，right = 8，mid = left + (right - left) = 7 + (8-7) = 7，那如果设置 left = mid 的话，则会**进入死循环**，mid 值一直为7 。
```cpp
public static int binarySearch(vector<int> nums, int target, int left, int right)
{
    if(left<=right)
    {
        int mid = left + (right - left)/2;
        if(nums[mid]==target) return mid;
        if(nums[mid]>target){
            return binarySearch(nums,target,left,mid-1);
        }
        if(nums[mid]<target){
            return binarySearch(nums,target,mid+1,right);
        }
    }
    // 不存在，这返回-1
    return -1;
}
```
------------------------

### 查找元素第一个位置和最后一个位置
上面我们说了如何使用二分查找在数组或区间里查出特定值的索引位置。但是我们刚才数组里面都没有重复值，查到返回即可，那么我们思考一下下面这种情况
![](./images/binary_repeat.png)
此时我们数组里含有多个 `5` ，我们查询是否含有 `5` 可以很容易查到，但是我们想获取第一个 `5` 和 最后一个 `5` 的位置应该怎么实现呢？哦！我们可以使用遍历或者`正反双向指针`，当查询到第一个 `5` 时，我们设立一个指针进行定位，然后到达最后一个 `5` 时返回，这样我们就能求的第一个和最后一个五了？因为我们这个文章的主题就是二分查找，我们可不可以用二分查找来实现呢？当然是可以的。

leetcode 34在排序数组中查找元素的第一个和最后一个位置
题目描述
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

如果数组中不存在目标值 target，返回 [-1, -1]。

示例 1：

输入：nums = [5,7,7,8,8,10], target = 8
输出：[3,4]

示例 2：

输入：nums = [5,7,7,8,8,10], target = 6
输出：[-1,-1]

示例 3：

输入：nums = [], target = 0
输出：[-1,-1]

题目解析
这个题目很容易理解，我们在上面说了如何使用遍历解决该题，但是这个题目的目的就是让我们使用二分查找，我们来逐个分析，先找出目标元素的下边界，那么我们如何找到目标元素的下边界呢？
```cpp
  if (nums[mid] == target) {
       return mid;
  }else if (nums[mid] < target) {
      //这里需要注意，移动左指针
      left  = mid + 1;
  }else if (nums[mid] > target) {
      //这里需要注意，移动右指针
      right = mid - 1;
  } 
```
我们只需在这段代码中修改即可，我们再来剖析一下这块代码，`nums[mid] == target` 时则**返回**，`nums[mid] < target` 时则移动左指针，在右区间进行查找， `nums[mid] > target`时则移动右指针，在左区间内进行查找。

那么我们思考一下，如果此时我们的 `nums[mid] = target` ,但是我们不能确定 `mid` 是否为该目标数的左边界，所以此时我们不可以返回下标。例如下面这种情况
![](./images/binary_search_equal.png)
此时 `mid = 4` ，`nums[mid] = 5`,但是此时的 `mid` 指向的并不是第一个 `5`，所以我们需要继续查找 ，因为我们要找的是数的下边界，所以我们需要在 mid 的值的左区间继续寻找 5 ，那我们应该怎么做呢？我们只需在

`target <= nums[mid]` 时，让 `right = mid - 1`即可，这样我们就可以继续在 `mid` 的左区间继续找 5 。通俗地讲，**就是让right去不断地逼近(approaching)下届！**
![](./images/binary_search_equal_1.png)
![](./images/binary_search_equal_2.png)

其实原理很简单，就是我们将小于和等于合并在一起处理，当 `target <= nums[mid]` 时，我们都移动右指针，也就是 `right = mid -1`，还有一个需要注意的就是，我们**计算下边界时最后的返回值为 left**(因为right 又往下边界跑了一位) ，当上图结束循环时，`left = 3`，`right = 2`，返回 left 刚好时我们的下边界。我们来看一下求下边界的具体执行过程。
![](./images/binary_search_equal.gif)

### 计算下边界代码
```cpp
int lowerBound(int[] nums, int target) {
        int left = 0, right = nums.length - 1;
        while (left <= right) {
            //这里需要注意，计算mid
            int mid = left + ((right - left) >> 1);
            if (target <= nums[mid]) {
                //当目标值小于等于nums[mid]时，继续在左区间检索，找到第一个数
                right = mid - 1;

            }else if (target > nums[mid]) {
                //目标值大于nums[mid]时，则在右区间继续检索，找到第一个等于目标值的数
                left = mid + 1;

            }
        }
        return left;
    }
```
计算上边界时算是和计算上边界时条件相反，
### 计算上边界的代码
```cpp
int upperBound(int[] nums, int target) {
        int left = 0, right = nums.length - 1;
        while (left <= right) {
            //求mid
            int mid = left + ((right - left) >> 1);
            //移动左指针情况
            if (target >= nums[mid]) {
                 left = mid + 1; 
            //移动右指针情况
            }else if (target < nums[mid]) {
                right = mid - 1;
            }
            
        }
        return left;
    }
```

### 题目完整代码
```cpp
class Solution {
    public int[] searchRange (int[] nums, int target) {
         int upper = upperBound(nums,target);
         int low = lowerBound(nums,target);  
         //不存在情况
         if (upper < low) {
             return new int[]{-1,-1};
         }
         return new int[]{low,upper};
    }
    //计算下边界
    int lowerBound(int[] nums, int target) {
        int left = 0, right = nums.length - 1;
        while (left <= right) {
            //这里需要注意，计算mid
            int mid = left + ((right - left) >> 1);
            if (target <= nums[mid]) {
                //当目标值小于等于nums[mid]时，继续在左区间检索，找到第一个数
                right = mid - 1;

            }else if (target > nums[mid]) {
                //目标值大于nums[mid]时，则在右区间继续检索，找到第一个等于目标值的数
                left = mid + 1;

            }
        }
        return left;
    }
    //计算上边界
    int upperBound(int[] nums, int target) {
        int left = 0, right = nums.length - 1;
        while (left <= right) {          
            int mid = left + ((right - left) >> 1);
            if (target >= nums[mid]) {
                 left = mid + 1;               
            }else if (target < nums[mid]) {
                right = mid - 1;
            }            
        }
        return right;
    }
}
```
我们也可以直接用STL中的`upper_bound()`,`lower_bound()`库函数
```cpp
class Solution {
    public:
    int GetNumberOfK(vector<int> nums, int target)
    {
        return upper_bound(nums.begin(), nums.end(), target) - lower_bound(nums.begin(), nums.end(), target);
    }

}
```
------------------------

### 找出第一个大于目标元素的索引
我们在上面的变种中，描述了如何找出目标元素在数组中的上下边界，然后我们下面来看一个新的变种，如何从数组或区间中找出第一个大于或最后一个小于目标元素的数的索引，例 `nums = {1,3,5,5,6,6,8,9,11}` 我们希望找出第一个大于 `5`的元素的索引，那我们需要返回 `4`，因为 5 的后面为 `6`，第一个 `6`的索引为 `4`，如果希望找出最后一个小于 `6` 的元素，那我们则会返回 `3` ，因为 6 的前面为 5 最后一个 5 的索引为 3。好啦题目我们已经了解，下面我们先来看一下如何在数组或区间中找出第一个大于目标元素的数吧。

找出第一个大于目标元素的数，大概有以下几种情况
![](./images/first_max_index.png)

1.数组包含目标元素，找出在他后面的第一个元素

2.目标元素不在数组中，且数组中的所有元素都大于它，那么我们此时返回数组的第一个元素即可

3.目标元素不在数组中，数组内的部分元素大于它，此时我们需要返回第一个大于他的元素

4.目标元素不在数组中，且数组中的所有元素都小于它，那么我们此时没有查询到，返回 -1 即可。

既然我们已经分析完所有情况，那么这个题目对咱们就没有难度了，下面我们描述一下案例的执行过程
```
nums = {1,3,5,5,6,6,8,9,11} target = 7
```
上面的例子中，我们需要找出第一个大于 7 的数，那么我们的程序是如何执行的呢？
![](images/first_max_index_1.png)
上面的例子我们已经弄懂了，那么我们看一下，当 target = 0时，程序应该怎么执行呢？
![](images/first_max_index_2.png)
```cpp
public static int lowBoundnum(int[] nums,int target,int left, int right) {

        while (left <= right) {
            //求中间值
            int mid = left + ((right - left) >> 1);
            //大于目标值的情况
            if (nums[mid] > target) {
                 //看看是不是当前区间的最前面的一位；如果当前大于，前面以为小于等于，返回当前值即可
                if (mid == 0 || nums[mid-1] <= target) {
                    return mid;
                }
                else{
                    right = mid -1;
                }

            } else if (nums[mid] <= target){
                left = mid + 1;
            }
        }
        //所有元素都小于目标元素
        return -1;
    }
```

------------------------

### 找出最后一个小于目标元素的索引
通过上面的例子我们应该可以完全理解了那个变种，下面我们继续来看以下这种情况，那就是如何找到最后一个小于目标数的元素。还是上面那个例子
```cppp
nums = {1,3,5,5,6,6,8,9,11} target = 7
```
查找最后一个小于目标数的元素，比如我们的目标数为 7 ，此时他前面的数为 6，最后一个 6 的索引为 5，此时我们返回 5 即可，如果目标数元素为 12，那么我们最后一个元素为 11，仍小于目标数，那么我们此时返回 8，即可。这个变种其实算是上面变种的相反情况，上面的会了，这个也完全可以搞定了，下面我们看一下代码吧。
```cpp
public static int upperBoundnum(int[] nums,int target,int left, int right) {

        while (left <= right) {

            int mid = left + ((right - left) >> 1);
             //小于目标值
            if (nums[mid] < target) {
                //看看是不是当前区间的最后一位，如果当前小于，后面一位大于，返回当前值即可
                if (mid == right || nums[mid+1] >= target) {
                    return mid;
                }
                else{
                    left = mid + 1;
                }

            } else if (nums[mid] >= target){
                right = mid - 1;
            }
        }
        //没有查询到的情况
        return -1;
    }
```

------------------------

## 不完全有序
###　查找目标元素（不含重复元素）
之前我们说二分查找需要在完全有序的数组里使用，那么不完全有序时可以用吗？
![](./images/not_complete_ordered.png)

上面的新数组虽然不是完全有序，但是也可以看成是由一个完全有序的数组翻折得到的。或者可以理解成两个有序数组，且第二个数组的最大值小于第一的最小值，我们将其拼接，拼接成了一个不完全有序的数组，在这个数组中我们需要找到 target ，找到后返回其索引，如果没有找到则返回 -1；

我们第一次看到这种题目时，可能会想到，我们只需要挨个遍历就好啦，发现后返回索引即可，这样做当然是可以滴，那么我们可不可以使用二分查找呢？

下面我们看一下解决该题的具体思路。

首先我们设想一下 **mid 值会落到哪里**，我们一起来想一下。

是不是只有两种情况，和 left 在一个数组，同时落在 数组1 或同时在 数组2，或者不在一个数组， left 在数组1，mid 在数组2。想到这里咱们这个题目已经完成一半了。
![](./images/semi_ordered.png)


那么我们先来思考一下，？我们可以根据 nums[mid] 和 nums[left] 判断，是因为我们的 mid 一定是会落在 left 和 right 之间，那如果 nums[mid] >= nums[left] 时，说明他俩落在一个数组里了，如果 nums[mid] < nums[left] 时，说明他俩落在了不同的数组，此时left 在数组1 mid在数组2.

注：left 和 mid 落在同一数组时，不能是 left 在 数组2 ，mid 在 数组1 呢？因为咱们的 mid 是通过 left 和 right 的下标求得，所以应该在 left 和 right 中间

如果我们的 mid 和 left 在同一个数组内时？咱们的 target 会有几种情况呢？我们通过都落在 数组1 举例。
![](./images/semi_ordered_2.png)

无非也是两种情况，用我们上面的例子来说，

> 1. **落在 mid 的左边**，当前例子中 情况是落在 [4,7）区间内，即 4 <= target < 7 ，也就是 target >= nums[left] && target < nums[mid]，此时我们让 right = mid -1，让 left 和 right 都落到数组 1 中，下次查找我们就是在数组1中进行了，完全有序，

2. **落在 mid 的右边**，此时例子中 target 不落在 [4,7）区间内，那就 target = 8 或 0 <= target <= 2 （此时我们的 target 均小于 nums[left]） 两种情况，也就是target > nums[mid] || target < nums[left] 此时我们让 left = mid + 1即可，也是为了慢慢将left 和 right 指针赶到一个有序数组内。

那我们在来思考一下当 mid 值落在 数组2 中时，target 会有几种情况呢？其实和上面的例子思路一致，情况相反而已。
![](./images/semi_ordered_3.png)


`target <= nums[right] && target > nums[mid]`

1. **落在右半部分**
这里和上面的对应，此时的情况就是整个落在**右半部分**，我们下次就可以在数组2内进行查找。

`target > nums[right] || target < nums[mid]`

2. **落在左半部分**
这里就是和上面的第二种情况对应，落在 mid 的左半部分，我们尽量将两个指针赶到一起。

------------------------

## leetcode33 搜索旋转排序数组

目描述
给你一个整数数组 nums ，和一个整数 target 。

该整数数组原本是按升序排列，但输入时在预先未知的某个点上进行了旋转。（例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] ）。

请你在数组中搜索 target ，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。

示例 1：

输入：nums = [4,5,6,7,0,1,2], target = 0
输出：4

示例 2：

输入：nums = [4,5,6,7,0,1,2], target = 3
输出：-1

示例 3：

输入：nums = [1], target = 0
输出：-1

题目解析
这个题目的解答方法，咱们在上面已经有所描述，下面我们来看一下下面这个例子的代码执行过程吧.

输入 nums = [4,5,6,7,8,0,1,2] target = 8

下面我们看题目代码吧，如果还没有完全理解的同学，可以仔细阅读 `if` ，`else if` 里面的语句，还有注释，一定可以整透的。

###　题目代码
```cpp
class Solution {
    public int search(int[] nums, int target) {
        //左右指针
        int left = 0;
        int right = nums.length - 1;
        while (left <= right) {
            int mid = left+((right-left)>>1);
            if (nums[mid] == target) {
                return mid;
            }
            //落在同一数组的情况，同时落在数组1 或 数组2
            if (nums[mid] >= nums[left]) {
                //target 落在 left 和 mid 之间，则移动我们的right，完全有序的一个区间内查找
                if (nums[mid] > target && target >= nums[left]) {
                       right = mid - 1;
                // target 落在right和 mid 之间，有可能在数组1， 也有可能在数组2
                } else if (target > nums[mid] || target < nums[left]) {
                       left = mid + 1;
                } 
            //不落在同一数组的情况，left 在数组1， mid 落在 数组2
            }else if (nums[mid] < nums[left]) {
                //有序的一段区间，target 在 mid 和 right 之间
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                // 两种情况，target 在left 和 mid 之间
                } else if (target < nums[mid] || target > nums[right]) {
                    right = mid - 1;
                }
            } 
        }
        //没有查找到
```

------------------------

### 查找不完全有序的数组中目标元素（含重复元素）
我们通过刚才的例子了解了，如果在**不完全有序的数组**中查找目标元素，但是我们的不完全有序数组中是不包含重复元素的，那如果我们的数组中包含重复元素我们应该怎么做呢？见下图
![](./images/semi_order_find_object_1.png)
如上图，如果我们继续使用刚才的代码，则会报错这是为什么呢?我们来分析一下。
[](./images/semi_order_find_object_2.png)
所以我们需要对其进行改进，我们只需将重复元素去掉即可，当我们的 `nums[left] == nums[mid]` 时，让 `left ++` 即可，比如 `1，3，1，1，1`此时 `nums[mid] == nums[left]` 则 `left ++`,那我们此时会不会错过目标值呢？其实并不会，只是去掉了某些重复元素，如果此时我们的目标元素是3，则我们`left++`，之后情况就变为了上题中的情况。

------------------------

## leetcode81. 搜索旋转排序数组 II
题目描述
假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,0,1,2,2,5,6] 可能变为 [2,5,6,0,0,1,2] )。

编写一个函数来判断给定的目标值是否存在于数组中。若存在返回 true，否则返回 false。

示例 1：

输入：nums = [2,5,6,0,0,1,2], target = 0 输出：true

示例 2：

输入：nums = [2,5,6,0,0,1,2], target = 3 输出：false

题目解析

**这个题目就比刚才的不含重复元素的题目多了一个去除某些重复元素的情况**，当 `nums[mid] == nums[left]` 时，让`left++`，并退出本次循环，其余部分完全相同，大家可以结合代码和图片进行理解。

```cpp
class Solution {
    public: 
    bool search (vector<int> &nums, int target)
    {
        int left = 0, right = nums.size()-1;
        while (left<=right)
        {
            int mid  = left + ((right-left)>>1);
            if (nums[mid]==target)
            {
                return true;
            }
            if (nums[mid]==nums[left])
            {
                // 当 nums[mid] == nums[left] 时，让 left++，并退出本次循环，其余部分完全相同
                left ++;
                continue;
            }
            if (nums[mid]>nums[left])
            {
                if (nums[mid]>target && target>=nums[left])
                {
                    right = mid -1;
                }else if (nums[mid]<target || target<nums[left])
                {
                    left = mid + 1;
                }
            }else if (nums[mid]<nums[left])
            {
                if (nums[mid]<target && target<=nums[right])
                {
                    left = mid+1;
                }else if (nums[mid]>target || nums[right]<target)
                {
                    right = mid -1;
                }
            }
        }
        return false;
    }
};
```

------------------------

### 寻找最小值
这种情况也很容易处理，和咱们的leetcode33搜索旋转排序数组，题目类似，只不过一个需要搜索目标元素，一个搜索最小值，我们搜索目标元素很容易处理，但是我们搜索最小值应该怎么整呢？见下图
![](./images/minimum.jpg)

我们需要在一个旋转数组中，查找其中的最小值，如果我们数组是完全有序的很容易，我们只需要返回第一个元素即可，但是此时我们是旋转过的数组。

我们需要考虑以下情况
![](./images/minimum2.png)

我们见上图，我们需要考虑的情况是

>1. **数组完全有序 nums[left] < nums[right]，此时返回 nums[left] 即可**

>2. `left` 和 `mid` 在一个都在前半部分，单调递增区间内，所以需要移动 `left`，继续查找，`left = mid + 1`；

>3. `left` 在前半部分，`mid`在后半部分，**则最小值必在 left 和 mid 之间**（见下图）。则需要移动right ，`right = mid`，我们见上图，如果我们 `right = mid - 1`，则会漏掉我们的最小值，因为此时 `mid` 指向的可能就是我们的最小值。所以应该是 `right = mid` 。
![](./images/minimum3.png)

------------------------

### leetcode 153 寻找旋转数组中的最小值
## 题目描述

假设按照升序排序的数组在预先未知的某个点上进行了旋转。例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] 。

请找出其中最小的元素。

示例 1：

输入：nums = [3,4,5,1,2]输出：1

示例 2：

输入：nums = [4,5,6,7,0,1,2] 输出：0

示例 3：

输入：nums = [1] 输出:1

题目解析
我们在上面的描述中已经和大家分析过几种情况，下面我们一起来看一下，[5,6,7,0,1,2,3]的执行过程，相信通过这个例子，大家就能把这个题目整透了。
![](./images/minimum4.png)

```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size()==1) return nums[0];
        int left = 0, right = nums.size() - 1;
        while (left<=right)
        {

            // 单调递增时直接返回
            if(nums[left]<=nums[right])
            {
                return nums[left];
            }
            int mid = left + (right-left)/2;
            // mid 和 left 之间单调递增,说明必然不在这里
            if(nums[mid]>=nums[left])
            {
                left= mid+1;
            } else if(nums[mid]<nums[left])
            {
                right = mid;
            }
        }
        return -1;
    }
};
```

------------------------

### 二维数组

下面我们来看一下另外一种变体，如何在二维矩阵里使用二分查找呢？

其实这个很简单，只要学会了二分查找，这个完全可以解决，我们先来看一个例子

我们需要从一个二维矩阵中，搜索是否含有元素 7，我们如何使用二分查找呢？其实我们可以完全将二维矩阵想象成一个有序的一维数组，然后用二分，，比如我们的二维矩阵中，共有 9 个元素，那定义我们的 `left = 0`，`right = 9 - 1= 8`，是不是和一维数组定义相同，然后我们求我们的 mid 值， `mid = left +（(right - left) >> 1）`此时 `mid = 4` ，但是我们的二维矩阵下标最大是，`nums[2,2]`呀，你这求了一个 `4` ，让我们怎么整呀。如果我们理解了二分查找，那么这个题目考察我们的应该是如何将一维数组的下标，变为 二维坐标。其实也很简单，咱们看哈，此时咱们的 `mid = 4`，咱们的二维矩阵共有 `3行`， `3列`，那我们 `mid =4`，肯定在第二行，那么这个应该怎么求得呢?

我们可以直接用 `（mid/列数）`，即可，因为我们 `mid = 4`，`4 /3` = 1,说明在 在第二行，那如果 mid = 7 ，7/3=2，在第三行，我们第几行知道了，那么我们如何知道第几列呢？我们可以直接根据 （`mid % 列数` ）来求得呀，比如我们此时 mid = 7，7%3 = 1，那么在我们一维数组索引为 7 的元素，其处于二维数组的第2列，大家看看下图是不是呀
![](./images/2darr_binary_search.png)
 

------------------------

### Leetcode 74 搜索二维矩阵

题目描述
编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：

每行中的整数从左到右按升序排列。
每行的第一个整数大于前一行的最后一个整数。

示例1

输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,50]], target = 3
输出：true

示例2

输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,50]], target = 13
输出：false

示例3

输入：matrix = [], target = 0
输出：false

题目解析
在上面我们已经解释了如何在二维矩阵中进行搜索，这里我们再对其进行一个总结，就是我们凭空想象一个一维数组，这个数组是有二维数组一层一层拼接来的，也是完全有序，然后我们定义两个指针一个指向一维数组头部，一个指向尾部，我们求得 mid 值然后将 mid 变成二维坐标，然后和 target 进行比较，如果大于则移动 left ，如果小于则移动 right 。
```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int row = matrix.size();
        int col = matrix[0].size();
        int left = 0, right = row*col -1;
        while (left<=right)
        {
            int mid = left + (right -left)/2;
            int i = mid/col, j = mid%col;
            if(matrix[i][j]==target) return true;
            if(matrix[i][j]>target){
                right = mid -1; 
            } else if (matrix[i][j]<target){
                left = mid +1;
            }
        }
        return false;
    }
};
```






