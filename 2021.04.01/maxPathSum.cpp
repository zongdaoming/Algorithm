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
};



// 求一棵二叉树的最大路径和，可以从二叉树的任意节点出发然后到二叉树的任意节点结束，
// 其实本质就是求以二叉树的某个节点为根节点出发，
// 求其本身与其左右子树构成的最大路径和，这种可能有：

// 1、其本身构成了最大值

// 2、其本身与其左右子树构成了最大值

// 3、其本身与其左子树或者右子树构成了最大值

// 所以我们采用后序遍历求解。

// 递归+动态规划

class Solution {
    private:
    int res = INT_MIN;
    int findPathSum(TreeNode* root)
    {
        // 递归边界 决定 leftsum的值
        if(root == nullptr)
        {
            return 0;
        }
        int sum = root->val;
        //我们采用后序遍历求解
        // 这里采用的是后序遍历求解
        int leftSum = findPathSum(root->left);
        int rightSum = findPathSum(root->right);
        // 这里是为了统计
        if(leftSum>0)
        {
            sum+= leftSum;
        }
        if(rightSum>0)
        {
            sum+= rightSum;
        }
        res = max(res,sum);
        // 这里确定的是只走一条路
        return max(root->val, max(rightSum,leftSum)+root->val);
    };
    public:
    int maxPathSum(TreeNode* root) {
        if(root==nullptr)
        {
            return 0;
        }
        if(root->left==nullptr && root->right==nullptr)
        {
            return root->val;
        } 
        findPathSum(root);
        return res;
    }
};


class Solution {
    //这道题目自己有两个误区：
    //1个是没有把握到这里的路径还是可以左+根+右这样的曲的路径。
    //2个是：在包含负数的处理过程中没有意识到如果是负数直接摒弃掉就可以了，因为最后反正都是抵消的因子
    //还有一定就是 我们用一个共享的变量记录了最大值，所以这个时候我们在递归的时候不需要关心如果不以子节点作为路径中一个元素时此时的最大值是什么，
    //因为如果是最大的，那么在遍历的过程值一定会记录到maxValue中的。
    int maxValue = INT_MIN;
    public:
     int help(TreeNode* root){
        if(root == NULL)return 0;
        int left = help(root->left);
        int right = help(root->right);
        maxValue = max(maxValue, max(0,left) + root->val +  max(0,right));
        return max(max(0,left) + root->val, max(0,right)+root->val);
    }
    public:
     int maxPathSum(TreeNode* root) {
 
        if(root == nullptr)return 0;
        //if(root.left == null && root.right == null)
        help(root);
        return maxValue;
    }
};

