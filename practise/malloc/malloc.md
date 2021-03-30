# Malloc

* 功能：分配长度为num_bytes字节的内存块 
* 说明：如果分配成功则返回指向被分配内存的指针，否则返回空指针NULL。 
* 当内存不再使用时，应使用free()函数将内存块释放

从函数声明上可以看出, `malloc` 和 `new` 至少有两个不同: new 返回指定类型的指针，并且可以自动计算所需要大小。比如：
```cpp
int *p;
p = new int; //返回大小为int*类型（整数类型的指针）,分配的大小为sizeof(int)
// or
p = new int [100] ////返回类型为 int* 类型(整数型指针)，分配大小为 sizeof(int) * 100;
```
而 `malloc` 则必须由我们计算字节数，并且在返回后强行转换为实际类型的指针。
```cpp
int *p;
p = (int *)malloc(sizeof(int));
```
第一、`malloc` 函数返回的是 `void *` 类型，如果你写成：`p = malloc (sizeof(int))`; 则程序无法通过编译，报错：“不能将 void* 赋值给 int * 类型变量”。所以必须通过 (int *) 来将**强制转换**。



