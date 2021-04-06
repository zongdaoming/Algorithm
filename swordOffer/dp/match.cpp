#include <iostream>
#include <string>
#include <cstdio>
#include <numeric>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
#include <algorithm>
using namespace std;


// 使用动态规划求解：
// 1.开辟一个二维数组 dp[i][j]来存放
// 模式串的前j个元素与字符串的前i个元素是否匹配 
// 初始化dp[0][0]为true（表示两个空串是匹配的）

// 2.如果第j个元素不是 那么采用正常的匹配方式即模式串的第j个元素与字符串的第i个元素一样，
// 或者模式串的第j个元素是‘.’,dp[i][j]=dp[i-1][j-1]

// 3.如果第j个元素是，那么分两种情况有一种情况为true即可
// 第一种将（）和前面那个元素视为空串（这时号代表出现0次）那么dp[i][j-2]==true即表示匹配成功 dp[i][j] = dp[i][j-2] 
// 第二种 dp[i][j-2]！=true 那么就得是得第i个元素与第j-1个元素相等（此时代表的是出现1次）或者第j-1个元素是‘.’ 并且dp[i-1][j]=true即可



class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param str string字符串 
     * @param pattern string字符串 
     * @return bool布尔型
     */
    bool match(string str, string pattern) {
        // write code here
            
        
        
    }
};

