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
#include <string.h>
#include <stdio.h>
using namespace std;

struct TreeNode
{   
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};


class Solution {
public:
    string s;
    int j=0;
    void Srtial(TreeNode *root)
    {
        if(root==NULL)
        {
            s+="#!";
            return ;
        }
        s+=to_string(root->val);
        s+="!";
        Srtial(root->left);
        Srtial(root->right);
    }
    char* Serialize(TreeNode *root) {   
        Srtial(root);
        return (char *)s.data();
    }
    TreeNode* Deserialize(char *str) {
        s=str;
        return Deserial();
    }
    TreeNode* Deserial()
    {
        
        if(s.size()==0)
            return NULL;
        
        if(s[j]=='!') {
            j++;
            if(j>=s.size())
            {
                return NULL;
            }
        }
        
        if(s[j]=='#'){
            j++;
            return NULL;
        }   
        
        int num=0;
        
        while(s[j]>='0' && s[j]<='9'){
            num=num*10+s[j++]-'0';
        }

        TreeNode *root=new TreeNode(num);
        root->left=Deserial();
        root->right=Deserial();
        
        return root;
    }
};
