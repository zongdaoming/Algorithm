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
    int jumpFloor(int number) {
        vector<int> dp(number+1,0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i=2; i<=number; i++)
        {
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[number];
    }
};

int Fibonacci(int n) {
    if (n<=1) return 1;
    return Fibonacci(n-1) + Fibonacci(n-2);
}


class Solution {
public:
    int Fib(int n, vector<int>& dp) {
        if (n<=1) return 1;
        if (dp[n] != -1) return dp[n];
        return dp[n] = Fib(n-1,dp) + Fib(n-2,dp);
    }
    int jumpFloor(int n) {
        vector<int> dp(45, -1); // 因为答案都是>=0 的， 所以初始为-1，表示没计算过
        return Fib(n, dp);
     }
};


int Fibonacci(int n) {
    vector<int> dp(n+1, 0);
        dp[0] = dp[1] = 1;
        for (int i=2; i<=n; ++i) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
}


int Fibonacci(int n) {
     if (n == 0 || n == 1) return n;
        int a = 1, b = 1, c;
        for (int i=2; i<=n; ++i) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
}

// 时间复杂度：O（n）
// 空间复杂度：O（1）