#include <iostream>
#include <string>
#include <cstdio>
#include <numeric>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

// 讲两个值进行交换
void fun(int *a, int *b) //形参为两个整型的指针变量
{
   int temp = 0; //定义一个临时变量。良好的习惯是定义一个变量并初始化它；
   temp = *a; //将*a赋值给temp;
   *a = *b;   //将*b赋值给*a;
   *b = temp;  //再将temp赋值给*b;这样就完成了a、b数值的交换
};


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
    int a = 18, b = 29;
    
    fun(&x,&y);
    cout<< " x is "<<x <<" y is "<<y <<endl;
    //  x is 20 y is 10

    fun_reference(a,b);
    cout<< " a is "<<a<<" b is "<<b<<endl;
    system("pause");
    //  a is 29 b is 18
    
    return 0;
}



