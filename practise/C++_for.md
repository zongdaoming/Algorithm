**遍历容器类的for如下:**

```cpp
int main()
{
    vector<int> vec{1,2,3,4,5,6,7,8};
    vector<int>::iterator it;   
    for (it = vec.begin(); it!=vec.end(); ++it)
    {
        cout<<*it;
    }
    getchar();
    return 0;
}
```
**C++ 11引入`auto`关键字之后,可以自动推导迭代器的类型** 所以上面可以简化为：

```cpp
for (auto it = vec.begin(); it!=vec.end(); ++it)
{
    cout<<*it;
}
// 输出：12345678
```
** C++11还引入了基于范围的`for`循环**，用基于范围的for循环来改写上面两个例子:
```cpp
vector<int> vec{1,2,3,4,5,6,7,8};
for(auto n:vec)
{
    cout<<n;
}
```
可以看到改写后的使用方法简单多了，代码的可读性提升了一个档次，但是需要注意的是`n`是对元素的`值拷贝`，所以修改`n`无法改变元素的值，如果需要**修改其中元素**，可以声明为`auto &`:
```cpp
vector<int> vec{1,2,3,4,5,6,7,8,9,10};
cout << "Before modification"<<endl;
for(auto &n:vec)
{
    cout<<++n;
}
cout<<endl;
cout<<"After modificaiton"<<endl;
for(auto j: vec)
{
    cout<<j;
}
// Output:
// Before modification
// 234567891011
// After modificaiton
// 234567891011
```

# 使用时需要注意的地方
## 注意auto自动推导的类型
**对容器的遍历**
** 在遍历容器的时候忙，auto 自动推导的类型是容器的`value_type`，而不是`迭代器`。而`map`中`value_type`是`std::pair`，也就是说`val`的类型是`std::pair`类型的，因此需要使用`val.first`，`val.second`来访问数据。
```cpp
#include <iostream>
using namespace std;
int main()
{
    map<string,int> map={
        {"a",1},
        {"b",2},
        {"c",3}
    };
    
    for (auto & val: map)
    {
        cout<<val.first<<"->"<<val.second<<endl;
    }
    system("pause");    
    return 0;
}
```
## 注意容器本生的约束
使用基于范围的for循环还需要注意一些容器本身的约束，比如`set`的容器的元素本身有容器的特性就决定了其元素是只读的，哪怕是使用了`引用类型`来遍历`set`元素，也是不能修改元素的。看下面的例子：
```cpp
set<int> ss = {1,2,3,4,5,6}
for(auto & n: ss)
   cout<<++n<<endl;
```

## 当冒号背后不是容器而是一个函数
```cpp
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
set<int> ss = {1, 2, 3, 4, 5, 6};  
const set<int> getSet(){
    cout<<"Getset"<<endl;
    return ss;
};
int main(int argc, char const *argv[])
{ 
    for(auto n:getSet())
    {
        cout<<n<<endl;
    }
    
    system("pause");
    return 0;
}
```
如果当冒号后面的表达式是一个函数调用时，函数仅会被调用一次，本质上是**将函数的返回值作为容器遍历**。

## 不要再for循环中修改容器
```cpp
#include <iostream>
#include <vector>
vector<int> vec ={1,2,3,4,5,6}
int main()
{   

    for(auto n: vec)
    {
      cout<<n<<endl;
      vec.push_bach(7);
    } 
    // Crashed Crashed Crashed
    system("pause");
    return 0;
}
```


