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
    vector<int> partitionLabels(string S) {
        vector<int> result;
        map <char, int> map_revert; //记录char c 和其最后出现位置的map
        int start = 0, end = 0;
        // 从左到右遍历字符串，遍历的同时维护当前片段的开始下标 start 和结束下标 end，初始时 start=end=0
        for(int i=0; i < S.size(); ++i)
        {
             map_revert[S[i]] = i; //遍历字符串，得到每个字母最后一次出现的下标位置
        }

        for(int i=0; i < S.size(); ++i)
        {   
            // 对于每个访问到的字母 cc，得到当前字母的最后一次出现的下标位置 \textit{end}_c, 则当前片段的结束下表一定不会小于end_{c}, 因此令 end = max(end, end_{c}) 
            end = max(end, map_revert[S[i]]);
            if (i==end)
            {
                result.push_back(end-start+1);
                start = i+1;
            }
        }
        return result;
    }
};