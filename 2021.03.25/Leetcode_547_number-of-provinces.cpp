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

class Solution {
    public:
    int findCircleNum(vector<vector<int>> & isConnected)
    {
        int row = isConnected.size(), count = 0;
        // 初始化为false;
        vector<bool> visited(row,false);
        for(int i = 0; i< row; i++)
        {
            if(!visited[i])
            {
                dfs(isConnected, i, visited);
                ++count;
            }
        }
        return count;
    }

    // 辅助函数
    void dfs(vector<vector<int>> & isConnected, int i, vector<bool> &visited)
    { 
        visited[i]=true;
        for(int k =0; k<isConnected.size(); k++)
        {
            if(isConnected[i][k]==1 && !visited[k])
            {
                dfs(isConnected,k, visited);
            }

        }
    }
};



class Solution {
    public:
    void dfs(vector<vector<int>> & isConnected,  vector<int> visited, int provinces, int i)
    {
        for(int j = 0; j<provinces; j++)
        {
            // 判断递归条件
            if(isConnected[i][j]==1 && !visited[j])
            // 是否满足递归条件
            {
                visited[j]=1;
                dfs(isConnected, visited, provinces, j);
            }

        }
    }
        
    
    int findCirculeNum(vector<vector<int>> & isConnected)
    {
        int provinces = isConnected.size();
        vector<int> visited(provinces);
        int circles = 0;
        for (int i =0; i < provinces;  i++)
        {
            if(!visited[i])
            {
                dfs(isConnected, visited, provinces, i);
                circles++;
            }
        }
        return circles;
    }
  
};


// 连通量
class SolutionAc {
public:
    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int row)
    {
        // 递归边界
        visited[row]=true;
        for(int col=0;  col<isConnected.size(); col++)
        {
            // 判断能否进行递归
            if(isConnected[row][col]==1 && !visited[col])
            {
                dfs(isConnected, visited, col);                
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        // 设置一个访问列表，如果访问过，则跳过
        int n = isConnected.size();
        vector<bool> visited(n,false);
        int circle = 0;
        // 从每行开始搜索
        for(int row=0; row<isConnected.size(); row++)
        {
            if(!visited[row])
            {
                dfs(isConnected,visited,row);
                circle++;
            }
        }
        return circle;
    }
};

// 复杂度分析
// 时间复杂度：O(n^2),其中 n 是城市的数量。需要遍历矩阵中的每个元素。
// 空间复杂度：O(n)，其中 n 是城市的数量。需要使用数组 visited 记录每个城市是否被访问过，数组长度是 n，递归调用栈的深度不会超过 n。


// 方法二：广度优先搜索
// 也可以通过广度优先搜索的方法得到省份的总数。对于每个城市，如果该城市尚未被访问过，则从该城市开始广度优先搜索，直到同一个连通分量中的所有城市都被访问到，即可得到一个省份。

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int provinces = isConnected.size();
        vector<bool> visited(provinces,false);
        queue<int> queueCol;
        int circle = 0;
        for(int row = 0; row<provinces; row++)
        {
            if(!visited[row])
            {
                queueCol.push(row);
                while(!queueCol.empty())
                {
                    int cur_row = queueCol.front();
                    queueCol.pop();
                    visited[cur_row]=true;

                    for(int col = 0; col<isConnected.size(); col++)
                    {
                        if (isConnected[cur_row][col]==1 && !visited[col])
                        {
                            queueCol.push(col);
                        }
                    }                
                }
                circle++;
            }            
        }
        return circle;
    }
};

// 方法三：用栈实现的深度优先搜索


