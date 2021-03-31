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
class Solution
{   
    public:
    int max = 10000000;
    int numSquares(int n)
    {
        // define dp vector
        vector<int> dp(n+1,max);
        dp[0]=0;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j*j<=i; j++)
            {
                dp[i]=min(dp[i],dp[i-j*j]+1);
            }
        }
        return dp[n];
    }
};  