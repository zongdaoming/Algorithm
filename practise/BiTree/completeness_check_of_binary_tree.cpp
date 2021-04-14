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

// 1.层次遍历直至遇到第一个空节点
// 2.完全二叉树在遇到空节点之后剩余的应当全是空节点

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
    public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        bool flag=false;
        while(!q.empty()){
            auto node =q.front();
            q.pop();
            if(node==nullptr){
                flag=true;
                continue;
            }
            if(flag) return false;
            q.push(node->left);
            q.push(node->right);
        }
        return true;
    }
};


class Solution {
    public:
    vector<int> ret;
    bool isCompleteTree(TreeNode* root) {
 
        return bianli(root); 
    }
    bool bianli(TreeNode* root)
    {
       
        if (root == NULL) {
            return true;
        }
        int flag = 0;
        queue<TreeNode *> Q;
        Q.push(root);
        while (!Q.empty()) {
            int size = Q.size();
            for (int i = 0; i < size; i++) {
                TreeNode *head = Q.front(); Q.pop();
                if(head != NULL && flag == 1)
                    return false;
                else if(head != NULL && flag == 0)
                {
                    Q.push(head->left);
                    Q.push(head->right);
                }
                else if(head == NULL )
                {
                    flag = 1;
                }
            }
        }
        return true;
 
    }
};
