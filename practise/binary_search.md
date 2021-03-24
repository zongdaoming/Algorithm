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

查找元素第一个位置和最后一个位置
上面我们说了如何使用二分查找在数组或区间里查出特定值的索引位置。但是我们刚才数组里面都没有重复值，查到返回即可，那么我们思考一下下面这种情况




