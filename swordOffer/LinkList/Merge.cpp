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
    struct ListNode *next;
    ListNode(int x): val(x),next(NULL){}
};

// struct ListNode {
// 	int val;
// 	struct ListNode *next;
// 	ListNode(int x) :
// 			val(x), next(NULL) {
// 	}
// };

class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        
        if(pHead1 == NULL)
        {
            return pHead2;
        }else if(pHead2 == NULL)
        {
            return pHead1;
        }
        ListNode *curNode1 = pHead1, *curNode2 = pHead2;
        ListNode *newHead = new ListNode(-1);
        ListNode *newNode  = newHead;
        
        while(curNode1!=NULL && curNode2!=NULL)
        {
            if(curNode1->val<curNode2->val)
            {
                newNode->next = curNode1;
                curNode1 = curNode1->next;
                newNode = newNode->next;
            }else{
                newNode->next = curNode2;
                curNode2 = curNode2->next;
                newNode = newNode->next;                
            }
        }
        // 处理较长链表的剩余部分
        if(curNode1!=NULL)
        {
            newNode->next = curNode1;
        }else
        {
            newNode->next = curNode2;
        }
        return newHead->next;
    }
};


class SolutionOurs {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        if(pHead1==NULL)
        {
            return pHead2;
        }else if(pHead2 == NULL)
        {
            return pHead1;
        }
        
        ListNode *curNode1= pHead1, *curNode2 = pHead2;
        //not required deep copy
        ListNode *newNode = NULL;
        
        // 生成头节点
        //这是一个技巧
        ListNode *newHead = new ListNode(-1);
        newNode =  newHead;
        
     
        while(curNode1 != NULL && curNode2 != NULL)
        {
            //compare which node is bigger
            if(curNode1->val>= curNode2->val )
            {
                newNode->next= curNode2;
                newNode = newNode->next;
                curNode2 = curNode2->next;
            }
            
            else if(curNode1->val < curNode2->val)
            {
                newNode->next = curNode1;  
                newNode = newNode->next;   
                curNode1 = curNode1->next;
            }
            
            while(curNode1==NULL && curNode2!=NULL)
            {
                newNode->next = curNode2;
                curNode2 = curNode2->next;                
                newNode = newNode->next;

            }
            while(curNode1!=NULL && curNode2==NULL)
            {
                newNode->next = curNode1;
                curNode1 = curNode1->next;
                newNode = newNode->next;
            }            
        }
        cout<<"HELLO"<<endl;
        return newHead->next;
    }
};

// #递归实现
// 其实思路一样，只是由于每次添加节点，都是机械性地重复工作，因此可以用递归来实现

