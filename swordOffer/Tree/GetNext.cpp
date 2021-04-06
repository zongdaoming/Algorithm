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



struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};

class SolutionViolent {
public:
    void pre_order(TreeLinkNode *root, vector<TreeLinkNode*> &v) {
        if (!root) {
            return;
        }
 
        pre_order(root->left, v);
        v.push_back(root);
        pre_order(root->right, v);
    }
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
          TreeLinkNode *root = nullptr;
          TreeLinkNode *tmp = pNode;
          // 第一步
          while (tmp) {
              root = tmp;
              tmp = tmp->next;
          }  
 
          vector<TreeLinkNode*> v;
          // 第二步
          pre_order(root, v);
 
          // 第三步
          int n = v.size();
          for (int i = 0; i < n; ++i) {
              if (v[i] == pNode && i + 1 != n) {
                  return v[i+1];
              }
          }
          return nullptr;
    }
};

// 对于给定的节点：

// 1.如果它可以是一个父节点，根据中序遍历的规则，需要输出它右子树中的【最左子节点】

// 2.如果它不是父节点
// 2.1若它是它父节点的左叶子，则返回它的父节点

// 2.2 若它是右叶子，则不断向上搜索父节点，直至有一个父节点k不是k的父节点的右叶子，此时返回k的父节点。
// 如果直到根节点上述情况还不成立，有可能该节点是最后一个节点或是输入的二叉树为None，则输出None

// 2.2 (换一种说话)右叶子：向上遍历它的祖先节点，直到找到一个祖先节点满足为左孩子的条件， 然后返回该
// 祖先节点的父节点


class SolutionFast{
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if (!pNode) {
            return pNode;
        }
        //如果它可以是一个父节点，根据中序遍历的规则，需要输出它右子树中的【最左子节点】
        if (pNode->right) {
            pNode = pNode->right;
            while (pNode->left) {
                pNode = pNode->left;
            }
            return pNode;
        }
        // 找到一个祖先节点满足为左孩子的条件， 然后返回该祖先节点的父节点
        while (pNode->next) {
            TreeLinkNode *root = pNode->next;
            if (root->left == pNode) {
                return root;
            }
            pNode = pNode->next;
        }
        return nullptr;
    }
};