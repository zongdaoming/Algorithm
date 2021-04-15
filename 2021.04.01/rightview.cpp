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


/*
根据先序遍历和中序遍历重建二叉树步骤：
1.先序的第一个元素pre[pstart]就是根节点，在中序中找到这个根节点的下标k。下标从0开始
2.找到根节点下标后，那么左子树节点个数是：k-istart
3.根节点的左子树寻找范围从pstart+1就可以了，中序的范围是 istart ---- k-1
4.根节点的右子树范围从先序的 pstart + k-istart +1。pos代表在先序序列中右子树根节点的下标。
中序序列中，从k+1到iend即可
*/

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x):val(x), left(NULL),right(NULL){}
};

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 求二叉树的右视图
     * @param xianxu int整型vector 先序遍历
     * @param zhongxu int整型vector 中序遍历
     * @return int整型vector
     */
    /*
    根据先序遍历和中序遍历重建二叉树步骤：
    1.先序的第一个元素pre[pstart]就是根节点，在中序中找到这个根节点的下标k。下标从0开始
    2.找到根节点下标后，那么左子树节点个数是：k-istart
    3.根节点的左子树寻找范围从pstart+1就可以了，中序的范围是 istart ---- k-1
    4.根节点的右子树范围从先序的 pstart + k-istart +1。pos代表在先序序列中右子树根节点的下标。
    中序序列中，从k+1到iend即可
    */
    TreeNode * fun(vector<int> &pre,int pstart,vector<int> &inorder,int istart,int iend)
    {
        if(istart>iend)
        {
            return NULL;
        }
        TreeNode *root=new TreeNode(pre[pstart]);
        int k=0;
        for(int i=istart;i<=iend;i++)
        {
            if(inorder[i]==root->val)
            {
                k=i;//在中序遍历中，下标k是 根节点，比如k=3，istart=0，3-0=3，代表左子树有3个元素
                break;//pstart  +  k-istart  +  1。 pstart代表根节点下标，k-istart代表左子树元素个数，+1表示右子树根节点下标
            }
        }
        root->left=fun(pre,pstart+1,inorder,istart,k-1);
        root->right=fun(pre,pstart+k-istart+1,inorder,k+1,iend);//pstart+k-istart+1在前序基础上 + 中序上的偏移绝对值
        return root;
    }
    vector<int> solve(vector<int>& xianxu, vector<int>& zhongxu) {
        // write code here
        int n = zhongxu.size();
        TreeNode* root = fun(xianxu, 0, zhongxu, 0, zhongxu.size()-1);
        vector<int> res;
        if(!root)
            return res;
        queue<TreeNode*> que;
        que.push(root);
        // 队列层次遍历右视图
        while(que.size())
        {
            int sz=que.size();
            for(int i=0;i<sz;i++)
            {
                TreeNode* node=que.front();
                que.pop();
                if(i==sz-1)
                {res.push_back(node->val);}
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
        }
        return res;
    }
};