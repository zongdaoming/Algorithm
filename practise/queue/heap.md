#　堆排序基本原理及实现

## 一、堆的概念
我们一般提到堆排序里的堆指的是`二叉堆`（binary heap），是一种完全二叉树，二叉堆有两种：最大堆和最小堆，特点是父节点的值大于（小于）两个小节点的值。

##  二、基础知识
`完全二叉树`有一个性质是，除了最底层，每一层都是满的，这使得堆可以利用数组来表示，每个结点对应数组中的一个元素，如下图所示
![full_binary_tree](./images/../../images/fullbinarytree.jpg)

对于给定的某个结点的下标 i（**从1开始**），可以很容易的计算出这个结点的父结点、孩子结点的下标：

* `Parent(i) = floor(i/2)`，i 的父节点下标
* `Left(i) = 2i`，i 的左子节点下标
* `Right(i) = 2i + 1`，i 的右子节点下标

但是数组都是0基的，所以调整下标之后，对应关系如下图所示：
![](./imges/../../images/fullbinarytree2.jpg)

因此前面说到的关系也要随之调整：

* `Parent(i) = floor(i/2)`，i 的父节点下标
* `Left(i) = 2i`，i 的左子节点下标
* `Right(i) = 2i + 1`，i 的右子节点下标

## 三、堆的基本操作
1. 最大堆调整（Max-Heapify）

该操作主要用于维持堆的基本性质。假设数组`A`和下标`i`，假定以`Left(i)`和`Right(i)`为根结点的左右两棵子树都已经是最大堆，节点`i`的值可能小于其子节点。调整节点`i`的位置，使得**子节点永远小于父节点**，过程如下图所示：

由于一次调整后，堆仍然违反堆性质，所以需要递归的测试，使得整个堆都满足堆性质，用 C++可以表示如下：
```JavaScript 
/**
 * 从 index 开始检查并保持最大堆性质
 *
 * @array
 *
 * @index 检查的起始下标
 *
 * @heapSize 堆大小
 *
 **/
function maxHeapify(array, index, heapSize) {
  var iMax = index,
      iLeft = 2 * index + 1,
      iRight = 2 * (index + 1);
  if (iLeft < heapSize && array[index] < array[iLeft]) {
    iMax = iLeft;
  }
  if (iRight < heapSize && array[iMax] < array[iRight]) {
    iMax = iRight;
  }
  if (iMax != index) {
    swap(array, iMax, index);
    maxHeapify(array, iMax, heapSize); // 递归调整
  }
}
function swap(array, i, j) {
  var temp = array[i];
  array[i] = array[j];
  array[j] = temp;
}
```


2. 创建最大堆（Build-Max-Heap）


创建最大堆（`Build-Max-Heap`）的作用是将一个数组改造成一个最大堆，接受数组和堆大小两个参数，Build-Max-Heap 将自下而上的调用 Max-Heapify 来改造数组，建立最大堆。因为 `Max-Heapify` 能够保证下标 i 的结点之后结点都满足最大堆的性质，所以自下而上的调用 Max-Heapify 能够在改造过程中保持这一性质。如果最大堆的数量元素是`n`，那么 `Build-Max-Heap` 从 `Parent(n)` 开始，往上依次调用 `Max-Heapify`。流程如下：
![](./images/max-heap.png)

用 JavaScript实现：

```javascript
function buildMaxHeap(array, heapSize) {
  var i,
      iParent = Math.floor((heapSize - 1) / 2);
      
  for (i = iParent; i >= 0; i--) {
    maxHeapify(array, i, heapSize);
  }
}
```

## 四、时间复杂度与排序稳定性
我们知道`n`个元素的完全二叉树的深度`h=floor(logn)`，分析各个环节的时间复杂度如下。

1. 堆调整时间复杂度
从堆调整的代码可以看到是当前节点与其子节点比较两次，交换一次。父节点与哪一个子节点进行交换，就对该子节点递归进行此操作，设对调整的时间复杂度为`T(k)`（`k`为该层节点到叶节点的距离），那么有：

* `T(k)=T(k-1)+3, k∈[2,h]`
* `T(1)=3`
迭代法计算结果为：

* `T(h)=3h=3floor(log n`)
所以堆调整的时间复杂度是`O(log n)`。

2. 建堆的时间复杂度
   
`n`个节点的堆，树高度是`h=floor(log n)`。

对深度为于h-1层的节点，比较2次，交换1次，这一层最多有`2^(h-1)`个节点，总共操作次数最多为`3(12^(h-1))`；对深度为`h-2`层的节点，总共有`2^(h-2)`个，每个节点最多比较`4`次，交换`2`次，所以操作次数最多为`3(22^(h-2))`……
以此类推，从最后一个父节点到根结点进行堆调整的总共操作次数为：
```shell
s=3*[2^(h-1) + 2*2^(h-2) + 3*2^(h-3) + … + h*2^0]       a
2s=3*[2^h + 2*2^(h-1) + 3*2(h-2) + … + h*2^1]           b
b-a，得到一个等比数列，根据等比数列求和公式
s = 2s - s = 3*[2^h + 2^(h-1) + 2^(h-2) + … + 2 - h]=3*[2^(h+1)-  2 - h]≈3*n
```
所以建堆的时间复杂度是`O(n)`。

3. 堆排序时间复杂度
从上面的代码知道，堆排序的时间等于`建堆`和进行`堆调整`的时间之和，所以`堆排序`的时间复杂度是`O(nlog n + n) =O(nlog n)`。

4. 稳定性
堆排序是不稳定的算法，它不满足稳定算法的定义。它在交换数据的时候，是比较父结点和子节点之间的数据，所以，即便是存在两个数值相等的兄弟节点，它们的相对顺序在排序也可能发生变化。