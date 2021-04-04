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
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}

    static void PreOrder (TreeNode *root)
    {
        if(root==NULL)
        {
            return;
        }
        cout<<root->val;
        PreOrder(root->left);
        PreOrder(root->left);
    }
    static void Inorder(TreeNode *root)
    {
        if(root == NULL)
        {
            return;
        }
        Inorder(root->left);
        cout<<root->val;
        Inorder(root->right);
    }
};


class Solution {
    public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in) {
        if(pre.size() != in.size())
        {
            return NULL;
        }
        int size = pre.size();
        if(size==0)
        {
            return NULL;
        }
        int length = pre.size();
        int value = pre[0]; //前序遍历的第一个节点是根节点
        TreeNode *root = new TreeNode(value);

        //  在中序遍历中查找到根的位置
        int rootIndex = 0;
        for (rootIndex = 0; rootIndex<length; rootIndex++)
        {
            if(in[rootIndex]==value)
            {
                break;
            }
        }
        if(rootIndex>=length)
        {
            return NULL;
        }

        //  区分左子树和右子树
        //  中序遍历中, 根左边的就是左子数, 右边的就是右子树
        //  前序遍历中, 根后面是先遍历左子树, 然后是右子树

        int leftLength = rootIndex;
        int rightLength = length-1-rootIndex;

        vector<int> preLeft(leftLength), inLeft(leftLength);
        vector<int> preRight(rightLength),inRight(rightLength);
        for(int i = 0; i<length; i++)
        {
            if(i<rootIndex)
            {
               //  前序遍历的第一个是根节点, 根后面的(leftLegnth = rootIndex) - 1个节点是左子树, 因此是i+1
               preLeft[i] = pre[i+1];
              // 中序遍历前(leftLength = rootIndex) - 1个节点是左子树, 第rootIndex个节点是根
               inLeft[i]=in[i];
            }
            else if (i>rootIndex)
            {
                preRight[i-rootIndex-1] = pre[i];
                inRight[i-rootIndex-1] = in[i];
            }
        }
        root->left = reConstructBinaryTree(preLeft,inLeft);
        root->right= reConstructBinaryTree(preRight,inRight);

        return root;
    }
};

