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
    vector<bool> judgeIt(TreeNode* root) {
        bool flag1 = true, flag2 = true;
        queue<TreeNode*> Q;
        stack<TreeNode*> st;
        vector<int> ret;
        TreeNode* cur = root;
        
        while(!st.empty() && cur!=NULL) {
            if(cur!=NULL){
                st.push(cur);
                cur = cur->left;
            }
            else
            {
                cur = st.top();
                st.pop();
                ret.push_back(cur->val);            
                cur = cur->right;
            }
        }
        for(int i = 1; i<ret.size(); i++){
            if(ret[i-1]>=ret[i]){
                flag1 = false;
                break;
            }
        }
        
        bool flag = false;            
        Q.push(root);
        while(!Q.empty())
        {
            TreeNode* node = Q.front();
            Q.pop();
            if(node==NULL){
                flag = true;
                continue;
            }
            if(flag){
                flag2 = false;
                break;
            };
            Q.push(node->left);
            Q.push(node->right);            
        }
        return vector<bool>({flag1,flag2});
    }
};



class Solution {
     
public:
    /**
     *
     * @param root TreeNode类 the root
     * @return bool布尔型vector
     */
    vector<bool> judgeIt(TreeNode* root) {
        vector<bool> vet(2, true);
        vector<int> v;
        inorder(root, vet, v);
        if(!isCompleteTree(root)) vet[1] = false;
        return vet;
         
    }
    void inorder(TreeNode* root, vector<bool>& vet, vector<int> &v)
    {
        if(!root || !vet[0]) return;
        inorder(root->left, vet, v);
        if(!v.empty() && root->val < v.back()) vet[0] = false;
        v.push_back(root->val);
        inorder(root->right, vet, v);
    }
    bool isCompleteTree(TreeNode* root)
    {
        if(!root) return true;
        queue<TreeNode*> que;
        que.push(root);
        int flag = 0;
        while(!que.empty())
        {
            TreeNode* node = que.front();
            que.pop();
            if(node->left)
            {
                if(flag) return false;
                que.push(node->left);
            }
            else flag = 1;
            if(node->right)
            {
                if(flag) return false;
                que.push(node->right);
            }
            else flag = 1;
        }
        return true;
    }
};



class Solution {
    private:
    int last;
public:
    /**
     *
     * @param root TreeNode类 the root
     * @return bool布尔型vector
     */
    bool dfs(TreeNode* root)
    {
        if(root == nullptr)
            return true;
        bool l, r;
        l = dfs(root->left);
        if(last > root->val)
            return false;
        last = root->val;
        r = dfs(root->right);
        return l && r;
    }
    bool bfs(TreeNode* root)
    {
        if(root==nullptr)
            return true;
        int exist = false;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* tmp;
        while(!q.empty())
        {
            tmp = q.front();
            q.pop();
            if(tmp == nullptr)
            {
                exist = true;
                continue;
            }
            if(exist)
                return false;
            q.push(tmp->left);
            q.push(tmp->right);
        }
        return true;
    }
    vector<bool> judgeIt(TreeNode* root) {
        // write code here
        last = INT_MIN;
        vector<bool>res;
        res.push_back(dfs(root));
        res.push_back(bfs(root));
        return res;
    }
};