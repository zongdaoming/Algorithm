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
    static bool cmp(const vector<int> &a, const vector<int> &b)
    {
        return a[1]<b[1]; //升序排序;
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty())
        {
            return 0;
        }
        int size = points.size();
        sort(points.begin(), points.end(),cmp);
        int pre = points[0][1];
        int count = 1;
        for(int i=1; i<size; ++i)
        {
           if (points[i][0]>pre){
               ++count;
               pre = points[i][1];
           }
        }
        return count;
    }
};


