#include <iostream>
#include <string>
#include <cstdio>
#include <numeric>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 贪心算法的直觉：由于不限制交易次数，只要今天股价比昨天高，就交易。
        // 贪心算法 在每一步总是做出在当前看来最好的选择。
        // 该算法仅可以用于计算，但 计算的过程并不是真正交易的过程，
        // 但可以用贪心算法计算题目要求的最大利润。下面说明等价性：以 [1, 2, 3, 4] 为例，这 4 天的股价依次上升，按照贪心算法，得到的最大利润是：
      int ans = 0;
      for (int i=1; i < prices.size(); i++){
          ans+= max(0, prices[i]-prices[i-1]);
      }
      return ans;
    }
    // dp
    int maxProfitsDP(vector<int> & prices)
    {
         int n = prices.size();
         int dp[n][2];
         dp[0][0] = 0, dp[0][1] = -prices[0];
         for (int i=1; i< prices.size(); i++)
         {
             dp[i][0] = max(dp[i-1][0],dp[i-1][1]+prices[i]);
             dp[i][1] = max(dp[i-1][1],dp[i-1][0]-prices[i]);
         }
         return dp[n-1][0];
    }

//  滚动数组* 滚动变量
    int maxProfits(vector<int> & prices)
    {
        int n = prices.size();
        int dp0 = 0, dp1 =  -prices[0];
        for(int i=1; i<n; ++i)
        {
          int newDp0 = max(dp0, dp1+prices[i]);
          int newDp1 = max(dp1, dp0-prices[i]);
          dp0 = newDp0;
          dp1 = newDp1;
        }
        return dp0;
    }
};

int main()
{
    vector<int> prices(6);
    Solution solution;
    cout<<"Please input stock prices"<<endl;
    // for(int i=0; i< prices.size(); i++)
    // {
    //     cin>>prices[i];
    // }
    prices[0] = 7;
    prices[1] = 1;
    prices[2] = 5;
    prices[3] = 3;
    prices[4] = 6;
    prices[5] = 4;

    cout<<"Max profits is "<<solution.maxProfit(prices)<<endl;
    system("pause");
    return 0;
}



// 贪心算法 在每一步总是做出在当前看来最好的选择。
/***
「贪心算法」 和 「动态规划」、「回溯搜索」 算法一样，完成一件事情，是 分步决策 的；
「贪心算法」 在每一步总是做出在当前看来最好的选择，我是这样理解 「最好」 这两个字的意思：
「最好」 的意思往往根据题目而来，可能是 「最小」，也可能是 「最大」；
贪心算法和动态规划相比，它既不看前面（也就是说它不需要从前面的状态转移过来），
也不看后面（无后效性，后面的选择不会对前面的选择有影响），
因此贪心算法时间复杂度一般是线性的，空间复杂度是常数级别的；
***/