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

// 二叉搜索树的中序遍历正好是一个递增的序列, 因此中序遍历的第K个结点就是二叉搜索树的第K个节点
class Solution {
    unsigned int count = 0;
    public:
    TreeNode* KthNode(TreeNode* pRoot, int k) {
        if(pRoot == NULL)
        {
            return  NULL;
        }
        TreeNode *ret = NULL;

        if ((ret = KthNode(pRoot->left, k))!=NULL)
        {
            return ret;
        }
        ++count;
        if(count==k)
        {
            return pRoot;
        }
        if((ret = KthNode(pRoot->right, k))!=NULL)
        {
            return ret;
        }
        return NULL;
    }
};

// 根节点的值大于其左子树中任意一个节点的值，
// 小于其右节点中任意一节点的值，这一规则适用于二叉查找树中的每一个节点。

class SolutionMiddle {
    public:
    int m;
    TreeNode* ans;
    void dfs(TreeNode *p)
    {
        if(!p||m<1) return;//不满足条件直接返回NULL/每次递归出口：
        dfs(p->left); //走到了最左边结点,到空不继续递归，该节点左右走完了回溯上一层
        if(m == 1) ans = p; //最左边结点 / m-到1的时候，当前结点就是第m小
        if(--m>0) dfs(p->right); //  右子树同样处理/遍历该节点的右节点 (左中右)
    }
    TreeNode* KthNode(TreeNode* pRoot, int k) {
        ans = NULL; 
        m = k;
        dfs(pRoot);
        return ans;
    }    
};

class SolutionOurs {
public:
    int m;
    TreeNode* ans;
    
    void dfs(TreeNode* root)
    {
        if (!root || m<=0)
        {
            // 递归边界
            return;
        }
        dfs(root->left);
        if (m==1)
        {
            ans = root;
        }
        if(--m)
        {
            dfs(root->right);
        }
    }
    TreeNode* KthNode(TreeNode* pRoot, int k) {
        m = k;
        ans = NULL;
        dfs(pRoot);
        return ans;        
    }
};

class SolutionStack{
    public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(!pRoot) return nullptr;
        stack<TreeNode*> res;
        TreeNode *p = pRoot;
        while(!res.empty() || p)
        {
            while(p)
            {
                res.push(p);
                p = p->left;
            }
            TreeNode* node = res.top();
            res.pop();
            if((--k)==0) return node;
            p = node->right;
        }
        return nullptr;
    }
};