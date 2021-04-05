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
    void dfs(TreeNode *root, int sum, vector<vector<int>> &ans, vector<int> &ret)
    {
        ret.push_back(root->val);
        //递归终止的条件：当root节点为叶子节点并且sum==root->val, 表示找到了一条符合条件的路径

        if(sum== root->val && !root->left && !root->right)
        {
            ans.push_back(ret);
        }
        // 下一次递归：如果左子树不空，递归左子树FindPath(root->left, sum - root->val),
        // 如果右子树不空，递归右子树，FindPath(root->right, sum - root->val)
        if(root->left) dfs(root->left, sum-root->val, ans, ret);
        if(root->right) dfs(root->right, sum-root->val, ans, ret);
        ret.pop_back();
    }
    
    vector<vector<int>> FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int>> ans;
        vector<int> ret;
        if(!root) return ans;
        dfs(root, expectNumber, ans, ret);
        return ans;
    }
};