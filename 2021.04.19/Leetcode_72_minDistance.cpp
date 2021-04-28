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
    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();

        vector<vector<int>> dp(len1+1,vector<int>(len2+1,0));
        
        // dp initialization
        for (int i=0; i<dp.size(); i++)
        {
            dp[i][0] = i;
        }
        // dp initialization
        for(int j=0; j<dp[0].size(); j++)
        {
            dp[0][j]= j;
        }
        for(int i =1; i<dp.size(); i++)
        {
            for(int j =1; j<dp[0].size(); j++)
            {
                dp[i][j] =  min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]))+1;
                if(word1[i-1] == word2[j-1])
                {
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
                }
            }
        }
        return dp.back().back();
    }
};