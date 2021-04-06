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


// 有序的双向链表=>中序遍历， 小->大
// 根据要求，节点的left指向小节点，节点的right指向大节点

// 递归的规律出来了，left向小节点，也就是前一个节点
// left指向大节点，那么前一个节点的right指向当前节点
// 头节点就是node.left == null 的节点


class Solution {
public:
    TreeNode* prenode = NULL;
    TreeNode* Convert(TreeNode* root) {
        if (root==NULL)
        {
            return NULL;
        }
        else{
            Convert(root->left);
            //propcessing
            root->left = prenode; //左节点指向小节点
            if(treenode!=NULL){
                prenode->right = root; //右节点指向大结点
            }
            // just for update
            prenode = root;  // 记录上一个遍历到的节点
            Convert(root->right);
        }
        while(root!=NULL && root->left!=NULL)
        {
            root = root->left;
        }
        return root; 
    }
};