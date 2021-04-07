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
    
    vector<int> direction= {1,0,-1,0,1};
    int check(int n)
    {
        int sum = 0;
        while(n)
        {
            sum += (n%10);
            n /= 10;
        }
        return sum;
    }
    void dfs(int x, int y, int &sho, int &ret, vector<vector<int>> &grid)
    {
        // 递归边界
        if(x<=0|| x>=grid.size() || y<0 || y>=grid[0].size() || grid[x][y]==1)
        {
            return;
        }
        // 递归边界
        if(check(x) +check(y)>sho)
        {
            return;
        }

        grid[x][y] = 1;
        ret+=1;

        for(int ind = 0; ind<4; ++ind)
        {
            int ind_x = x + direction[ind];
            int ind_y = y + direction[ind+1];
            dfs( ind_x, ind_x, sho, ret, grid);
        }


    }
    int movingCount(int threshold, int rows, int cols) {
        if (threshold<=0)
        {
            return  0;
        }
        vector<vector<int>> grid(rows,vector<int>(cols,-1));
        int ret = 0;
        dfs(0,0,threshold,ret,grid);
        return ret;
    }
};


class Solution {
public:
    typedef pair<int,int> pii;
    using V = vector<int>;
    using W = vector<V>;
    vector<int> direction = {0,1,0,-1,0};    
    int check(int n)
    {
        int sum = 0;
        while(n)
        {
            sum += (n%10);
            n /= 10;
        }
        return sum;
    }
    int movingCount(int threshold, int rows, int cols) {
        if(threshold<0)
        {
            return 0;
        } 
        W grid(rows,V(cols,-1));
        int ret = 0;
        queue<pii> q;
        q.push({0,0});
        grid[0][0]=1;

        while(!q.empty())
        {
            auto ft = q.front();
            q.pop();
            // 每次保证进队列的都是满足条件的坐标            
            ++ ret;
            for(int ind = 0; ind<4; ind ++)
            {
                int x = ft.first + direction[ind];
                int y = ft.second + direction[ind+1];
                if( x >= 0 && x< rows && y>=0 && y<cols && grid[x][y] == -1)
                {
                    if(check(x)+check(y)<=threshold)
                    {
                        q.push({x,y});
                        grid[x][y] = 1;
                    }
                }
            }
        }
        return ret; 
    }
};