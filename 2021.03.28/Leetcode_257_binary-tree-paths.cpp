#include <iostream>
#include <string>
#include <cstdio>
#include <numeric>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 方法一：深度优先搜索
class Solution {
    public:
    void construct_paths(TreeNode * root, string path, vector<string> &paths)
    {
        if(root!=nullptr)
        {
            path += to_string(root->val);
            if(root->left == nullptr && root->right == nullptr)
            {
                // 当前节点是叶子节点
                paths.push_back(path);
            }
            else
            {
                path += '->'; //当前节点不是叶子节点，继续递归遍历
                construct_paths(root->left, path, paths);
                // interval: 需要先执行完上一个语句才执行下一个语句
                construct_paths(root->right, path, paths);
            }
        }
    }
    vector<string> binaryTreePaths(TreeNode* root)
    {
        vector<string> paths;
        construct_paths(root,"",paths);
        return paths;
    }
};

void printVec(vector<string> &paths)
{
    cout<<"[";
    for(int i = 0; i<paths.size(); i++)
    {
        cout<<" "<<paths[i]<<" ";
    }
    cout<<"]";
}










int main(int argc, char const *argv[])
{   
    Solution solution;
    TreeNode* root;
    root->val=1;
    root->left->val =2;
    root->right->val=3;
    root->left->right->val = 5;
    vector<string> paths = solution.binaryTreePaths(root);
    printVec(paths);
    return 0;
}
