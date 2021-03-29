#include <iostream>
#include <string>
#include <cstdio>
#include <numeric>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
using namespace std;

// 输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。
// 假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，
// 但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）


// 这题必须用 vector<int> mystack 代替 stack<int>，不然会发生队栈溢出

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> mystack;
        int ipush=0;
        for(int i=0;i<popV.size();i++){
            while(mystack.empty()||mystack.top()!=popV[i]){
                // 这里因为压栈数组和弹栈数组 仍然存在不相等的值，所以根据循环条件会再一次进入循环体
                // 会再一次进入循环体,导致index的值增加为 pushV.size() 实际上 index的值最大应该为 pushV.size()-1;
                if(ipush>=pushV.size())
                    return false;
                mystack.push(pushV[ipush++]);
            }
            if(mystack.top()==popV[i])
                mystack.pop();
        }
        return true;
    }
};


class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        
        if (pushV.empty() || popV.empty() || pushV.size()!= popV.size()) return false;
        
        vector<int> mystack;
        
        for(int i =0, j=0; i<pushV.size();)
        {
            mystack.push_back(pushV[i]);
            i++;
            while(j<popV.size() && mystack.back()== popV[j])
            {
                mystack.pop_back();
                j++;
            }
        }
        return mystack.empty();
    }
};
