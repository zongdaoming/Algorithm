# 前序遍历迭代
### 算法1

* 1.根节点入栈
* 2.当栈非空时，栈顶出栈，把出栈的节点值添加到 list 结尾，然后依次再入栈其右子节点和左子节点

**因为前序遍历要左子节点在右子节点前面，所以先入栈右子节点，后入栈左子节点**.

```cpp
class Solution {
    public:
        vector<int>  threeOrders(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> res;
        
        st.push(root);
        while(!st.empty()) {
            TreeNode *node = st.top();
            st.pop();
            res.push_back(node->val);
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
```

算法2

1. 辅助变量 curr 初始化为根节点
2. 当 curr != null 时，就保存这个节点值到 list 中，然后将其入栈并置 curr 为它自己的左子节点
3. 当 curr == null 时，说明已经遍历到二叉树的左下节点了，这时前序遍历应该遍历右子树了，首先 pop 出已经遍历保存过的父节点，然后置 curr 为 pop 出的父节点的右子节点

```cpp
class Solution{
    public:
    vector<int> preOrderTranversal(TreeNode *root)
    {
       stack<TreeNode*> st;
       TreeNode curr = root;
       vector<int> ret;
       while(!st.empty() || curr!=NULL)
       {
           if(curr!=NULL)
           {
               ret.push_back(curr->val);
               st.push(curr);
               curr = curr->left;
           }
           else{
               curr = st.top();
               st.pop();
               curr = curr->right;
           }
       }
    }
}
```

算法3

和算法2的区别：

父节点遍历到之后直接保存下来不再入栈，**随后入栈其右子节点**，**这样出栈的时候也不必再置为其右子节点**。

```cpp
class Solution{
    public:
    vector<int> preOrderTranversal(TreeNode *root)
    {
        stack<TreeNode*> st;
        TreeNode *curr = root;
        vector<int> ret;
        while(!st.empty() || curr!=NULL)
        {
            if(curr!=NULL)
            {
                ret.push_back(curr->val);
                if(curr->right != NULL)
                {
                    st.push(curr->right);
                }
                curr = curr->left;
            }else
            {
                curr = st.top();
                st.pop();
            }
        }
    }
}
```

# 中序遍历迭代
中序遍历迭代

算法1

1. 辅助变量 curr 初始化 root
2. 当栈非空或 curr 非 null 时，循环
* 2.1 `curr != null` 时，说明还有左子节点存在，将 `curr` 入栈，并且将 `curr` 置为它自己的左子节点（和前序遍历的区别在于这里遍历到先不保存到 `list` 中，出栈的时候再将其保存到 `list` 中）

* 2.2 `curr == null` 时，说明到二叉树左下的节点了，这时栈顶的父节点出栈赋值给 `curr` ，并保存节点值到 `list` ，将 `curr` 置为栈顶节点的右子节点继续循环

```cpp
class Solution{
    public:
    vector<int> preOrderTranversal(TreeNode *root)
    {
        stack<TreeNode*> st;
        TreeNode *curr = root;
        vector<int> ret;
        while(!st.empty() || curr!=NULL){
            if(curr!=NULL)
            {
                st.push(curr);
                curr = curr->left;
            }
            else
            {
                curr = st.top();
                st.pop();
                ret.push_back(curr->val);
                curr = curr->right;
            }
        } 
    }
}
```



```cpp
class Solution{
    public:
    vector<int> preOrderTranversal(TreeNode *root)
    {
        stack<TreeNode*> st;
        TreeNode *curr = root;
        vector<int> ret;
        while(!st.empty() || curr!=NULL)
        {
            while(curr!=NULL)
            {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            ret.push_back(curr->val);
            curr = curr->right;
        }
    }
}
```

#　后序遍历迭代

* 三种算法分别对应前序遍历的反操作：
* * 前序遍历从尾部添加元素，后序遍历从头部添加元素
* * 前序遍历去左子树，后序遍历去右子树
  
```cpp
class Solution{
    public:
    vector<int> preOrderTranversal(TreeNode *root)
    {
        stack<TreeNode*> st;
        TreeNode *curr = root;
        vector<int> ret;
        st.push(root);
        while(!st.empty())
        {
            TreeNode *curr = st.top();
            st.pop();
            ret.push_back(curr->val);
            if(curr->left!=NULL)
            {
                st.push(curr->left);
            }
            if(cur->right!=NULL)
            {
                st.push(curr->right);
            }
        }
    }
};
```

```cpp
class Solution{
    public:
    vector<int> preOrderTranversal(TreeNode *root)
    {
        stack<TreeNode*> st;
        TreeNode *curr = root;
        vector<int> ret;
        while(!st.empty() || curr!=NULL)
        {
            if(curr!=NULL)
            {
                st.push(curr);
                ret.push_back(curr->val);
                curr = curr->right;
            }else
            {
                curr = st.top();
                st.pop();
                curr = curr->left;
            }
        }
    }
};
```

```cpp
class Solution{
    public:
    vector<int> preOrderTranversal(TreeNode *root)
    {
        stack<TreeNode*> st;
        TreeNode *curr = root;
        vector<int> ret;
        st.push(root);
        while(!st.empty() || curr != NULL)
        {
            if(curr!=NULL)
            {
                ret.push_back(curr->val);
                if(curr->left != NULL)
                {
                    st.push(curr->left);
                }
                curr = curr->right;
            }
            else
            {
                curr = st.top();
                st.pop();
            }
        }
};
```