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
 TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
 
class Solution {
    public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param pRoot TreeNode类 
     * @return TreeNode类
     */
    TreeNode* Mirror(TreeNode* pRoot) {
        // write code here
        if(pRoot == NULL) return pRoot;
        TreeNode *temp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = temp;
        Mirror(pRoot->left);
        Mirror(pRoot->right);
        return pRoot;
    }
};

// 提到过二叉树的广度优先搜索，就是一层一层的访问，像下面这样

class SolutionBFS 
{
    public:
    TreeNode *Mirror(TreeNode* root)
    {
        if(root==NULL){
            return NULL;
        }
        queue<TreeNode*> Q;
        // 先把根节点加入到队列中
        Q.push(root);
        while(!Q.empty())
        {
            TreeNode* node = Q.front();
            Q.pop();
            TreeNode* temp = node->left;
            node->left = node->right;
            node->right = temp;
            if(node->left) Q.push(node->left);
            if(node->right) Q.push(node->right);

        }
        return root;
    }
    

};

// 2，DFS解决
// 无论是BFS还是DFS都会访问到每一个节点，访问每个节点的时候交换他的左右子节点，直到所有的节点都访问完为止
class SolutionDFS
{
    public:
    TreeNode *Mirror(TreeNode *root)
    {
        if(root==NULL)
        {
            return NULL;
        }
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty())
        {
            TreeNode* node = st.top();
            st.pop();
            TreeNode* temp = node->left;
            node->left = node->right;
            node->right = temp;
            if(node->left) st.push(node->left);
            if(node->right)st.push(node->right);
        }
        return root;
    }
};


//3.中序遍历非递归
// 提到二叉树中序遍历的非递归写法如下
class inOrderTraversal
{
    public:
    TreeNode *Mirror(TreeNode *root)
    {
        if(root==NULL)
        {
            return NULL;
        }
        stack<TreeNode*> st;
        while(root!=NULL || !st.empty())
        {
            while(root!=NULL)
            {
                st.push(root);
                root = root->left;
            }
            if(!st.empty())
            {
                TreeNode *root = st.top();
                st.pop();
                cout<<root->val<<endl;
                root = root->right;
            }
        }
    }
};


class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param pRoot TreeNode类 
     * @return TreeNode类
     */
    TreeNode* Mirror(TreeNode* root) {
        // write code here
        if(root==NULL)
        {
            return NULL;
        }
        stack<TreeNode*> st;
        TreeNode *node = root;
        while(node!=NULL || !st.empty())
        {
            while(node!=NULL)
            {
               st.push(node);
               node = node->left; 
            }
            if(!st.empty())
            {
                node = st.top();
                st.pop();
                // 子节点交换
                TreeNode* temp = node->left;
                node->left = node->right;
                node->right = temp;
                // 注意这里以前是node->right, 因为上面已经交换了
                // 所以这里是node->left
                node = node->left;
            }
        }
        return root;
    }
};

