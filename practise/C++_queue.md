# C++ 清空队列(queue)的几种方法

C++中的`queue`自身是不支持`clear`操作的，但是双端队列`deque`是支持`clear`操作的。

```cpp
// 直接用空的队列对象赋值
queue<int> q1;
// process
// ...
q1 = queue<int>();

```

```cpp
// 遍历出队列
while(!Q.empty()) Q.pop();

```

```cpp
// 使用swap，这种是最高效的，定义clear，保持STL容器的标准。
void clear(queue<int>& q)
{
    queue<int> empty;
    swap(empty,q)
}
```