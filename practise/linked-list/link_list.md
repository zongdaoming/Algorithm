# 题目描述
在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 例如，链表`1->2->3->3->4->4->5` 处理后为 `1->2->5`

示例1
输入

{1,2,3,3,4,4,5}

返回值

{1,2,5}


## 方法一：使用set，暴力解法
根据题意，显然如果能够知道重复的值是什么，然后再遍历一次单链表，删除重复值即可。
找重复值的具体步骤：

> 1. 初始化：set<int> st
> 2. 遍历单链表相邻两个元素，如果相等，就加入到set当中
> 3. 直到单链表遍历完</int>

删除重复值的具体步骤：
>  1. 初始化：pre指针指向重复值的前一个节点，cur指向当前遍历的节点值
>  2. 遍历单链表当前元素，然后再set中检查，如果是重复值，就删除，pre->next = cur->next
>  3. 否则，不是重复值，pre = pre->next, cur = cur->next
>  4. 直到单链表遍历完

```cpp
class Solution
{
    public:
    class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(!pHead) return pHead;
        set<int> st;
        ListNode *pre = pHead;
        ListNode *cur = pHead->next;
        while(cur!=nullptr)
        {
            if(pre->val == cur->val)
            {
                st.insert(pre->val);
            }
            pre = pre->next;
            cur = cur->next;
        }
        ListNode *vhead = new ListNode(-1);
        vhead->next = pHead;
        // 
        pre = vhead;
        // 
        cur = pHead；
        while(cur!=nullptr)
        {
            if(st.count(cur->val))
            {
                cur = cur->next;
                pre->next = cur;
            }
            else{
                pre = pre->next;
                cur = cur->next;
            }
        }
        return vhead->next;
    }
}
```


## 方法二：直接删除法
根据方法一，可以优化，在遍历单链表的时候，检查当前节点与下一点是否为相同值，如果相同，继续查找祥同值的最大长度，然后指针改变指向。
```cpp




```