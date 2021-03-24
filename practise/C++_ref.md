# C++ 引用类型
说到引用，先来讲一个故事：我们生活的院子里有这样一个小盆友，他的名字叫罗XX，我们喜欢给他起一个外号，看着他营养不太好，脑袋比较大、身子比较小，于是我们就给他起了一个叫"萝卜头"的外号。那么罗XX就是他的真实姓名，萝卜头就是他的一个别名，那么什么是引用呢？？

**定义：`引用`：就是`变量`的一个`别名`。**


![注：作为别名来说，一个变量不能只有别名，而没有自己的真实姓名。](./images/reference.png)

## 基本数据类型的引用
如下面的一段代码

```cpp
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int a = 3; // 定义一个整型变量a
    int &b = a; //  b就是a的引用，即b是a的一个别名
    b = 10;
    cout <<a <<endl; 
    // 此时a 的值，已由原来的3变成了10.因为我们无论对别名做什么操作，
    // 其实都是对变量的本身做操作。
    // 就像我们去交萝卜头去干什么，罗XX本身就去干什么。
    system("pause");
    return 0; 
}
```
## 结构体类型的引用
如下面的一段代码:
```cpp
#include <iostream>
using namespace std;
typedef struct
{
    int x;
    int y;
}Coor;

int main(void)
{
    Coor c1; //定义一个结构体变量，叫c1
    Coor &c = c1; //给c1起了一个别名叫做c.
    c.x = 10;
    c.y = 20;
    cout << c1.x <<" "<< c1.y <<endl; //输出的结果为 10 20
    system("pause");
    return 0;
}   
```

## 指针类型的引用

指针类型的引用是引用当中最为复杂，最难理解的一部分，同时在写法形式上也有着与众不同的地方。

定义：
 **`类型 *&指针引用名 = 指针`;**

看个例子:
```cpp
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int a = 10; //定义一个整型变量a, a的值为10.
    int *p = &a; //定义一个指向a 变量的指针；
    int *& q = p; //定义一个指针的引用，即q为p的别名。定义方法：类型 *&指针引用名 = 指针；
    *q = 40;  // 把40赋给*q,相当于是把40赋值给*p，也就相当于把40赋值给a.
    cout << a << endl; // 输出a的值为40.
    system("pause");
    return 0;
}
```
## 引用作函数参数
在没有学习引用之前我们学习 C 语言时，学过这样的经典程序:
```cpp
// 讲两个值进行交换
void fun(int *a, int *b) // 形参为两个整型的指针变量
{
   int temp = 0; // 定义一个临时变量。良好的习惯是定义一个变量并初始化它；
   temp = *a; // 将*a赋值给temp;
   *a = *b;   // 将*b赋值给*a;
   *b = temp;  //再将temp赋值给*b;这样就完成了a、b数值的交换
};
```

```cpp
void fun_reference(int &a, int &b) //形参为两个整型的引用
{
    int temp = 0;
    temp =a;
    a = b;
    b = temp;
};

int main(int argc, char const *argv[])
{    
    int x = 10, y = 20;
    int x_ = 18, y_ = 29;
    
    fun(&x,&y); //在主函数中调用时，传过去的 实参 需要写成 取地址a，取地址b,比较麻烦，也不易理解。
    cout<< " x is "<<x <<" y is "<<y <<endl;
    //  x is 20 y is 10


    fun_reference(x_ ,y_ ); // 在主函数中调用时，实参 传过去后a是x_的别名，b是y_的别名。
    cout<< " a is "<<a<<" b is "<<b<<endl;
    system("pause");
    //  a is 29 b is 18
    
    return 0;
}
```


