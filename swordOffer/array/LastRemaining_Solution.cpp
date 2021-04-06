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
    int LastRemain_Solution(int n, int m)
    {
        if(n<=0) return -1;
        vector<int> lt;
        for(int i = 0; i<n; i++){
            lt.push_back(i);
        }
        int index = 0;
        while(n>1)
        {
            index = (index+m-1)%n;
            // auto it = it.begin();
            vector<int>::iterator it = lt.begin();
            // std::advance(it,index);
            it = it + index;
            lt.erase(it);
            --n;
        }
        return lt.back();
    }
};

