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


class Solution{
    public:

    bool dfs(vector<vector<int>>& grid, int row, int col)
    {
        // 判断递归的边界
        if(row>0 && row<grid.size()-1 && col>0 && col<grid[0].size()-1)
        {            
            if(grid[row][col]>=grid[row-1][col])
            {
                return dfs(grid,row-1,col);
            }
            if(grid[row][col]>=grid[row+1][col]){
                return dfs(grid,row+1,col);
            }
            if(grid[row][col]>=grid[row][col-1]){
                return dfs(grid,row,col-1);
            }
            if(grid[row][col]>=grid[row][col+1]){
                return dfs(grid,row,col+1);
            }
        }
        return false;
    };
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) 
    {


        int n = matrix.size();
        vector<vector<int>> ans;
        int index=0;

        for(int row = 0; row<matrix.size(); row++)
        {
            for(int col = 0; col<matrix[0].size(); col++)
            {
                if(dfs(matrix,row,col))
                {
                    ans[index]=vector<int>{row,col};
                }
            }
        }
        return ans;
    
    }
};

void print2vec(vector<vector<int>>& grid)
{
    for(int i = 0; i<grid.size(); i++)
    {
        for(int j = 0; j<grid[0].size(); j++)
        {
            cout<<" "<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> matrix(5,vector<int>(5));
    matrix ={{ 1,   2,   2,   3,  5},
              {3,   2,   3,   4,  4},
              {2,   4,   5,   3,  1},
              {6,   7,   1,   4,  5},
              {5,   1,   1,   2,  4}
            };
    print2vec(matrix);
    system("pause");
    return 0;
}
