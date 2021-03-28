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
void print2vec(vector<vector<char>> &board);

// 任何边界上的 O 都不会被填充为 X。 
// 我们可以想到，所有的不被包围的 O 都直接或间接与边界上的 O 相连。
// 我们可以利用这个性质判断 O 是否在边界上，具体地说：
// 对于每一个边界上的 O，我们以它为起点，用A标记所有与它直接或间接相连的字母 O；

// dfs
class Solution{
    public:
    vector<int> direction{-1,0,1,0,-1};
    int m, n;

    void(dfs(vector<vector<char>> &board, int x, int y)){
        // 递归边界
        if(x<0 || x>=n || y<0 || y>=m || board[x][y]!='O')
        {
            return;
        }
        board[x][y]='A';
        for(int ind = 0; ind < 4; ind++)
        {
            int ind_x = x + direction[ind];
            int ind_y = y + direction[ind+1];
            dfs(board,ind_x,ind_y);
        }
    }

    void solve(vector<vector<char>> &board)
    {
        n = board.size();
        if(n==0)
        {
            return;
        }
        m = board[0].size();
        for (int i =0; i<n; i++)
        {
            dfs(board, i, 0);
            dfs(board, i, m-1);
        }
        for (int j = 0; j<m; j++)
        {
            dfs(board,0,j);
            dfs(board, n-1, j);

        }
        for(int i=0; i<n; i++)
        {
            for(int j = 0; j<m; j++)
            {
                if(board[i][j]=='A')
                {
                    board[i][j]='O';
                }
                else if(board[i][j]=='O')
                {
                    board[i][j]='X';
                }
            }
        }
    }
};

// bfs

class SolutionBFS{
    vector<int> direction{-1,0,1,0,-1};
    public:
    int m, n = 0;
    void solve(vector<vector<char>> & board)
    {
        int n = board.size();
        int m = board[0].size();
        if(n==0) return;
        // bfs need queue
        queue<pair<int,int>> que;
        for(int i =0; i<n; i++)
        {
            if(board[i][0]=='O')
            {
                // que.emplace(i,0);
                que.push({i,0});
            }
            if(board[i][m-1])
            {
                // que.emplace(i,m-1);
                que.push({i,m-1});
            }
            for(int i = 1, i < m-1; i++)
            {
                if(board[0][i]=='O')
                {
                    // que.emplace(0,i);
                    que.push({0,i});
                }
                if(board[n-1][i]=='O')
                {
                    // que.emplace(n-1,i);
                    que.push({n-1,i});
                }
            }
        }
        while(!que.empty())
        {
            auto ft = que.front();
            int x = ft.first;
            int y = ft.second;
            que.pop();
            board[x][y]='C';
            for(int ind = 0; ind<4; ind++)
            {
                int ind_x = x + direction[ind];
                int ind_y = y + direction[ind+1];
                // 广度优先搜索在这判定条件
                if(ind_x<0 || ind_y <0 || ind_x>=board.size() || ind_y >= board[0].size() || board[ind_x][ind_y]!='O')
                {
                    continue;
                }
                // que.emplace(ind_x,ind_y);
                que.push({ind_x,ind_y});
            }
        }
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<m; j++)
            {
                if(board[i][j]=='C')
                {
                    board[i][j] = 'O';
                }
                else if(board[i][j]=='O')
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};

void print2vec(vector<vector<char>> &board)
{
    for(int i = 0; i<board.size(); i++)
    {
        for(int j = 0; j<board[0].size(); j++)
        {
            cout<<" "<<board[i][j];
   }
        cout<<endl;
    }
}


int main(int argc, char const *argv[])
{
    Solution solution;
    int m = 4, n = 4;
    vector<vector<char>> board(m, vector<char>(n));
    // vector<vector<char>> board;
    board[0] = {'X','X','X','X'};
    board[1] = {'X','O','O','X'};
    board[2] = {'X','X','O','X'};
    board[3] = {'X','O','X','X'};
    // print2vec(board);
    solution.solve(board);

    system("pause");
    return 0;
}
