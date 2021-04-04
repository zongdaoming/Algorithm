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


class Solution {
public:
    vector<vector<int>> Print(TreeNode* pRoot) {
        vector<vector<int>> ret;
        if(pRoot == NULL)
        {
            return ret;
        }
        queue<TreeNode*> q;
        q.push(pRoot);
        int count = 1;
        while(!q.empty())
        {
            int size = q.size();
            vector<int> ans;
            while(size--)
            {
                TreeNode *node = q.front();
                q.pop();
                ans.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            count++;
            ret.push_back(ans);
        }
        
        for(int i = 0; i<ret.size(); i++)
        {
            if(i%2==1)
            {
                reverse(ret[i].begin(),ret[i].end());
            }
        }
        
        return ret;
    }
};