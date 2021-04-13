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

class Solution {
public:
    int getLongestPalindrome(string str, int n) {
        if(n<2)
        {
            return str.size();
        }
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int maxLen = 1;
        for(int right = 1; right<n; right++){
            for(int left = 0; left<n; left++){
                
                if(str[left]!=str[right]){
                    continue;
                }

                // 如果只有一个字符，肯定是回文串                
                if (right == left)
                {
                    dp[right][left] = true;
                }
                else if(right-left<=2)
                {
                    dp[left][right] = true;
                }
                else
                {
                  //类似于"a******a"，要判断他是否是回文子串，只需要
                  //判断"******"是否是回文子串即可
                  dp[left][right] = dp[left+1][right-1];
                }
                 //如果字符串从left到right是回文子串，只需要保存最长的即可
                 if(dp[left][right] && right-left+1>maxLen)
                 {
                     maxLen = right-left+1;
                 }
            }
    }
};

int main(int argc, char)
{
    Solution solu;
    string str = "abbbbbba";
    int maxLen = solu.getLongestPalindrome(str, str.size());
    return maxLen;
}