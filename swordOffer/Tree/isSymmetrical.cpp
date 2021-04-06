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
    bool isSame(TreeNode* root1, TreeNode *root2)
    {
        if(!root1 && !root2) return true;
        if(!root1 || !root2) return false;
        return root1->val == root2->val && isSame(root1->left, root2->right) && isSame(root1->right, root2->left);
    }    
    bool isSymmetrical(TreeNode* pRoot) {   
        return isSame(pRoot,pRoot);
    }
};
