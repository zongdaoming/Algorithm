 # 一和零【01背包】详解


 这道题目，还是比较难的，也有点像程序员自己给自己出个脑筋急转弯，程序员何苦为难程序员呢哈哈。

来说题，本题不少同学会认为是多重背包，一些题解也是这么写的。

其实本题并不是多重背包，再来看一下这个图，捋清几种背包的关系

**多重背包是每个物品，数量不同的情况**。

**本题中strs 数组里的元素就是物品，每个物品都是一个！**

而`m` 和`n`相当于是一个背包，两个维度的背包。

理解成多重背包的同学主要是把m和n混淆为物品了，感觉这是不同数量的物品，所以以为是多重背包。

但本题其实是01背包问题！


这不过这个背包有两个维度，一个是`m` 一个是`n`，而不同长度的字符串就是不同大小的待装物品。

开始**动规五部曲**：

* 1.确定dp数组（dp table）以及下标的含义

**`dp[i][j]`：最多有`i`个0和`j`个1的strs的最大子集的大小为`dp[i][j]`**

* 2.确定递推公式

dp[i][j] 可以由前一个strs里的字符串推导出来，strs里的字符串有zeroNum个0，oneNum个1。

dp[i][j] 就可以是 dp[i - zeroNum][j - oneNum] + 1。

然后我们在遍历的过程中，取dp[i][j]的最大值。

所以递推公式：`dp[i][j] = max(dp[i][j], dp[i - zeroNum][j - oneNum] + 1)`;

此时大家可以回想一下01背包的递推公式：`dp[j] = max(dp[j], dp[j - weight[i]] + value[i])`;

对比一下就会发现，字符串的`zeroNum`和`oneNum`相当于物品的重量（`weight[i]`），字符串本身的个数相当于物品的价值（`value[i]`）。

* 3.dp数组如何初始化

因为物品价值不会是负数，初始为0，保证递推的时候dp[i][j]不会被初始值覆盖。

* 4.确定遍历顺序
`01背包`为什么一定是外层for循环遍历**物品**，内层for循环遍历**背包容量**且**从后向前遍历**！
```cpp
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        dp[0][0] = 0;
        for (string str : strs) { // 遍历物品
        int oneNum = 0, zeroNum = 0;
        for (char c : str) {
        if (c == '0') zeroNum++;
            else oneNum++;
        }
        for (int i = m; i >= zeroNum; i--) { // 遍历背包容量且从后向前遍历！
            for (int j = n; j >= oneNum; j--) {
                dp[i][j] = max(dp[i][j], dp[i - zeroNum][j - oneNum] + 1);
                }
            }
        }
        return dp[m][n];
    }
};
```

有同学可能想，那个遍历背包容量的两层for循环先后循序有没有什么讲究？

没讲究，都是物品重量的一个维度，先遍历那个都行！
