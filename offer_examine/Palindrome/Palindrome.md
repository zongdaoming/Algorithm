# 1，中心扩散法
中心扩散法也很好理解，我们遍历字符串的每一个字符，然后以当前字符为中心往两边扩散，查找最长的回文子串，下面随便举个例子，看一下
![](../images/center_exploration.png)

图片中我们是以每一个字符为中心，往两边扩散，来求最长的回文子串。但忽略了一个问题，回文串的长度不一定都是奇数，也可能是偶数，比如字符串"abba"，如果使用上面的方式判断肯定是不对的。

我们来思考这样一个问题，如果是单个字符，我们可以认为他是回文子串，如果是**多个字符，并且他们都是相同的，那么他们也是回文串**。

所以对于上面的问题，我们以当前字符为中心往两边扩散的时候，先要判断和他挨着的有没有相同的字符，如果有，则直接跳过，来看下代码

```cpp
class Solution {
public:
    int getLongestPalindrome(string str, int n) {
        if(n<2)
        {
            return str.size();
        }
        int maxLen = 0;
        for(int i =0; i<n;)
        {
            //如果剩余子串长度小于目前查找到的最长回文子串的长度，直接终止循环
            // （因为即使他是回文子串，也不是最长的，所以直接终止循环，不再判断）
            if(n-i<= maxLen/2)
            {
                break;
            }
            int left =i;
            int right = i;
            while(right<n-1 && str[right]==str[right+1])
            {
                ++right;
            }
            //下次在判断的时候从重复的下一个字符开始判断
            i=right+1;
            // 然后往两边判断，
            while(right<n-1 && left>0 && str[right+1]==str[left-1])
            {
                ++right;
                --left;
            }
            // 保留最长的
            maxLen = (maxLen, right - left + 1 );
        }
        // 截取回文串
        return maxLen;
        
    }
};
```

# 动态规划
定义二维数组`dp[length][length]`，如果`dp[left][right]`为`true`，则表示字符串从`left`到`right`是回文子串，如果`dp[left][right]`为`false`，则表示字符串从`left`到`right`不是回文子串。


如果`dp[left+1][right-1]`为`true`，我们判断`str[left]`和`str[right]`是否相等，如果相等，那么`dp[left][right]`肯定也是回文子串，否则`dp[left][right]`一定不是回文子串。

有了递推公式，还要确定边界条件：

1. 如果`left==right`，也就是说只有一个字符，我们认为他是回文子串。即`dp[left][right]=true（left==right）`

2. 如果`right-left<=2`，类似于"aa"，或者"aba"，我们认为他是回文子串。即`dp[left][right]=true（right-left<=2）`

3. 如果`right-left>2`，我们只需要判断`dp[left+1][right-1]`是否是回文子串，才能确定`dp[left][right]`是否为true还是false。即`dp[left][right]=dp[left+1][right-1]`

有了递推公式和边界条件，代码就很容易写了，来看下

```cpp
class Solution {
public:
    int getLongestPalindrome(string s, int n) {
        int len = s.size();
        if(len<2)
        {
            return s.length();
        }
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        int maxLen = 1;
        for(int right = 1; right<len; right++){ 
            for(int left = 0; left<right; left++){                           
                if(s[left]!=s[right])
                {
                    continue;
                }
                //如果只有一个字符，肯定是回文子串
                if(left==right)
                {
                    dp[left][right] = true;
                //类似于"aa"和"aba"，也是回文子串
                }else if(right-left<=2)
                {
                    dp[left][right] = true;
                }else{
                //类似于"a******a"，要判断他是否是回文子串，只需要
                //判断"******"是否是回文子串即可                    
                    dp[left][right]=dp[left+1][right-1];
                }
                //如果字符串从left到right是回文子串，只需要保存最长的即可                
                if(dp[left][right] && right-left+1 >maxLen)
                {
                    maxLen = right-left + 1;    
                }
            }
        }
        return maxLen;
    }
};
```


