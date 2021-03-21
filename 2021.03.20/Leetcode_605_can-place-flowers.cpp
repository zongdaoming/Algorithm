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
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        // 贪心, 当前位置能种花，就种花
        int ans = 0;
        for (int i=0; i< flowerbed.size(); i++) 
        {
            if (flowerbed[i]==0 && (i+1==flowerbed.size() || flowerbed[i+1]==0) && (i==0 || flowerbed[i-1]==0))
            {
                flowerbed[i]=1;
                ans++;
            }  
        }
        return ans >= n;
    }
};