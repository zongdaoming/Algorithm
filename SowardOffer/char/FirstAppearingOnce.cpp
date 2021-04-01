#include <iostream>
#include <string>
#include <cstdio>
#include <numeric>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
#include <algorithm>
using namespace std;

class Solution
{
    public:

    // Insert one char from stringstream
    queue<char> Q;
    map<char,int> smap;
    void Insert(char ch) {
        // 如果是第一次出现， 则添加到队列中
        if(smap.find(ch)==smap.end())
        {
            Q.push(ch);
        }
        // 不管是不是第一次出现，都进行计数
        smap[ch]++;
    }
    // Return the first appearence once char in current stringstream
    char FirstAppearingOnce() {
        while(!Q.empty())
        {
            char ch = Q.front();
            // 拿出头部，如果是第一次出现，则返回
            if (smap[ch]==1)
            {
                return ch;
            }
             //如果不是第一次出现,才让这个字符弹出来啊
            //不是第一次出现,则弹出,然后继续判断下一个头部
            else
            {
                Q.pop();
            }
        }
        return '#';
    }
};