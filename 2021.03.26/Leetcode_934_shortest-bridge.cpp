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
    vector<int> direction{-1,0,1,0,-1};
    queue<int> queueRow;
    queue<int> queueCol;

    
    int shortestBridge(vector<vector<int>> & grid)
    {
        int m = grid.size(), n = grid[0].size();
        queue<int> queueRow;
        queue<int> queueCol;

        // dfs 寻找第一个岛屿，并把1全部赋值为2;
        bool flipped = false;
        for (int i = 0; i<m; i++)
        {
            if(flipped)
            {
                break;
            }
            for(int j = 0; j<n; j++)
            {
                if(grid[i][j]==1)
                {
                    dfs(queueRow, queueCol, grid, m, n, i, j);
                    flipped = true;
                    break;
                }

            }
        }
        
        // bfs寻找第二个岛屿，并把过程中经过的0赋值为2
        int count = 0;
        while(!queueRow.empty())
        {
            ++count;
            int n_points = queueRow.size();
            // 只要栈不为空
            while(n_points--)
            {
                int i = queueRow.front();
                int j = queueCol.front();
                queueRow.pop();
                queueCol.pop();
                for(int k =0; k<4; k++)
                {
                    int ind_i = i+direction[k];
                    int ind_j = j+direction[k+1];
                    if(ind_i>=0 && ind_j>=0 && ind_i<m && ind_j<n)
                    {
                        if(grid[ind_i][ind_j]==2){
                            continue;
                        }
                        if(grid[ind_i][ind_j]==1){
                            return count;
                        }
                        queueRow.push(i);
                        queueCol.push(j);
                        grid[ind_i][ind_j] = 2;
                    }
                }
            }
        }
        return 0;
        // 
    }

    void dfs(queue<int>& queueRow, queue<int>& queueCol, vector<vector<int>>& grid, 
    int m, int n, int i, int j)
    {
        // 递归边界 or 终止条件
        if(i<0 || j<0 || i==m || j==n ||grid[i][j]==2)
        {
            return;
        }
        // 递归终止的条件
        if(grid[i][j]==0)
        {
            queueRow.push(i);
            queueCol.push(j);
            return;

        }
        grid[i][j]=2;
        for (int ind = 0; ind<4; ind++)
        {
            int ind_i  = i + direction[ind];
            int ind_j  = j + direction[ind+1];
            dfs(queueRow,queueCol,grid,m,n,ind_i, ind_j);
        }
    }

};