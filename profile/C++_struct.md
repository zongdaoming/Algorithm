#　C++中的结构体

在C语言中，结构体不能包含函数。
在面向对象的程序设计中，对象具有状态（属性）和行为，状态保存在成员变量中，行为通过成员方法（函数）来实现。

C语言中的结构体只能描述一个对象的状态，不能描述一个对象的行为。在C++中，考虑到C语言到C++语言过渡的连续性，对结构体进行了扩展，**C++的结构体可以包含函数**，这样，C++的结构体也具有类的功能，与class不同的是，结构体包含的函数默认为public，而class中默认是private。

结构体的定义与声明
```cpp
struct tag
{
    member-list;
}variable-list;

// 注：struct为结构体关键字；
//    tag为结构体的标志（类型）；
//    member-list为结构体成员变量及成员函数列表，其必须列出其所有成员；
//    variable-list为此结构体声明的变量；
```
实例代码2
```cpp
#include <iostream>
using namespace std;
struct SAMPLE
{
    int x;
    int y;
    int add(){
        return x+y;
    }
}s1;


int main()
{    
    cout<<"没初始化成员变量的情况下："<<s1.add()<<endl;
    s1.x = 3;
    s1.y = 4;
    cout<<"初始化成员变量的情况下："<<s1.add()<<endl;
    system("pause");
    return 0;  
}
// =>没初始化成员变量的情况下：0
//   初始化成员变量的情况下：7
```
C++中的结构体与类的区别： 

>* (1)class中默认的成员访问权限是private的，而struct中则是public的。

>* (2)class继承默认是private继承，而从struct继承默认是public继承。

结构体也可以继承结构体或者类。



# 1、用Typedef 定义类型

除了可以直接使用C提供的标准类型名（如int char float等）和自己声明的结构体等类型外，还可以用typedef声明新的类型名来代替已有的类型名。
如：
```cpp
typedef int INTEGER;
typedef float REAL;
```
如果一个程序中，一个整形变量用来计数，可以
```cpp
typedef int COUNT;
COUNT i,j;
```
2、可以声明结构体类型

```cpp
typedef struct
{
    int month;
    int day;
    int year;
}DATE;
```
声明新类型名DATE，它代表上面指定的一个结构体类型。这时，就可以用DATE定义变量：
```cpp
DATE birthday;
DATE *p;
```

3、还可以进一步：
1）
```cpp
typedef int NUM[100];
NUM n;
```
**声明NUM为整形数组类型，定义n为整形数组变量；**

2）
```cpp
typedef char * STRING;
STRING p,s[10];
```
**声明STRING为字符指针类型**
3）
```cpp
typedef int （* POINTER）( )
```
**声明POINTER为指向函数的指针类型，该函数返回整型值；**


> 1】注意#define是在预编译时处理的，它只能作简单的字符串替换，而typedef 是在编译时处理的。实际上它并不是作简单的字符串替换。

> 2】当不同源文件中用到同一类型数据时，常用typedef声明一些数据类型，把它们单独放在一个文件中，然后在需要用到它们的文件中用#include命令把它们包含进来。

> 3】使用typedef有利于程序的通用和移植。有时程序会依赖硬件特性，用typedef便于移植。例如，有的计算机系统int型数据用两个字节、数据范围为-32768~32767，而另外一些机器则以4个字节存放一个整数，数值范围为+-21亿。如果把一个C程序从一个以4个字节存放整数的计算机系统移植到以2个字节存放整数的系统，按一般方法需要将定义变量中的每个int改为long。例如，将“int a,b,c;”改为“long a,b,c;”,如果程序中有多处用int 定义变量，则要改动多处。现在用一个INTEGER 来声明int:
```cpp
typedef int INTEGER;
```
在程序中所有整型变量都用INTEGER定义。在移植时只需改动typedef定义体即可：
```cpp
typedef long INTEGER;
```

#　2、struct和typedef struct
在c++中定义一个结构体类型：
```cpp
struct Student  
{  
     int a;  
};　
```


于是就定义了结构体类型Student，声明变量时直接Student stu2

```cpp
typedef struct Student2  
{  
int a;  
}stu1;//stu1是一个结构体类型  
```

```cpp
struct Student  
{  
int a;  
}stu2;//stu2是一个变量  
```
**注意带typedef关键字，其就为【类型】，不带就为变量**


# 3、链表的声明

因为都有`typedef`关键字，所以后面声明的都是`类型`。其中`Node`与`LinkList`本质是一样的，只不过一个是`Node类型结构体`，一个是`指向Node的指针`。但是理解时`LinkList`应该是高层次的意义，即一个`链表`。
```cpp
// 方式1
typedef struct ListNode
{
    DataType data;
    struct ListNode *next;
}Node, *LinkList;

// 方式2
struct ListNode
{
    Datatype data;
    struct ListNode *next;
}
typedef struct ListNode Node;
typedef Node *LinkList;

// 方式3
typedef struct ListNode{
    DataType data;
    struct ListNode *next;
}Node;
typedef Node *LinkList;
```




