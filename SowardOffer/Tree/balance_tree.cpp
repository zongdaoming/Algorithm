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
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* abs */

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
    map<TreeNode*, int> hs;
    int depth(TreeNode *root)
    {
        if(!root) return 0;
        if(hs.find(root)!=hs.end()) return hs[root];
        
        int ldep = depth(root->left);
        int rdep = depth(root->right);
        return hs[root] = max(ldep, rdep) + 1;
    }
    bool judge(TreeNode* root)
    {
        if(!root) return true;
        return std::abs(hs[root->left]-hs[root->right]) <= 1 && judge(root->left) && judge(root->right); 
    }
    
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if (pRoot == NULL) return true;
        depth(pRoot);
        return judge(pRoot);
    }
};

class SolutionFast
{
    public:
    int depth(TreeNode *root)
    {
        if (!root) return 0;
        int ldep = depth(root->left);
        if(ldep == -1) return -1;
        int rdep = depth(root->right);
        if(rdep == -1) return -1;
        if(std::abs(ldep-rdep)>1) return -1;
        return max(ldep,rdep)+1;
    }

    bool IsBalanced_Solution(TreeNode* pRoot) {

        return depth(pRoot)!=-1;
    
    
    }
};