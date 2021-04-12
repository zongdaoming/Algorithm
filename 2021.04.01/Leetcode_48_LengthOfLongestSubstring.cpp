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
#include <unordered_set>

using namespace std;

class Solution {
public:
    /**
     * 
     * @param arr int整型vector the array
     * @return int整型
     */
//     [2,3,4,5]
    int maxLength(vector<int>& arr) {
        // write code here
        unordered_set<int> us;
        int n = arr.size();
        int ans = 0;
//        set.count() 返回值：该函数返回1或0，因为该集合仅包含唯一元素。如果设置的容器中存在该值，则返回1。如果容器中不存在它，则返回0。
        // define another pointer 定义一个右指针
        int j = 0;
        for(int i = 0; i< n; i++)
        {
            if(i!=0)
            {
                us.erase(arr[i-1]);
            }
            while( j<n && !us.count(arr[j]))
            {
                us.insert(arr[j]);
                j++;
            }          
            ans = max(ans, j-i);
        }
        return ans;
    }
};


// 算法 ：双指针+哈希
// tail 指针向末尾方向移动；
// 如果尾指针指向的元素存在于哈希表中：
// head 指针跳跃到重复字符的下一位；
// 更新哈希表和窗口长度。


// 复杂度分析
// 时间复杂度：O(n)，遍历了一遍 s，哈希表中查找的时间复杂度为 O(1)。
// 空间复杂度：O(n)，使用了哈希表。

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> m;
        
        int ret = 0, l = 0, r = 0;
        while (r < s.size()) {
            if (m.find(s[r]) != m.end()) {
                l = max(l, m[s[r]] + 1);
            }
            m[s[r++]] = r;
            ret = max(r - l, ret);
        }
        return ret;
    }
};



class Solution {
public:
    /**
     * 
     * @param arr int整型vector the array
     * @return int整型
     */
    int maxLength(vector<int>& arr) {
        // write code here
        int n = arr.size();
        int l = 0, r = 0, res = 0;
        unordered_map<int, int> cmap;
        while(r<n)
        {
            if(cmap.find(arr[r])!=cmap.end())
            {
                l = max(l, cmap[arr[r]]+1);
            }
            cmap[arr[r++]] = r;
            res = max(res, r-l);
        }
        return res;
    }
};