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

// 使用递归的深度优先遍历:第一种写法 在递归之前首先判断，先判定是否越界，只有在合法的情况下才进行下一步搜索（即判断放在调用递归函数前）
class Solution101 {
    public:
    vector<int> direction{-1,0,1,0,-1};
    // 可以创造一个数组 [-1, 0, 1, 0, -1]，每相 邻两位即为上下左右四个方向之一
    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        if(grid.empty() ||grid[0].empty()) return 0;
        int max_area = 0;
        for(int i = 0; i< grid.size(); i++)
        {
            for (int j = 0; j<grid[0].size(); j++)
            {
               //    在递归之前首先判断
               if (grid[i][j]==1)
               {
                   max_area = max(max_area, dfs(grid,i,j));
               }
    
            }
        }
        return max_area;
    }

    // 辅函数
    int dfs(vector<vector<int>> &grid, int i, int j)
    {
        if (grid[i][j]==0) return 0;
        int x, y, area =1;
        for(int ind=0; ind<4; ind++){
            x = i+direction[i];
            y = j+direction[i+1];
            if(x>=0 && y<grid.size() && y>=0 && y<grid[0].size())
            {
                // 判断条件写在递归之前
                area += dfs(grid,x,y);
            }
        
        }
        return area;
    }
};


// 使用递归的深度优先遍历： 第二种： 不管三七二十一先进行下一步搜索，待下一步搜索开始时再判断是否合 法（即判断放在辅函数第一行）

class Solution102 {
    public:
    int maxAreaOfIsland(vector<vector<int>> & grid)
    {
        if (grid.empty() || grid[0].empty()) return 0;
        int max_area = 0;
        for(int i = 0; i<grid.size(); i++)
        {
            for (int j = 0; j<grid[0].size(); j++)
            {
                max_area = max(max_area,dfs(grid, i,j));
            }
        }

    }
    int dfs(vector<vector<int>> & grid, int i, int j)
    {  
        int area=0;
        //  判断是否在递归边界内
        if(i<0 || i==grid.size()|| j<0 || j==grid.size())
        {
            return 0;
        }
        grid[i][j]=0;
        return 1 + dfs(grid,i+1,j) + dfs(grid,i-1,j) + dfs(grid, i, j-1) + dfs(grid, i, j+1);
    }
};



class Solution{
    public:
    int IslandDFS(vector<vector<int>> & grid, int i, int j)
    {
        // step:1 判断是否在递归边界内
        // 判断访问是否超越了二维数组的边界
        if(i<grid.size() && (i>=0) && j<grid[0].size() && j>=0)
        {
            // 第二种边界： 水
            if(grid[i][j]==0)
            {
                return 0;
            }
            else
            {
                grid[i][j]=0;
                return 1+ IslandDFS(grid, i-1,j) + IslandDFS(grid,i+1,j) + IslandDFS(grid,i,j-1) + IslandDFS(grid,i,j+1); 
            }
        }
        else
        {
            return 0;
        }
    }

    int maxAreaOfIsland(vector<vector<int>> & grid)
    {
        int ans = 0;
        
        // 遍历整块所给的区域
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                ans = max(ans,IslandDFS(grid, i,j));
            }
        }
        return ans;
    }
};

// 空间复杂度， O(R*C)
// 对于整个所给的二维网格来说，在递归时至多会被访问一次，
// 时间复杂度，O(R*C)




// 方法二：深度优先搜索 + 栈
// 算法

// 我们可以用栈来实现深度优先搜索算法。这种方法本质与方法一相同，唯一的区别是：

// 方法一通过函数的调用来表示接下来想要遍历哪些土地，让下一层函数来访问这些土地。

// 而方法二把接下来想要遍历的土地放在栈里，然后在取出这些土地的时候访问它们。

// 访问每一片土地时，我们将对围绕它四个方向进行探索，找到还未访问的土地，加入到栈 stack 中；

// 另外，只要栈 stack 不为空，就说明我们还有土地待访问，那么就从栈中取出一个元素并访问。

class Solution2 {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;

        for(int i = 0; i< grid.size(); i++)
        {
            for(int j = 0; j< grid[0].size(); j++)
            {
                // 访问所有的区块
                stack<int> stacki;
                stack<int> stackj;
                stacki.push(i);
                stackj.push(j);

                int cur = 0;
                while(!stacki.empty())
                {
                    int index_i = stacki.top(); 
                    int index_j = stackj.top();
                    stacki.pop();
                    stackj.pop();

                    // 边界条件
                    if(index_i<0 || index_j<0 || index_i==grid.size() || index_j == grid[0].size() || grid[index_i][index_j]!=1)
                    {
                        continue;
                    }
                    cur++;
                    grid[index_i][index_j]=0;
                    int di[4] = {-1,1,0,0};
                    int dj[4] = {0,0,-1,1};
                    for(int ind = 0; ind<4; ind++)
                    {

                        int next_i = index_i +di[ind], next_j = index_j+dj[ind];
                        stacki.push(next_i);
                        stackj.push(next_j);
                    }
                }
                ans = max(ans,cur);
            }
        }
        return ans;
    }
};

// 时间复杂度：O(R×C)。其中 R 是给定网格中的行数，C是列数。我们访问每个网格最多一次。
// 空间复杂度：O(R×C)，栈中最多会存放所有的土地，土地的数量最多为 R×C 块，因此使用的空间为 O(R×C)。
// 执行用时：
// 132 ms
// , 在所有 C++ 提交中击败了
// 5.12%
// 的用户
// 内存消耗：
// 110.2 MB
// , 在所有 C++ 提交中击败了
// 4.99%
// 的用户



// 我们把栈改为队列，每次从队首取出土地，并将接下来想要遍历的土地放在队尾，就实现了广度优先搜索算法。
class Solution3 {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i != grid.size(); ++i) {
            for (int j = 0; j != grid[0].size(); ++j) {
                int cur = 0;
                queue<int> queuei;
                queue<int> queuej;
                queuei.push(i);
                queuej.push(j);
                while (!queuei.empty()) {
                    int cur_i = queuei.front(), cur_j = queuej.front();
                    queuei.pop();
                    queuej.pop();
                    if (cur_i < 0 || cur_j < 0 || cur_i == grid.size() || cur_j == grid[0].size() || grid[cur_i][cur_j] != 1) {
                        continue;
                    }
                    ++cur;
                    grid[cur_i][cur_j] = 0;
                    int di[4] = {0, 0, 1, -1};
                    int dj[4] = {1, -1, 0, 0};
                    for (int index = 0; index != 4; ++index) {
                        int next_i = cur_i + di[index], next_j = cur_j + dj[index];
                        queuei.push(next_i);
                        queuej.push(next_j);
                    }
                }
                ans = max(ans, cur);
            }
        }
        return ans;
    }
};

// 复杂度分析
// 时间复杂度：O(R×C)。其中 R是给定网格中的行数，C 是列数。我们访问每个网格最多一次。
// 空间复杂度：O(R×C)，队列中最多会存放所有的土地，土地的数量最多为 R×C 块，因此使用的空间为 O(R×C)。


int main(int argc, char const *argv[])
{

    Solution solution;

    int max_num = 0;

    vector<vector<int>> grid;

    max_num = solution.maxAreaOfIsland(grid);

    cout<<"Max Island is"<<max_num<<endl;

    return 0;
}
