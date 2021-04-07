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
  vector<int> dirt = {1, 0, -1, 0, 1}; 
  bool hasPath(vector<vector<char> >& matrix, string word) {
      vector<vector<bool> > visited(matrix.size(),vector<bool>(matrix[0].size(),0));
 
      for(int i = 0; i < matrix.size(); i++){
          for(int j = 0; j < matrix[0].size(); j++){
               if(dfs(matrix, i, j, 0, word, visited))return true;  
          }
      }
     return false; 
  }
 
  bool dfs(vector<vector<char> >& matrix, int x, int y, int w_index, string word, vector<vector<bool> >& visited){
      if(w_index == word.size()) return true; 
      if(x < 0 || x >= matrix.size() || y < 0 || y >= matrix[0].size() || visited[x][y] ||word[w_index] != matrix[x][y]) return false;
      w_index++;
      visited[x][y] = true;
      bool isExist = false;
      for(int i = 0; i < 4; i++){
          isExist = isExist || dfs(matrix, x + dirt[i], y + dirt[i+1], w_index, word, visited);
      }
 
      visited[x][y] = false;
      w_index--;
 
      return isExist;
  }
};

class Solution
{
    public:
    vector<int> dirt = {1, 0, -1, 0, 1}; 
    bool dfs(vector<vector<char> >& matrix, int lnow, string &word, vector<vector<bool> >& visited, int i, int j)
    {
        if(lnow==word.length())
        {
            return true;
        }
        


    }
    bool hasPath(vector<vector<char> >& matrix, string word) {
    vector<vector<bool>> visited(matrix.size(),vector<bool>(matrix[0].size(),0));
    int rows = matrix.size();
    int cols = matrix[0].size();
    for(int i = 0; i<rows; i++){
        for(int j = 0; j<cols; j++)
        {
            dfs(matrix,0, word, visited, i,j);
        }
    }


    }
 

    }


}