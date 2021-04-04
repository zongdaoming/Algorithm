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

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};


class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        
        if(pHead==NULL)
        {
            return NULL;
        }
        ListNode *pNode = pHead;
        ListNode *nNode = NULL;
        ListNode *pNext = NULL;
        
        //头节点的处理 nNode 节点cope pNode节点
        nNode = pNode;
        // nNode 的尾节点
        nNode->next = NULL;
        //pNode  保存next指向，防止丢失, 为进入循环做好准备
        pNode = pNode->next;
        
        while(pNode!=NULL)
        {
            pNext = pNode->next; //保存next指向，防止丢失
            
            pNode->next = nNode; //pNode的指针域更新为nNode的一个节点
      
            nNode = pNode; // node直接更新 copy当前的 pNode(包括数据域和指针域)
            
            pNode = pNext; //更新pNode
        }
        return nNode;
    }
};



class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        
        ListNode *pNode = pHead;
        ListNode *pPre = NULL;
        ListNode *pNext = NULL;
        
        while(pNode!=NULL)
        {
            pNext = pNode->next;
            //指针指向反转反转
            pNode->next = pPre;
            //复制节点
            pPre = pNode;
            pNode = pNext;
        }
        return pPre;
    }
};