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

// 思路：转移方程可以这样写   dp[i][j]= dp[i-1][j]{表示第i-1个字符串替换第j个字符串所需的最小步数}
// dp[i][j-1] {表示第i个字符串替换第j个字符串所需的最小步数}
// dp[i-1][j-1]{分两种情况:当前的单词相同和当前的单词不相同， 如果相同：则不需要操作 如果不相同则需要删除两次}
// Note that 当前的单词是 word[i-1][j-1] 和 dp 数组访问位置的区别
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        vector<vector<int>> dp(len1+1, vector<int>(len2+1,0));
        // initlization dp 
        for(int i = 0 ; i< dp.size(); i++)
        {
            dp[i][0] = i;
        }

        for(int j = 0 ; j< dp[0].size(); j++)
        {
            dp[0][j] = j;
        }

        for(int i = 1; i<dp.size(); i++)
        {
            for(int j = 1; j<dp[0].size(); j++)
            {
                dp[i][j] = min(dp[i-1][j-1]+2, min(dp[i-1][j]+1, dp[i][j-1]+1));
                if(word1[i-1]==word2[j-1])
                {
                    dp[i][j]= min(dp[i][j], dp[i-1][j-1]);
                }
            }
        }
        return dp.back().back();
    }
};


int main(int argc, char const *argv[])
{
    
    return 0;
}
