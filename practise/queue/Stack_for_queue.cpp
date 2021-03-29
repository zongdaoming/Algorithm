#include <iostream>
#include <string>
#include <cstdio>
#include <numeric>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

// 请你仅使用两个队列实现一个后入先出（LIFO）的栈，

class MyQueue{
    /**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
    public:
    stack<int> in_st;
    stack<int> out_st;
    // **Initialize your data structure here**/
    MyQueue(){
    }
    // **Push element x to the back of the queue.*/
    void push(int x)
    {
        in_st.push(x);
    }
    // **Remove the element from in front of queue and returns that element. */
    int pop()
    {
        int res = peek();
        if(!out_st.empty())
        {
            res=peek();
            out_st.pop();
            return res;
        }
        return res;        
    }

    // ** Get the front element */
    int peek()
    {
        if(out_st.empty())
        {
            while(!in_st.empty())
            {
                out_st.push(in_st.top());
                in_st.pop();
            }
        }
        if(!out_st.empty())
        {
            int res = out_st.top();
            return res;
        }
        return -1;
    }
    // ** Return whether the queue is empty. */

    bool empty()
    {
        if(in_st.empty() && out_st.empty())
        {
            return true;
        }
        return false;

    }
};


int main(int argc, char const *argv[])
{
    //  * Your MyQueue object will be instantiated and called as such:
    MyQueue* obj = new MyQueue();
    // MyQueue obj;
    bool flag = obj->empty();
    if (flag)
    {
        cout<<"Results is True"<<endl;
    }
    

    system("pause");
    return 0;
}
