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

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

// bfs 模板题：层次遍历

class Solution {
public:
        vector<vector<int> > Print(TreeNode* pRoot) {
            vector<vector<int>> ret;
            if(pRoot == NULL)
            {
                return ret;
            }
            queue<TreeNode*> q;
            q.push(pRoot);
            while(!q.empty())
            {
                vector<int> ans;                
                int sz = q.size();
                while(sz--)
                {
                    TreeNode *node = q.front();
                    q.pop();
                    ans.push_back(node->val);
                    if(node->left) q.push(node->left);
                    if(node->right) q.push(node->right);
                }
                ret.push_back(ans); 
            }
            return ret;
        }
};