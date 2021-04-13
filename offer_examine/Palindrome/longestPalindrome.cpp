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
    int longestPalindrome(string s){
        unordered_map<char, int> count;
        int ans = 0;
        for(char c: s)
        {
            count[c]++;
        }
        for(auto p: count)
        {
            int v = p.second;
            ans+= v/2*2;
            if(v%2==1 && ans%2 == 0)
            {
                ++ans;
            }
        }
        return ans;
    }
};