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


// 反向思考 ： 逆流 DFS
class Solution {
public:
    vector<int> direction={-1,0,1,0,-1};
    // 主函数
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {

        // 特殊情况的处理 不补上的话过不了
        if(matrix.empty() || matrix[0].empty()){
            return {};
        }


        vector<vector<int>> ans;
        int m = matrix.size(), n = matrix[0].size();
        
        // 二维数组的初始化
        vector<vector<bool>> can_reach_p(m, vector<bool>(n,false));
        vector<vector<bool>> can_reach_a(m, vector<bool>(n,false));

        // 从太平洋左侧遍历
        for(int i =0; i<m; i++)
        {
            dfs(matrix, can_reach_p, i, 0);
            dfs(matrix, can_reach_a, i, n-1);
        }
        for(int j = 0; j<n; j++)
        {
            dfs(matrix, can_reach_p, 0, j);
            dfs(matrix, can_reach_a, m-1,j);
        }
        // 递归完毕，得到每一个位置的true or false; 只有同一个位置在两个动态数组里面都成立的才可以流向两个大洋
        for(int i = 0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if (can_reach_p[i][j] && can_reach_a[i][j])
                {
                    ans.push_back(vector<int>{i,j});
                }
            }
        }
        return ans;    
    }
    // 辅函数
    void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& can_reach, int i, int j)
    {
        // 判断递归边界
        if(can_reach[i][j]){
            return;
        }
        // 递归实体
        can_reach[i][j]=true;
        // 判断递归开始条件
        for(int ind=0; ind<4; ind++){
            int ind_i = i + direction[ind];
            int ind_j = j + direction[ind+1];
            if(ind_i>=0 && ind_i<matrix.size() && ind_j>=0 && ind_j<matrix[0].size() && matrix[i][j]<=matrix[ind_i][ind_j])
            {
                dfs(matrix,can_reach,ind_i, ind_j);
            }

        }
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
    matrix ={ 
              {1,   2,   2,   3,  5},
              {3,   2,   3,   4,  4},
              {2,   4,   5,   3,  1},
              {6,   7,   1,   4,  5},
              {5,   1,   1,   2,  4}
            };
    print2vec(matrix);
    system("pause");
    return 0;
}
