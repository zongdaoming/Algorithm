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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode * root, string path, vector<string> &paths)
    {
        if(root!=nullptr)
        {
            path += to_string(root->val);
            if(root->left==nullptr && root->right == nullptr)
            {
                // 当前节点是叶子节点
                paths.push_back(path); 
            }
            else 
            {
                path += '->'; //当前节点不是叶子节点，继续遍历递归
                dfs(root->left, path, paths);
                dfs(root->right, path, paths);
            }
        }   
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        dfs(root, "", paths);
        return paths;

    }
};

// 方法2：广度优先搜索
class Solution{
    public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        if(root==nullptr)
        {
            return;
        }
        queue<TreeNode*> node_queue;
    
        queue<string> path_queue;
    
        node_queue.push(root);
        path_queue.push(to_string(root->val));
        while(!node_queue.empty())
        {
            TreeNode* node = node_queue.front();
            string path = path_queue.front();
            node_queue.pop();
            path_queue.pop();

            if(node->left==nullptr && node->right==nullptr)
            {
                paths.push_back(path);
            }
            else
            {
                if(node->left!=nullptr)
                {
                    node_queue.push(node->left);
                    path_queue.push(path+"->"+ to_string(node->left->val));
                }
                if(node->right!=nullptr)
                {
                    node_queue.push(node->right);
                    path_queue.push(path+"->"+to_string(node->right->val));
                }
            }
            
        }
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
