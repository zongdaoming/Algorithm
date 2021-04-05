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
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
    public:
    bool judge(TreeNode* &root1, TreeNode* &root2)
    {
        //递归边界
        if (root2==NULL)
        {
            return true;
        }
        //递归边界
        if(root1==NULL && root2!=NULL)
        {
            return false;
        }
        
        if(root1->val == root2->val)
        {
            return judge(root1->left, root2->left) && judge(root1->right, root2->right);
        }
        else 
        {
            return false;
        }     
    }
    bool HasSubtree(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL || root2==NULL)
        {
            return false;
        }
        return judge(root1, root2) || HasSubtree(root1->left, root2) ||  HasSubtree(root1->right, root2);
    }
};