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
    ListNode(int x):val(x), next(NULL) {}
    };

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        
        vector<int> ans;    
        ListNode *pNode = head;     
        ListNode *pPre = NULL;
        ListNode *pNext = NULL;
        
        while(pNode!=NULL)
        {
            pNext = pNode->next;
            pNode->next = pPre;
            pPre = pNode;
            pNode = pNext;
        }
        ListNode *newNode = pPre;
        while(newNode!=NULL)
        {
            ans.push_back(newNode->val);
            newNode = newNode->next;
        }
        return ans;
    }
};