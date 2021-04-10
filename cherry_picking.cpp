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

/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param root TreeNode类 
     * @return int整型
     */
    int maxMoney(TreeNode* root) {
        if (root == NULL) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int ans =0;
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                TreeNode *node = q.front();
                q.pop();
                
                if(node->left) q.push(node->left); 
                if(node->right) q.push(node->right);
                
                if(node->right && !(node->right->left) && !(node->right->right))
                {
                    ans += 2;
                }
                else if(node->left && !(node->left->left) && !(node->left->right))
                {
                    ans += 2;
                }
                else if(node->left && node->right && !(node->left->left) && !(node->left->right) && !(node->right->left) && !(node->right->right))
                {
                    ans +=5;
                }                
            }
            
        }
        return ans;
       
    }
};