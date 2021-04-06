# 滑动窗口

## 什么是滑动窗口？

顾名思义，首先是一个窗口，既然是一个窗口，就需要用窗口的左边界`i`和右边界`j`来唯一表示一个窗口，其次，滑动代表，窗口始终从左往右移动，这也表明左边界`i`和右边界`j`**始终会往后移动**，而不会**往左移动**。 这里我用左闭右开区间来表示一个窗口。比如

![](./images/sliding_window.png)


滑动窗口的操作(基于while的)

> 扩大窗口，`j += 1`
> 缩小窗口，`i += 1`
* 算法步骤：

1. 初始化，`i=1`,`j=1`, 表示窗口大小为0
2. 如果窗口中值的和小于目标值`sum`， 表示需要扩大窗口，`j+=1`
3. 否则，如果窗口值和大于目标值`sum`，表示需要缩小窗口，`i+=1`
4. 否则，等于目标值，存结果，缩小窗口，继续进行步骤2,3,4

这里需要注意1个问题：
什么时候窗口终止呢，这里窗口左边界走到sum的一半即可终止，因为题目要求至少包含2个数

```cpp
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> ret;
        int l = 1, r = 1;
        int tmp = 0;
        while (l <= sum / 2) {
            if (tmp < sum) {
                tmp += r;
                ++r;
            }
            else if (tmp > sum) {
                tmp -= l;
                ++l;
            }
            else {
                vector<int> ans;
                for (int k=l; k<r; ++k)
                    ans.push_back(k);
                ret.push_back(ans);
                tmp -= l;
                ++l;
            }
        }
        return ret;
    }
};
```

