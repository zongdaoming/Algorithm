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

class Solution{
    public:
    int minSteps(int n)
    {
        vector<int> dp(n+1);
        // initialization 
        int h = n/2;
        for(int i = 2; i<=n; ++i)
        {
            dp[i] = i;
            for(int j = 2; j <= h; ++j)
            {
                if(i % j == 0)
                {
                    // view as a whole
                    dp[i] = dp[j] + dp[i/j];
                    break;
                }
            }
        }
        return dp[n];
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;
    int n = 4;
    int ans = sol.minSteps(n);
    system("pause");
    return 0;
}
