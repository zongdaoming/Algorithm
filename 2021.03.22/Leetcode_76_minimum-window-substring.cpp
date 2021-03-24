#include <iostream>
#include <string>
#include <cstdio>
#include <numeric>
#include <vector>
#include <unordered_map >
#include <algorithm>
using namespace std;

// 哈希+滑动窗口(双指针)

class Solution {
public:
    
    unordered_map <char, int> tFreq, winFreq;
    string minWindow(string s, string t) {  
        //统计目标字符t中字符出现的个数
        for (const auto &c: t) 
        {
            tFreq[c]++;
        }
        // 声明一些变量:滑动窗口内部包含了多少T中的字符,对应字符频数不重复计算
        int distance = 0; 
        int slen = s.size(), tlen =t.size();
        int minLen = slen+1; //初始化为一个不可能达到的数 
        int begin = 0;
        int left = 0, right = 0;
        // [left, right) 左边右开
        while(right<slen) 
        {
          if(tFreq.find(s[right])==tFreq.end())
          {
          //   如果右边界的元素不在t里面出现,这继续向右移动
              right++;
              continue;
          }
        //  维护Distance的逻辑
          if(winFreq[s[right]]< tFreq[s[right]])
          {
              distance++;
          }
        // 滑动窗口的的字符统计个数
          winFreq[s[right]]++;
          right++;

          while(distance == tlen){
              
             minLen = min(minLen, right-left);
             begin=left;

              if(tFreq.find(s[left])==tFreq.end())
              {
                  //   如果左边界的元素不在t里面出现,这继续向右移动
                  left++;
                  continue;
              }
             //  维护Distance的逻辑
              if(winFreq[s[left]]==tFreq[s[left]])
              {
                  distance--;
              }
            //   滑动窗口的字符统计个数
            winFreq[s[left]]--;
            left++;

          }
        }
         return minLen==slen+1?"":s.substr(begin,begin+minLen);
    }
};

int main(int argc, char const *argv[])
{
    string  str="abcdefgacd", target = "ad";
    Solution solution;
    cout<<solution.minWindow(str,target).c_str()<<endl;
    system("pause");
    return 0;
}
