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

/**
 * Definition for a binary tree node.
*/  
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 递归边界
        if(root == NULL) return NULL;
        if(root==p || root==q)
        {
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left!=NULL && right!=NULL)
        {
            // p,q一个在左边，一个在右边
            return root;
        }
        if(left!=NULL)
        {
            // p,q 都在左子树
            return left;
        }
        if(right!=NULL)
        {
            // p,q 都在右子树
            return right;
        }
        return nullptr;
    }
};