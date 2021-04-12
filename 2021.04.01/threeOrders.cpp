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


class Solution {
public:
    /**
     * 
     * @param root TreeNode类 the root of binary tree
     * @return int整型vector<vector<>>
     */
    vector<vector<int> > threeOrders(TreeNode* root) {
        // write code herew
        stack<TreeNode*> st;
        vector<int> ret;
        st.push(root);
        while(!st.empty()) {
            TreeNode *node = st.top();
            st.pop();
            ret.push_back(node->val);
            if(node->right)
            {
                st.push(node->right);
            }
            if(node->left)
            {
                st.push(node->left);
            }
        }
    }
};


class Solution {
public:
    /**
     * 
     * @param root TreeNode类 the root of binary tree
     * @return int整型vector<vector<>>
     */
    vector<vector<int> > threeOrders(TreeNode* root) {
        // write code herew
        stack<TreeNode*> st;
        vector<int> ret;
        st.push(root);
        TreeNode * curr =root;
        // curr非空就可以了
        while(!st.empty() || curr!=NULL ) {
            if(curr != nullptr)
            {
                
            }



        }

    }
};






