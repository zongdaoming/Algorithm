知识点：二叉树，递归
难度：一星


# 题解
## 题目描述：给定一颗二叉树，判断此二叉树是否为对称二叉树。
----
![](./images/../../images/bitree.png)

根据上图可知：若满足对称二叉树，必须满足
```sh
1. L->val == R->val;
2. L->left->val = R->right->val;
3. L->right->val = R->left->val;
```
因此可以自顶向下，递归求解即可。

>1. 设置一个递归函数`isSame(r1, r2)`,表示如果对称，返回`true`，否则返回`false`
>2. 递归终止条件：`r1==nullptr` && `r2==nulllptr`, 直接返回`true`，否则，如果只有一个为`nullptr`，返回`false`
>3. 下一步递归：如果`r1->val == r2->val`, 则`isSame(root1->left, root2->right)` && `isSame(root1->right, root2->left)`;


```cpp
class Solution {
public:
    bool isSame(TreeNode* root1, TreeNode *root2)
    {
        if(!root1 && !root2) return true;
        if(!root1 || !root2) return false;
        return root1->val == root2->val && isSame(root1->left, root2->right) && isSame(root1->right, root2->left);
    }    
    bool isSymmetrical(TreeNode* pRoot) {   
        return isSame(pRoot,pRoot);
    }
};

```