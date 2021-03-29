#include <iostream>
#include <string>
#include <cstdio>
#include <numeric>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

// 方法1:基于集合的回溯

class Solution{
    public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> solutions;
        vector<int> queens(n,-1);
        unordered_set<int> columns;
        unordered_set<int> diagonals1;
        unordered_set<int> diagonals2;
        backtrack(solutions, queens, n, 0, columns, diagonals1, diagonals2);
        return solutions;
    }
    void backtrack(vector<vector<string>>& solutions, vector<int>& queens,
    int n, int row, unordered_set<int>& columns, unordered_set<int>& diagonals1, unordered_set<int>& diagonals2)
    {

        // 判断递归边界：终止条件
        if(row == n)
        {
            vector<string> board = generateBoard(queens,n);
            solutions.push_back(board);
        }
        else
        {   

            for(int i = 0; i<n; i++)
            {
                // 列数相同，立刻跳转
                if(columns.find(i)!= columns.end())
                {
                    continue;
                }
               
                // 同一条斜线上的每个位置满足行下标与列下标之差相等
                int diagonal1 = row - i; 
                if (diagonals1.find(diagonal1) != diagonals1.end())
                {
                    continue;
                }
               
                // 同一条斜线上的每个位置满足行下标与列下标之和相等
                int diagonal2 = row + i;
                if(diagonals2.find(diagonal2)!=diagonals2.end())
                {
                    continue;
                }
                
                // 这里记录的是某一列的索引
                // 如{0，3，1，2}
                queens[row] = i;

                // columns插入
                columns.insert(i);
                // 斜对角线插入
                diagonals1.insert(diagonal1);

                // 反写对角线插入
                diagonals2.insert(diagonal2);

                // 递归： 确定了某一方，进入下一行
                backtrack(solutions, queens, n, row+1, columns, diagonals1, diagonals2);

                // 回溯
                queens[row] = -1;
                columns.erase(i);
                diagonals1.erase(diagonal1);
                diagonals2.erase(diagonal2);
            }
        }   
    }

    vector<string> generateBoard(vector<int>& queens, int n)
    {
        vector<string> board;
        for(int i=0; i<n; i++)
        {
            string row = string(n, '.');
            row[queens[i]]='Q';
            board.push_back(row);
        }
        return board;
    }
};


class SolutionOurs {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<int> queens(n,-1);

        unordered_set<int> columns;
        unordered_set<int> digonals;
        unordered_set<int> anti_digonals;

        dfs(ans, queens, n, 0, columns, digonals, anti_digonals);
        return ans;
    }
    void dfs(vector<vector<string>>& ans, vector<int>& queens, int& n, int row, unordered_set<int>& columns,unordered_set<int>& digonals,unordered_set<int>& anti_digonals)
    {
        // 递归边界
        if(row==n)
        {   
            vector<string> board = generateBoard(queens,n);
            ans.push_back(board);
        }
        for(int col =0; col<n; col++)
        {
            if (columns.find(col)!=columns.end())
            {
                continue;
            }
            int digonal = row-col;
            if(digonals.find(digonal)!=digonals.end())
            {
                continue;
            }
            int anti_digonal = row + col;
            if(anti_digonals.find(anti_digonal)!=anti_digonals.end())
            {
                continue;
            }
            queens[row] = col;

            columns.insert(col);
            digonals.insert(digonal);
            anti_digonals.insert(anti_digonal);
            dfs(ans, queens, n, row+1, columns, digonals, anti_digonals);
            // 回溯：状态重置
            columns.erase(col);
            digonals.erase(digonal);
            anti_digonals.erase(anti_digonal);
            queens[row] = -1;   
        }
    }



    vector<string> generateBoard(vector<int> & queens, int& n)
    {
        vector<string> board;
        for(int i=0; i<n; i++)
        {
            string row = string(n,'.');
            row[queens[i]]='Q';
            board.push_back(row);
        }
        return board;
    }
    
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
