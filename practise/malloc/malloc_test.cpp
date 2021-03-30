#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <numeric>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;


// void *malloc(size_t size) 
// 分配所需的内存空间，并返回一个指向它的指针
// size -- 内存块的大小，以字节为单位。

int main()
{
    char *p;
    p = (char*) malloc(100);
    if (p)
    {
        printf("Memory Allocated at: %x \n",p);
    }
    else
    {
        printf("Not Enough Memory!");
    }
    free(p);
    system("pause");
    return 0;
}
