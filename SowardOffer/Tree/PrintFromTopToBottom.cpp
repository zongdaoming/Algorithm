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

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root){ 
        vector<int> ans;
        queue<TreeNode*> Q;
        
        if(!root) 
        {
            return ans;
        }
        Q.push(root);
        
        while(!Q.empty())
        {
            int sz = Q.size();
            while(sz--)
            {
                TreeNode *node =  Q.front();
                Q.pop();
                ans.push_back(node->val);
                if(node->left) Q.push(node->left);
                if(node->right) Q.push(node->right);
            }
            
        }
        return ans;
    }
};