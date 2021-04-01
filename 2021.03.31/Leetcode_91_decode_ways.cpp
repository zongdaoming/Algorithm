#include <iostream>
#include <string>
#include <cstdio>
#include <numeric>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;



class Solution {
    // 状态定义：若前 i 个字符可以解码，dp(i) 表示前 i 个字符可以解码的方法数。
    // dp[i-1]表示当前字符单独解码的解数
    // dp[i-2]表示当前字符与前一位结合解码的解数
   public:
    int numDecodings(string s) {
        int n = s.size();
        if(s[0]=='0') return 0;
        vector<int> dp(n,0);
        dp[0] = 1;
        for(int i=1;i<n;i++)
        {
            if(s[i]=='0')
            {
                if(s[i-1]=='1' || s[i-1]=='2')
                {
                       if(i==1)
                       {
                           dp[i]=1;
                       }
                       else
                       {
                        // 当前字符只能与前一位结合进行解码
                           dp[i]=dp[i-2];
                       }                                
                }
                else
                {
                    return 0;
                }  
            }
            else
            {
                int value = 10*(s[i-1]-'0')+(s[i]-'0');
                if(value>=11 && value<=26)
                {
                    if(i==1){
                        dp[i]=dp[0]+1;
                    }
                    else{
                        dp[i] = dp[i-1] + dp[i-2];
                    }
                }
                else{
                    dp[i] = dp[i-1];
                }
            }

        }
        return dp[n-1];
    }
};