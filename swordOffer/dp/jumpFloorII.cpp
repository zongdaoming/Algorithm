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
    int jumpFloorII(int number) {
        vector<int> f(number+1);
        f[0]= 1;
        f[1] = 1;
        f[2] = 2;
        f[3] = 4;
        int sum =0;
        for(int i=1; i<=number;i++)
        {
            f[i] = f[i-1]+sum; 
            sum+=f[i-1];
        }
        
        return f[number];

    }
};


