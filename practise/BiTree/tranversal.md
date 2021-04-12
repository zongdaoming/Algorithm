# 前序遍历迭代
### 算法1

* 1.根节点入栈
* 2.当栈非空时，栈顶出栈，把出栈的节点值添加到 list 结尾，然后依次再入栈其右子节点和左子节点

**因为前序遍历要左子节点在右子节点前面，所以先入栈右子节点，后入栈左子节点**.

```cpp
class Solution {
    public:
    vector<vector<int> > threeOrders(TreeNode* root) {
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()) {
            TreeNode *node = st.top();
            st.pop();
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

