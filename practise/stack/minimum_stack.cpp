#include <iostream>
#include <string>
#include <cstdio>
#include <numeric>
#include <vector>
#include <stack>
#include <cassert>
#include <unordered_map>
#include <algorithm>
using namespace std;


// 实现一个特殊的栈，在实现栈的基本功能的基础上，再实现返回栈中最小元素的操作。
// 本题关键的实现是用两个栈
class Stack
{
public:
	void Push(int data)
	{
		stackData.push(data);
		if (stackMin.empty())
		{
			stackMin.push(data);
		}
		else
		{
			if (data <= stackMin.top())
			{
				stackMin.push(data);
			}
		}
	}
    //  删除的操作也要有
	void Pop()
	{
		assert(!stackData.empty() && !stackMin.empty());
		if (stackData.top() == stackMin.top())
		{
			stackMin.pop();
		}
		stackData.pop();
	}
 
	int GetMin()
	{
		assert(!stackMin.empty());
		return stackMin.top();
	}
 
private:
	stack<int> stackData;
	stack<int> stackMin;
 
};


int main(int argc, char const *argv[])
{
    Stack s;
    s.Push(36);
    s.Push(15);
    s.Push(95);
    s.Push(100);
    s.Push(2);
    cout<<"The minimum value is "<<s.GetMin()<<endl;
    system("pause");
    return 0;
}

