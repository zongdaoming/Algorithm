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

