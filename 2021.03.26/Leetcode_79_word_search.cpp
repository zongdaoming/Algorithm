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


// 在我们对任意位置进行深度优先搜索时，
// 我们先标记当前位置为已访问， visited
// 以避免重复遍历（如防止向右搜索后又向左返回）

class Solution {
public:  
    vector<int> direction = {1,0,-1,0, 1};
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty()) return false;
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        bool find = false;
        for(int i =0 ; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(board[i][j]==word[0]){
                    backtracking(i,j, board, word, find, visited, 0);
                }
            }
        }
        return find;

    }

    void backtracking(int i, int j, vector<vector<char>> & board, string& word, bool& find, vector<vector<bool>>& visited, int pos)
    {
        // 递归边界
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size())
        {
            return;
        }
        if(visited[i][j] || find || board[i][j] !=word[pos])
        {
            return;
        }
        if(pos==word.size()-1){
            find = true;
            return;
        }
        visited[i][j]=true; //修改当前节点状态
        // 递归子节点
        for(int ind = 0; ind<4; ind++)
        {
            int ind_i = i + direction[ind];
            int ind_j = j + direction[ind+1];
            backtracking(ind_i, ind_j, board, word, find, visited, pos+1);
            // 回溯=状态回置
        }
        visited[i][j]=false; // 回改当前节点状态
    }
};



int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
