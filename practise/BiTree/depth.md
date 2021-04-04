# 题解
------
## 题目抽象：给出一颗二叉树，求树的最大深度，也就是从根节点到所有叶子节点中的最大值。


## 分治法 和 递归法

分治法简介：求一个规模为n的问题，先求左边规模大约为n/2的问题，再求右边规模大约为n/2的问题，然后合并左边，右边的解，从而求得最终解。具体可参考归并排序。

步骤：

>1. 求 pro(left, rigth) -> int
>2. 先求 pro(left, (left+right)/2) -> lval
>3. 再求 pro((left+right)/2 + 1, right) -> rval
>4. merge(lval, rval) -> result

代码如下：
```cpp
class Solution
{
    public:
    int TreeDepth (TreeNode* pRoot)
    {
        if(!pRoot) return 0;
        int lval = TreeDepth(pRoot->left);
        int rval = TreeDepth(pRoot->right);
        return max(lval,rval) + 1;
    }
}
```


## 层次遍历
求最大深度，可用队列。因为要满足先进先出的特性。
>1. 初始化：一个队列`queue<TreeNode*> q`， 将root节点入队列q
>2. 如果队列不空，做如下操作：
>3. 弹出队列头，保存为node，将node的左右非空孩子加入队列
>4. 做2,3步骤，直到队列为空

### 如果不需要确定当前遍历到了哪一层，模板如下：

```cpp
void bfs(){
    vis[] = 0;
    queue<int> pq(start_val);
    while(!pq.empty())
    {
        int cur = pq.front();
        pq.pop();
        for (遍历cur所有的相邻节点nex){
            if(nex节点有效 && vis[nex]==0)
            {
                vis[nex]=1;
                pq.push(nex);
            }
        }
    }
}
```

### 如果需要确定遍历到哪一层，模板如下
```cpp
void bfs()
{
    int level = 0;
    vis[] = 0; //or set
    queue<int> pq(original_val);
    while(!pq.empty())
    {
        int sz = pq.size();
        while(sz--)
        {
            int cur = pq.front();
            pq.pop();
            for(遍历cur所有的相邻节点nex){
                if(nex节点有效 && vis[nex] == 0)
                {
                    vis[nex] = 1;
                    pq.push(nex);
                }
            } // end for
        } // end inner while
        level++;
    } // end outer while
}
```

