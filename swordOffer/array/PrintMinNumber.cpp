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
    string PrintMinNumber(vector<int> numbers) {
        
        vector<string> str;
        for(int val: numbers) str.push_back(to_string(val));
        sort(str.begin(),str.end(),[](string a, string b)
        {
            return a + b < b+a;
        });
        string ret = "";
        for(string s: str) ret+=s;
        return ret;
    }
};

class Solution
{
    public:
  
    static bool cmp(string &a, string &b)
    {
        return a+b < b+a;
    }
    string PrintMinNumber(vector<int> numbers)
    {
        vector<string> str;
        for(int val: numbers) str.push_back(to_string(val));
        sort(str.begin(), str.end(),cmp);
        string ret = "";
        for(string s:str) ret+=s;
        return ret;
    }
};


// 显然方法一出现了太多无关的排列，我们需要一个最小的数，细想一下可知，如果有两个字符串a,b，
// 如果a + b < b + a, 显然我们希望a排在b的前面，因为a排在前面可以使结果更小。
// 于是我们就自定义排序规则，使得vector中字符串都满足如上规则，那么最后的结果肯定是最小的。


// 结构体实现 仿函数

class Solution
{
    public:
    struct Com {
        bool operator() (string a, string b) {
        return a + b < b + a;
        }
    };
    string PrintMinNumber(vector<int> numbers)
    {
        vector<string> str;
        for(int val:numbers) str.push_back(to_string(val)); 
        sort(str.begin(), str.end(), Com()); // Com()为临时对象
        string ret = "";
        for(string s: str) ret += s;
        return ret;
    }
};

// lambda表达式
class Solution
{
    public:
    string PrintMinNumber(vector<int> numbers)
    {
        vector<string> str;
        for(int val: numbers) str.push_back(to_string(val));
        // 1. 匿名lambda表达式
        sort(str.begin(), str.end(),[](string a, string b){return a+b<b+a;});
        string ret = "";
        for(string s:str) ret+=s;
        return ret;
    }
};

// lambda表达式
class Solution
{
    public:
    string PrintMinNumber(vector<int> numbers)
    {
        vector<string> str;
        for(int val: numbers) str.push_back(to_string(val));
        // 1. 具名lambda表达式
        auto lam = [](string a, string b){return a+b<b+a;};
        sort(str.begin(), str.end(),lam);
        string ret = "";
        for(string s:str) ret+=s;
        return ret;
    }
};


