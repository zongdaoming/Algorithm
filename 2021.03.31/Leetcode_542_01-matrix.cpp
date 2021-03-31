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

class SolutionOurs {
    public:
    vector<int> direction={-1,0,1,0,-1};
    vector<vector<int>> updateMatrix(vector<vector<int>> &matrix)
    {

        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> ans(m,vector<int>(n,0));
        vector<vector<bool>> visited(m,vector<bool>(n,0));
        
        queue<pair<int,int>> que;
        // for considering
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(matrix[i][j]==0)
                {
                    que.push({i,j});
                    visited[i][j]=true;
                }
            }
        }
        // BFS while 套在for里面
        int level = 0;
        while(!que.empty())
        {
            int size = que.size();
            while(size--)
            {
                auto temp = que.front();
                int x = temp.first;
                int y = temp.second;
                que.pop();
                if (matrix[x][y]==1){
                    ans[x][y]=level;
                }
                for(int ind=0; ind<4; ind++)
                {
                    int ind_x = temp.first + direction[ind];
                    int ind_y = temp.second + direction[ind+1];
                    // 如果满足条件才往下面执行
                    if(ind_x>=0 && ind_y>=0 && ind_x<m && ind_y<n && !visited[ind_x][ind_y])
                    {
                        que.push({ind_x,ind_y});
                        visited[ind_x][ind_y] = true;
                        
                    }    
                }

            }
            level +=1;
        }
        return ans;
    }

};


class SolutionMultiposition{
private:
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dist(m, vector<int>(n));
        vector<vector<int>> seen(m, vector<int>(n));
        queue<pair<int, int>> q;
        // 将所有的 0 添加进初始队列中
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    q.emplace(i, j);
                    seen[i][j] = 1;
                }
            }
        }
        // 广度优先搜索
        while (!q.empty()) {
            auto ft = q.front();
            int i = ft.first;
            int j = ft.second;
            q.pop();
            for (int d = 0; d < 4; ++d) {
                int ni = i + dirs[d][0];
                int nj = j + dirs[d][1];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && !seen[ni][nj]) {
                    dist[ni][nj] = dist[i][j] + 1;
                    q.emplace(ni, nj);
                    seen[ni][nj] = 1;
                }
            }
        }

        return dist;
    }
};


class SolutionAC {
    public: 
    int Max = 1000;
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int numr = matrix.size();
        int numc = matrix[0].size();
        vector<pair<int,int>> around = {{0,1},{0,-1},{-1,0},{1,0}};
        vector<vector<int>> result(numr, vector<int>(numc, Max));
        queue<pair<int,int>> que;
        for(int i = 0; i < numr; i++){
            for(int j = 0; j < numc; j++){
                if(matrix[i][j] == 0){
                    result[i][j] = 0;
                    que.push({i, j});
                }
            }
        }
        while(!que.empty()){
            auto temp = que.front();
            que.pop();
            for(int i = 0; i < 4; i++){
                int x = temp.first + around[i].first;
                int y = temp.second + around[i].second;
                if(x >= 0 && x < numr && y >= 0 && y < numc){
                    if(result[x][y] > result[temp.first][temp.second] + 1){
                        // 防重
                        result[x][y] = result[temp.first][temp.second] + 1;
                        que.push({x, y});
                    }
                }

            }
        }
        return result;
    }
};



class SolutionDP {
public:
    int MAX =  1000;
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        // 初始化动态规划的数组，所有的距离值都设置为一个很大的数
        vector<vector<int>> dist(m, vector<int>(n,  MAX));
        // 如果 (i, j) 的元素为 0，那么距离为 0
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    dist[i][j] = 0;
                }
            }
        }
        // 只有 水平向左移动 和 竖直向上移动，注意动态规划的计算顺序
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i - 1 >= 0) {
                    dist[i][j] = min(dist[i][j], dist[i - 1][j] + 1);
                }
                if (j - 1 >= 0) {
                    dist[i][j] = min(dist[i][j], dist[i][j - 1] + 1);
                }
            }
        }
        // 只有 水平向左移动 和 竖直向下移动，注意动态规划的计算顺序
        for (int i = m - 1; i >= 0; --i) {
            for (int j = 0; j < n; ++j) {
                if (i + 1 < m) {
                    dist[i][j] = min(dist[i][j], dist[i + 1][j] + 1);
                }
                if (j - 1 >= 0) {
                    dist[i][j] = min(dist[i][j], dist[i][j - 1] + 1);
                }
            }
        }
        // 只有 水平向右移动 和 竖直向上移动，注意动态规划的计算顺序
        for (int i = 0; i < m; ++i) {
            for (int j = n - 1; j >= 0; --j) {
                if (i - 1 >= 0) {
                    dist[i][j] = min(dist[i][j], dist[i - 1][j] + 1);
                }
                if (j + 1 < n) {
                    dist[i][j] = min(dist[i][j], dist[i][j + 1] + 1);
                }
            }
        }
        // 只有 水平向右移动 和 竖直向下移动，注意动态规划的计算顺序
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (i + 1 < m) {
                    dist[i][j] = min(dist[i][j], dist[i + 1][j] + 1);
                }
                if (j + 1 < n) {
                    dist[i][j] = min(dist[i][j], dist[i][j + 1] + 1);
                }
            }
        }
        return dist;
    }
};
