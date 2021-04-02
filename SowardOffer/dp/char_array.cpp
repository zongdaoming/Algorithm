#include <iostream>
#include <string>
#include <cstdio>
#include <numeric>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

// 字符串也需要用到 push_back 和 pop_back; 回溯基本要用到push_back 和 pop_back;
class Solution {
public:
    void dfs(string &str, vector<string> &ans, string &res, vector<bool> &visited, int pos)
    {
        if(pos==str.size())
        {
            ans.push_back(res);
            return;
        }
        for(int i=0; i<str.size(); i++)
        {
            // 如果没有被访问过，且添加的不是左边第一个除了没被访问过之外的值
            if(visited[i] || (i>0 && str[i]==str[i-1] && !visited[i-1]))
            {
                continue;
            }
            res.push_back(str[i]);
            visited[i]= true;
            dfs(str,ans,res,visited,pos+1);
            visited[i] = false;
            res.pop_back();
        }        
    }
    vector<string> Permutation(string str) {
        int n = str.size();
        vector<bool> visited(n,false);
        vector<string> ans;
        string res="";
        // 首先排序，然后递归+回溯
        sort(str.begin(),str.end());
        //递归+回溯
        dfs(str,ans,res,visited,0);
        return ans;
    }
};



class SolutionChar {
    public:
    vector<string> ans;
    vector<bool> visited;
    string res= "";
    void dfs(string &str, int pos)
    {
        if (pos==str.size())
        {
            ans.push_back(res);
            return;
        }
        
        for(int i = 0; i< str.size(); i++)
        {
            if(visited[i] || (i>0 && str[i]==str[i-1] && !visited[i-1]))
            {
               continue; 
            }
            res.push_back(str[i]);
            visited[i]=true;
            dfs(str,pos+1);
            visited[i]=false;
            res.pop_back();
        }
    }
    
    vector<string> Permutation(string str) {
        if (str.empty()) return ans;
        sort(str.begin(), str.end());
        int len = str.size();
        visited = vector<bool>(len, false);
        dfs(str, 0);
        return ans;
    }
};