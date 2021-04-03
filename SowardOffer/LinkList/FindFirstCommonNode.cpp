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

struct ListNode{
    int val;
    struct ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};

class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        ListNode *ta = pHead1, *tb = pHead2;
        while(ta!=tb)
        {
            ta= ta?ta->next:pHead2;
            tb= tb?tb->next:pHead1;
        }
        return ta;
    }
};


int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
