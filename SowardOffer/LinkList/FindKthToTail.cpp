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

struct ListNode
{
    int val;
    struct ListNode* next;
    ListNode(int x): val(x), next(NULL){}
};


class Solution {
public:
    ListNode* FindKthToTail(ListNode* pHead, int k) {
        // 双指针，快慢指针
        ListNode* fast = pHead;
        ListNode* slow = pHead;
        for(int i = 0 ; i < k ; i++)
        {
            if(fast == NULL){return NULL;}
            fast = fast->next;
        }
        while(fast!=NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};


class SolutionNotAC {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param pHead ListNode类 
     * @param k int整型 
     * @return ListNode类
     */
    ListNode* FindKthToTail(ListNode* pHead, int k) {
        // write code here
        //反转列表+递归
        
        if (pHead == NULL)
        {
            return NULL;
        }
        
        ListNode *pNode = pHead;
        ListNode *pNext = NULL;
        ListNode *pPrev = NULL;
        
        while(pNode!=NULL)
        {
            pNext = pNode->next;
            //链表反转
            pNode->next = pPrev;
            //节点复制
            pPrev = pNode;
            pNode = pNext;
        }
        ListNode *newHead = pPrev;
        ListNode *newNode = newHead;
        int count = 1;
        
        while(newNode!=NULL)
        {
            if(k==count)
            {
                newNode->next = NULL;
                return newNode;
            }
            newNode = newNode->next;
            count++;
        }
        
        return NULL;
     
    }
};



