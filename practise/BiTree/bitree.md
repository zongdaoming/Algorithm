# 结构体+指针存

根据每一个节点的特点，我们可以使用一个结构体来描述每个节点。

用结构体来表示就是
```cpp
struct LeaftNode{
    int data; //数据
    struct LeafNode *left; //左边叶子指针
    struct LeafNode *right; //右边叶子指针
}
```
由于`struct LeafNode`太长了，我们可以在`#include<...>`之后加一句
```cpp
typedef struct LeafNode Node;
```
# 遍历
有了一颗二叉树，那么怎么样才能把它读取出来呢？

## 通过递归
用类似DFS的思路，我们可以写出下面的方法:
```cpp
void preorderTraversal(Node *nd)
{
    if(nd==NULL) return;
    printf("%d",nd->data);
    preorderTraversal(nd->left);
    preorderTraversal(nd->right);
}
```
这种遍历方式就叫做`前序遍历`(`Preorder Traversal`)。

我们把printf的位置换一下：
```cpp
void inorderTraversal(Node *nd)
{
    if (nd == NULL) return;
    inorderTraversal(nd -> left);
    printf("%d ",nd -> data);
    inorderTraversal(nd -> right);
}
```

这样就成了中序遍历了(`Inorder Traversal`)。它是先遇到的节点不输出，然后第二次遇到它时再输出。

同样的，后序遍历(`Postorder Traversal`)就是这样的了：
```cpp
void postorderTraversal(Node *nd)
{
    if (nd == NULL) return;
    postorderTraversal(nd -> left);
    postorderTraversal(nd -> right);
    printf("%d ",nd -> data);
}
```

# 使用队列实现层次遍历
```cpp
void levelTravesal(Node *root)
{
    if(root == NULL) return; //如果root为空，直接return掉
    queue<Node*> childs; //创建节点队列
    childs.push(root); // 先把root节点加入套餐
    // childs.size()! = 0
    while(!childs.empty())
    {
        Node *current = childs.front(); //取出队列前端的节点
        printf("%d",current->data); //提取数据
        if(current->left!=NULL) childs.push(current->left); //如果不是空的，就加入套餐
        if(current->right!=NULL) childs.push(current->right); //同上
        childs.pop();//去掉队列前端的节点
    }
}
```
