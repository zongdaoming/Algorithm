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
    ListNode(int x): val(x), next(nullptr){}

};

class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead) {
        if(pHead==nullptr) return pHead;
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
        // pre表示的是v家的指针
        pre = vhead;
        // cur表示的是p家的指针
        cur = pHead;
        while(cur)
        {
            if(st.count(cur->val))
            {
                cur=cur->next;
                pre->next = cur;
            }else{
                pre = pre->next;
                cur = cur->next;
            }
        }
        return  vhead->next;
    }
};


class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        ListNode *vhead = new ListNode(-1);
        vhead->next = pHead;
        ListNode *pre = vhead, *cur = pHead;       
        while (cur) {
            if (cur->next && cur->val == cur->next->val) {
                cur = cur->next;
                
                while (cur->next && cur->val == cur->next->val) {
                    cur = cur->next;
                }
                
                cur = cur->next;
                pre->next = cur;
            }
            else {
                pre = cur;
                cur = cur->next;
            }
        }
        return vhead->next;
    }
};