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
    char* Serialize(TreeNode *root) {
        if(root==NULL)
        {
            char *serial = new char[3];
            strcpy(serial,"#,");
            return serial;
        }
        string str;
        Serialize(root, str);
        const char *c_str = str.c_str();
        char *serial = new char[str.length()+1];
        strcpy(serial, c_str);
        return serial;
    }
    TreeNode* Deserialize(char *str) {
        if(str==NULL || *str == '\0')
        {
            return 0;
        }
        int index=0;
        return Deserialize(str, index);
    
    }
private:
    void Serialize(TreeNode *root, string &str)
    {
        if(root==NULL)
        {
            str+="#,";
            return;
        }
        /* 先序遍历的方式，序列化二叉树 */
        str+= (to_string(root->val)+',');
        Serialize(root->left, str);
        Serialize(root->right,str);
    }
    TreeNode* Deserialize(char *str, int &index)
    {
        if(str[index]=='#')
        {
            index+=2;
            return NULL;
        }
        /* 获取到节点的数字权值 */
        int num = 0;
        while(str[index]!=',' && str[index]!='\0')
        {
            num = num*10 + (str[index]-'0');
            index ++;
        }
        index++;
        TreeNode *root = new TreeNode(num);
        root->left = Deserialize(str,index);
        root->right = Deserialize(str,index);
        return root;
    }
};



