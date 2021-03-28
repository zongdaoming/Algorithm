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
    vector<int> direction = {-1,0,1,0,-1};
    int shortestBridge(vector<vector<int>>& A) {
        queue<pair<int,int>>  Q;
        int  m = A.size();
        int n  = A[0].size();
        bool flag = true;
        int ans = -1;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        // *****************************************************
        for(int i = 0; i<m; i++)
        {
         
            
                 for(int j = 0; j<n; j++)
                 {
                     if(flag && A[i][j])
                     {
                         init(A, visited, Q, i, j);
                        flag = false;   
                     }
                }
        }
        // *****************************************************
        ans = bfs(A, visited);
        return ans;
    }

    void init(vector<vector<int>>& A, vector<vector<bool>>& visited, queue<pair<int,int>>& Q, int i, int j)
    {
        // 以Q为中心
        visited[i][j]=true;
        // 根节点
        Q.push({i,j});
        while(!Q.empty()){
            auto fn = Q.front();
            Q.pop();
            int x =  fn.first;
            int y = fn.second;
            for(int ind = 0; ind<4; ind++)
            {
                int ind_i = x + direction[ind];
                int ind_j = y + direction[ind+1];
                if( ind_i<0 || ind_j<0 || ind_i>=A.size() || ind_j>=A[0].size()){
                    continue;            
                }
                if(visited[ind_i][ind_j] || !A[ind_i][ind_j]){
                    continue;
                }
                visited[ind_i][ind_j]=true;
                Q.push({ind_i,ind_j});
            }
        }
    }
    
    int bfs(vector<vector<int>>& A, vector<vector<bool>>& visited)
    {
        queue<pair<int,int>> new_Q;
        for(int i = 0; i<A.size(); i++)
        {
            for(int j = 0; j<A[0].size(); j++)
            {
                if(visited[i][j]){
                   new_Q.push({i,j});
                }
            }
        }
        
        // 以Q为中心
        // visited[i][j]=true;
        // 根节点
        // Q.push({i,j});
        while(!new_Q.empty()){
            auto fn = new_Q.front();
            new_Q.pop();
            int x =  fn.first;
            int y = fn.second;
            for(int ind = 0; ind<4; ind++)
            {
                int ind_i = x + direction[ind];
                int ind_j = y + direction[ind+1];
                
                if( ind_i<0 || ind_j<0 || ind_i>=A.size() || ind_j>=A[0].size()){
                    continue;            
                }
                if(visited[ind_i][ind_j]){
                    continue;
                }

                if(A[ind_i][ind_j]==0)
                {
                    A[ind_i][ind_j] = A[x][y]+1;
                }
                else
                {
                    return A[x][y]-1;
                }
                visited[ind_i][ind_j]=true;
                new_Q.push({ind_i,ind_j});
        }
    }
    
        return -1;
    } 
 
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
