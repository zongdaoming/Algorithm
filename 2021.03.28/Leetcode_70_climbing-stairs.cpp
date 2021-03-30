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
public:
    int stair(int  n)
    {
        if (n==1)
        {
            return 1;
        }
        if(n==2)
        {
            return 2;
        }
        return stair(n-2)+stair(n-1);
    }

    int climbStairs(int n) {
        int ans = 0;
         ans = stair(n);
         return ans;
    }
};

class SolutionFor {
public:
    int climbStairs(int n) {
        if(n==2) return n;
        vector<int> dp(n+1,1);
        for(int i = 2; i<=n; i++)
        {
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};

class SolutionIteration{
public:
    int climbStairs(int n) {
        if(n<=2) return n;
        vector<int> dp(n+1,1);
        int pre2 =1, pre1 =2, cur; 
        for(int i = 2; i<n; i++)
        {
            cur = pre1+pre2;
            pre2 = pre1;
            pre1 =cur;
        }
        return cur;
    }
};


int main(int argc, char const *argv[])
{
    
    return 0;
}
