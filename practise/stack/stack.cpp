#include <iostream>
#include <string>
#include <cstdio>
#include <numeric>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
using namespace std;

template<class T>class Stack
{
private:
	struct Node
	{
		T data;
		Node *next;
	};
	Node *head;
	Node *p;
	int length;
 
public:
	Stack()
	{
		head = NULL;
		length = 0;
	}
	void push(T n)//入栈
	{
		Node *q = new Node;
		q->data = n;
		if (head == NULL)
		{
			q->next = head;
			head = q;
			p = q;
		}
		else
		{
			q->next = p;
			p = q;
		}
		length++;
	}
 
	T pop()//出栈并且将出栈的元素返回
	{
		if (length <= 0)
		{
			abort();
		}
		Node *q;
		T data;
		q = p;
		data = p->data;
		p = p->next;
		delete(q);
		length--;
		return data;
	}
	int size()//返回元素个数
	{
		return length;
	}
	T top()//返回栈顶元素
	{
		return p->data;
	}
	bool isEmpty()//判断栈是不是空的
	{
		if (length == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void clear()//清空栈中的所有元素
	{
		while (length > 0)
		{
			pop();
		}
	}
};

// 基于单链表的栈
void TestSingleLinkedStack()
{
    Stack<char> s;
    s.push('a');
    s.push('b');
    s.push('c');
    while(!s.isEmpty())
    {
        cout<<s.pop()<<endl;
    }
};

// 基于数组的栈
void TestStack()
{
    stack<int> myStack;
    int sum = 0;
    for (int i =0; i<10; i++)
    {
        myStack.push(i);
    }
    cout<<"size is "<<myStack.size()<<endl;
    while(!myStack.empty())
    {
        cout<<" "<<myStack.top()<<endl;
        myStack.pop();
    }
    cout <<endl;
};

int main(int argc, char const *argv[])
{
    TestStack();
    system("pause");
    return 0;
}
