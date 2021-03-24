#include <iostream>
#include <string>
#include <cstdio>
#include <numeric>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;


// 双指针+贪心
class Solution {
public:
    bool judgePalindrome(int low, int high, const string &s)
    {
       while(low<high){
           if (s[low]!=s[high])
           {
               return false;
           }
           low++;
           high--;
       }
       return true;
   }

    bool validPalindrome(string s) 
    {
    // 初始化双指针 
    // initialize two pointer
    int low=0, high=s.size()-1;
    while(low<high)
    {
        if(s[low]!=s[high])
        {
        //  贪心策略
        // 已经相等的局部最优无需再继续考虑了；即回文串的外延，只需要考虑剩下的局部最优，即保证删除后余下的字符串是回文串即可
        return judgePalindrome(low+1,high,s) || judgePalindrome(low,high-1,s);
        }
        low++;
        high--;
    }
    return true;
    }
};
