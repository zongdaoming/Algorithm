归并排序的套路，按照下面套路来就完事了。
思路:

1. 双指针从A和B的m、n尾部遍历

2. 比较A和B的m、n尾部的值，将较大值赋给A整体数组的尾部，指针左移
 
3. 注意特殊情况处理：A的尾指针已遍历结束，B尾指针还未结束。

<!-- 归并排序的套路 -->
```cpp
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int  i = m-1;
        int  j = n-1;
        int index = m + n -1; //AB合并后最后一个元素所在位置
        while(i>=0 && j>=0)
        {
            A[index--]  = A[i]>B[i]?A[i--]:B[j--];
        }
        //如果A没有遍历完,已经井然有序了 这和链表直接相连的道理是一样的
        while(j>=0)
        {
            //如果B没有遍历完，那么丢在A数组的前面
            A[index--] = B[index--];
        }
    }
};
```